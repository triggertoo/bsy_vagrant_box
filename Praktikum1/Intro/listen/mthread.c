//******************************************************************************
// File:    mthread.h
// Purpose: inplementation of thread handling
// Author:  M. Thaler, 2012, (based on former work by J. Zeman and M. Thaler)
//******************************************************************************

#include <stdlib.h>
#include <stdio.h>

#include "commondefs.h"
#include "mthread.h" 

//******************************************************************************
// Method:	mtNewThread
// Purpose:	set up data structure for new thread

mthread_t* mtNewThread(unsigned id, tprio_t prio, unsigned readyTime) {
    mthread_t* tcb = (mthread_t*)malloc(sizeof(mthread_t));
    tcb->tID       = id;
    tcb->readyTime = readyTime;
    return tcb;
}

//******************************************************************************
// clean up thread

void mtDelThread(mthread_t* tcb) {
    free(tcb);
}

//******************************************************************************

unsigned mtGetID(mthread_t* tcb) {
	return(tcb->tID);
}

//******************************************************************************

void mtSetReadyTime(mthread_t* tcb, unsigned rTime) {
	tcb->readyTime = rTime;
}
	
unsigned mtGetReadyTime(mthread_t* tcb) {
	return(tcb->readyTime);			            // get ready time (clock ticks)
}

//******************************************************************************

