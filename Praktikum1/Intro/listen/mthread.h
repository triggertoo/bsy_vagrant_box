#ifndef MTHREAD_HEADER_FILE
#define MTHREAD_HEADER_FILE

//******************************************************************************
// File:    mthread.h
// Purpose: header file for thread handling thread control blocks (tcb)
// Author:  M. Thaler, 2012, (based on former work by J. Zeman and M. Thaler)
//******************************************************************************

#include "commondefs.h"

//******************************************************************************
// Thread control block

typedef struct mthread {
    unsigned      tID;              // thread-ID
    unsigned      readyTime;        // time, when thread is ready to run
} mthread_t;

//******************************************************************************
// function prototypes 

    mthread_t*    mtNewThread(unsigned id, tprio_t prio, unsigned readyTime);
    void          mtDelThread(mthread_t *tcb);

//******************************************************************************
// single variable access functions

    unsigned      mtGetID(mthread_t* tcb);
    void          mtSetReadyTime(mthread_t* tcb, unsigned rtime);
  
    unsigned      mtGetReadyTime(mthread_t* tcb);
    //#define       mtGetReadyTime(X) X->readyTime
    
//******************************************************************************

#endif // MTHREAD_HEADER_FILE
