#ifndef __HC_HANDLE_H__
#define __HC_HANDLE_H__

#include"hc_types.h"

#define hc_handle       hc_pvoid
#define INVALID_HANDLE  NULL

typedef enum _HC_HANDLE
{
    HANDLE_ID_AGENT_UNIT        =   256,
    HANDLE_ID_AGENT_RECEPTOR    =   257,
    HANDLE_ID_WORKER_FACTORY    =   258,
} EHandle;

#define CHECK_HANDLE( handle, ID )  ( ( handle == ID ) ? (TRUE) : (FALSE) )

#endif