#ifndef __HC_ERROR_H__
#define __HC_ERROR_H__

typedef enum _ERESULT
{
    NO_ERROR                =   0,
    ERR_INVALID_PARAM       =   1,
    ERR_OUT_OF_MEMORY       =   2,
    ERR_INVALID_HANDLE_ID   =   3,

    MAX_ERROR_COUNT

} EResult;


#endif