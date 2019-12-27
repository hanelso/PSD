#ifndef __AGENT_MAIN_H__
#define __AGENT_MAIN_H__

#include"hc_types.h"
#include"hc_error.h"
#include"hc_def.h"
#include"hc_handle.h"


struct SAgentUnit
{
    EHandle handleID;

    hc_handle   hReceptor;
    hc_handle   hWorkerFactory;
};

EResult Agent_create( hc_handle* phAgentUnit );
EResult Agent_finalize( hc_handle hAgentUnit );

#endif