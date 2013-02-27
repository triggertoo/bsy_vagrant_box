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
// macro to allocate new tnode_t

#define mlNewTNode() (tnode_t *)malloc(sizeof(tnode_t))

//******************************************************************************

mlist_t* mlNewList()
{
    mlist_t* dummyNode = malloc(sizeof(mlist_t)); // Copy dummyNode to the allocated space in the heap

    dummyNode->head = mlNewTNode();
    dummyNode->head->tcb = NULL;
    dummyNode->head->next = NULL;
    dummyNode->iter = NULL;
    dummyNode->numNodes = 0;

    dummyNode->tail = dummyNode->head; // As there is only one node: first = last
   
    return dummyNode; 
}

void mlDelList(mlist_t* list)
{

}

void mlEnqueue(mlist_t* list, mthread_t* tcb)
{
    tnode_t* node = mlNewTNode(); // Includes memory allocation, see top of file!
    node->next = NULL;

    list->tail->next = node;
    list->tail = node;
}

mthread_t* mlDequeue(mlist_t* list, mthread_t* tcb)
{

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
    if (list->next == NULL) return;

    list->iter = list->iter->next;
}

mthread_t* mlReadCurrent(mlist_t* list)
{
    if (list->iter == NULL) return NULL;

    return list->iter->tcb;
}

//******************************************************************************

