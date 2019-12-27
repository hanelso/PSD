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
    hc_handle*  pahWorker;
};


#endif

