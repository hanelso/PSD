#ifndef __AGENT_WORKERFACTORY_H__ 
#define __AGENT_WORKERFACTORY_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../include/hc_def.h"
#include"../include/hc_error.h"
#include"../include/hc_handle.h"
#include"../include/hc_types.h"

struct SWorkerFactory
{
    EHandle handleID;

    hc_uint     uWorkerCount;
    hc_handle*  pastWorker;
};

typedef EResult ( *FnCreateWorker ) ( hc_handle* phHandle );
typedef EResult ( *FnFinalizeWorker ) ( hc_handle hHandle );
typedef EResult ( *FnWorkWorker ) ( hc_handle hHandle );

struct SWorker
{
    EHandle handleID;

    FnCreateWorker fnCreate;
    FnFinalizeWorker fnFinalize;
    FnWorkWorker fnWork;
};


#endif

