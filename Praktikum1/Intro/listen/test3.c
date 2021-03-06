//******************************************************************************
// File:    test1.c
// Purpose: unit test for single linked list
// Author:  M. Thaler, 2012
//******************************************************************************

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>

#include "commondefs.h"
#include "mlist.h"
#include "mthread.h"

//******************************************************************************
#define N (4 * 1024 * 1024)
//******************************************************************************
// prototypes of local functions

void beginTest(const char *str);
void endTest(void);
void shuffleIntArray(int *ar, int size);

//******************************************************************************

int main(void) {

    int        tid;
    int*       array = (int *)malloc(N * sizeof(int));
    mthread_t* th;
    mlist_t*   queue = mlNewList();

    // -------------------------------------------------------------------------
    // enqueue N threads

    beginTest("large queue");

    tid = 0;
    for (int i = 0; i < N; i++) {
        th = mtNewThread(tid++, HIGH, 10);
        mlEnqueue(queue, th);
    }
    assert(mlGetNumNodes(queue) == N);

    // dequeue N threads
    for (int i = 0; i < N; i++) {
        th = mlDequeue(queue);
        mtDelThread(th);
    }   
    assert(mlGetNumNodes(queue) == 0);

    // -------------------------------------------------------------------------
    // enqueue N threads sorted i increasing
    for (int i = 0; i < N; i++) {
        th = mtNewThread(tid++, HIGH, i);
        mlSortIn(queue, th);
    }
    assert(mlGetNumNodes(queue) == N);

    // dequeue N threads
    for (int i = 0; i < N; i++) {
        th = mlDequeue(queue);
        mtDelThread(th);
    }
    assert(mlGetNumNodes(queue) == 0);

    // -------------------------------------------------------------------------
    // enqueue N threads sorted i decreasing
    for (int i = 0; i < N; i++) {
        th = mtNewThread(tid++, HIGH, N-1-i);
        mlSortIn(queue, th);
    }
    assert(mlGetNumNodes(queue) == N);

    // dequeue N threads
    for (int i = 0; i < N; i++) {
        th = mlDequeue(queue);
        mtDelThread(th);
    }
    assert(mlGetNumNodes(queue) == 0);

    // -------------------------------------------------------------------------
    // enqueue N threads sorted all i shuffled

    int nN = N / 100;
    for (int i = 0; i < nN; i++)
        array[i] = i;
    shuffleIntArray(array, nN);

    for (int i = 0; i < nN; i++) {
        th = mtNewThread(tid++, HIGH, array[i]);
        mlSortIn(queue, th);
    }
    assert(mlGetNumNodes(queue) == nN);

    // dequeue N threads
    for (int i = 0; i < N; i++) {
        th = mlDequeue(queue);
        mtDelThread(th);
    }
    assert(mlGetNumNodes(queue) == 0);

    endTest();

    exit(0);

}

//******************************************************************************

void beginTest(const char *str) {
    printf("\n*************************************************************\n");
    if (str != NULL)
        printf("check: %s\n", str);
}


void endTest(void){
    printf("-> passed\n");
}

//******************************************************************************

void shuffleIntArray(int *ar, int size) {
    int j, k, tmp;
    double dran;
    srand((unsigned int)time(NULL));
    // shuffle according to Knuth to avoid sorted lists
    for (j = size-1; j >= 0; j--) {
        dran = (double)rand() / (double)(RAND_MAX);
        k = (int)(j*dran);
        tmp   = ar[j];
        ar[j] = ar[k];
        ar[k] = tmp;
    }
}

//******************************************************************************

