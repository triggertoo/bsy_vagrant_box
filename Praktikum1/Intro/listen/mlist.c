//******************************************************************************
// File:    mlist.c
// Purpose: implementation mlist (a single linked list with header dummy)
// Author:  M. Thaler, 2012, (based on former work by J. Zeman and M. Thaler)
//******************************************************************************

#include <stdlib.h>

#include "commondefs.h"
#include "mthread.h"
#include "mlist.h"

//******************************************************************************
// macros

#define mlNewTNode() (tnode_t *)malloc(sizeof(tnode_t))
#define mlDestroyTNode(node) free(node)
//******************************************************************************

mlist_t* mlNewList()
{
    mlist_t* myList = malloc(sizeof(mlist_t)); // Create list to the allocated space in the heap

    // Catch nullpointer
    handleMListNullPointer(myList);

    myList->head = mlNewTNode();
    handleTNodeNullPointer(myList->head);

    myList->head->tcb = NULL;
    myList->head->next = NULL;
    myList->iter = NULL;
    myList->numNodes = 0;

    myList->tail = myList->head; // As there is only one node: first = last
   
    return myList; 
}

void mlDelList(mlist_t* list)
{
    tnode_t* currentNode;
    tnode_t* nextNode = list->head;

    do {
        currentNode = nextNode;
        nextNode = currentNode->next;

        mlDestroyTNode(currentNode);
    } while(nextNode != NULL);

    free(list);    
}

void mlEnqueue(mlist_t* list, mthread_t* tcb) {
    tnode_t *node = mlNewTNode();
    handleTNodeNullPointer(node);
    node->tcb = tcb;
    node->next = NULL;
    
    list->tail->next = node;
    list->tail = node;
    
    list->numNodes++;
}

mthread_t* mlDequeue(mlist_t* list)
{
    if (list->numNodes == 0) return NULL;

    tnode_t *next = list->head->next;

    mlDestroyTNode(list->head);

    list->head = next;
    list->numNodes--; 

    mthread_t *thread = list->head->tcb;
    list->head->tcb = NULL;

    return thread;
}

void mlSortIn(mlist_t* list, mthread_t* tcb) {
    if (list->numNodes == 0) {
        mlEnqueue(list, tcb);
        return;
    }
    
    // Performance improvement - Only loop if readyTime of new thread is newer than readyTime of last element 
    if (list->tail->tcb->readyTime < tcb->readyTime) {
        mlEnqueue(list, tcb);
        return;
    }
    
    tnode_t *current = list->head->next;
    tnode_t *previous = list->head;

    while (current->next != NULL && current->tcb->readyTime < tcb->readyTime) {
        previous = current;
        current = current->next;
    }
    
    tnode_t *node = mlNewTNode();
    handleTNodeNullPointer(node);
    node->tcb = tcb;
    node->next = current;
    previous->next = node;
    list->numNodes++;
}

unsigned mlGetNumNodes(mlist_t* list)
{
    return list->numNodes;
}

void mlSetPtrFirst(mlist_t* list)
{
    list->iter = list->head->next; // Set the pointer to the first non-dummy-element
}

void mlSetPtrNext(mlist_t* list)
{
    if (list->iter == NULL) return;

    list->iter = list->iter->next;
}

mthread_t* mlReadFirst(mlist_t* list)
{
    if (list->numNodes == 0) return NULL;

    return list->head->next->tcb;
}

mthread_t* mlReadCurrent(mlist_t* list)
{
    if (list->iter == NULL) return NULL;

    return list->iter->tcb;
}

void handleMListNullPointer(mlist_t* list)
{
    if (list == NULL) exit(1);
}

void handleTNodeNullPointer(tnode_t* node)
{
    if (node == NULL) exit(1);
}

//******************************************************************************

