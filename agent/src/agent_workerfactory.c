#include "../include/agent_workerfactory.h"

EResult WorkerFactory_create( hc_handle* phWorkerFactory )
{
    EResult result = NO_ERROR;
    struct SWorkerFactory* pstWorkFact = NULL;

    if( phWorkerFactory == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }

    pstWorkFact = ( struct SWorkerFactory* )malloc( sizeof( struct SWorkerFactory ) );
    if( pstWorkFact == NULL )
    {
        ERRASSIGNGOTO( result, ERR_OUT_OF_MEMORY, _ERR_EXIT );
    }

    pstWorkFact->handleID = HANDLE_ID_WORKER_FACTORY;
    pstWorkFact->pastWorker = NULL;
    pstWorkFact->uWorkerCount = 0;

    *phWorkerFactory = pstWorkFact;
    pstWorkFact = NULL;

_ERR_EXIT:
    SAFEFREE( pstWorkFact );
_EXIT:
    return result;
}

EResult WorkerFactory_finalize( hc_handle hWorkerFactory )
{
    EResult result = NO_ERROR;
    struct SWorkerFactory* pstWorkFact = NULL;
    struct SWorker* pstWorker = NULL;
    hc_int  nIndex = 0;

    if( hWorkerFactory == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }
    pstWorkFact = ( struct SWorkerFactory* )hWorkerFactory;

    for( nIndex = 0; nIndex < pstWorkFact->uWorkerCount; nIndex++ )
    {
        pstWorker = ( struct SWorker* )&pstWorkFact->pastWorker[ nIndex ];

        pstWorker->fnFinalize()
    }
    

_ERR_EXIT:
_EXIT:
    return result;
}

