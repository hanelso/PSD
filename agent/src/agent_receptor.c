#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../include/agent_main.h"

struct SPacketData
{
    int TODO;
};

struct SSocket
{
    int nPort;
    unsigned long ulAddr;
    int nSocket;
};

struct SReceptor
{
    hc_handle hSocket;
    struct SPacketData stPacketData;
};

static EResult createSocket( hc_handle* phSock );
static EResult finalizeSocket( hc_handle hSock );

EResult Receptor_create( hc_handle* phReceptor )
{
    EResult result = NO_ERROR;
    struct SReceptor* pstReceptor = NULL;

    if( phReceptor == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }

    pstReceptor = ( struct SReceptor* )malloc( sizeof( struct SReceptor ) );
    if( pstReceptor == NULL )
    {
        ERRASSIGNGOTO( result, ERR_OUT_OF_MEMORY, _ERR_EXIT );
    }

    memset( pstReceptor, 0, sizeof( struct SReceptor ) );

    *phReceptor = pstReceptor;
    pstReceptor = NULL;   

_ERR_EXIT:
    SAFEFREE( pstReceptor );
_EXIT:
    return result;
}

EResult Receptor_finalize( hc_handle hReceptor )
{
    EResult result = NO_ERROR;
    struct SReceptor* pstReceptor = NULL;

    if( hReceptor == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }
    pstReceptor = ( struct SReceptor* )hReceptor;

    if( pstReceptor->hSocket != INVALID_HANDLE )
    {
        // TODO...
    }

_ERR_EXIT:
    SAFEFREE( pstReceptor );
_EXIT:
    return result;
}

EResult Receptor_receiveSignal( hc_handle hReceptor )
{
    EResult result = NO_ERROR;
    struct SReceptor* pstReceptor = NULL;

    if( hReceptor == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }
    pstReceptor = ( struct SReceptor* )hReceptor;

    // TODO... 
    // 소켓의 시작 등록

_ERR_EXIT:
_EXIT:
    return result;
}

static EResult createSocket( hc_handle* phSock )
{
    EResult result = NO_ERROR;
    struct SSocket* pstSock = NULL;

    if( phSock == INVALID_HANDLE )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }
    pstSock = ( struct SSocket* )malloc( sizeof( struct SSocket ) );
    if( pstSock == NULL )
    {
        ERRASSIGNGOTO( result, ERR_OUT_OF_MEMORY, _ERR_EXIT );
    }

    memset( pstSock, 0, sizeof( struct SSocket ) );

    *phSock = pstSock;
    pstSock = NULL;

_ERR_EXIT:
    SAFEFREE( pstSock );
_EXIT:
    return result;
}

static EResult finalizeSocket( hc_handle hSock )
{
    EResult result = NO_ERROR;
    struct SSocket* pstSock = NULL;

    if( hSock == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }
    pstSock = ( struct SSocket* )hSock;
    hSock = NULL;

    SAFEFREE( pstSock );

_ERR_EXIT:
_EXIT:
    return result;
}