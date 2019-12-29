#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"../include/agent_main.h"


int main( int argc, char** argv )
{
    Agent_main();

    return 0;
}

EResult Agent_main()
{
    EResult result = NO_ERROR;
    hc_handle hAgentUnit = NULL;

    result = Agent_create( &hAgentUnit );
    ERRIFGOTO( result, _ERR_EXIT );


    while(1)
    {
        // receiveor가 메인 서버에서 수신을 기다린다.
        result = Agent_receiveSignal( hAgentUnit );
        ERRIFGOTO( result, _ERR_EXIT );

        // receiveor에서 parsing한 정보를 참조하여 함수들을 등록한다.
        result = Agent_setTargetFunc( hAgentUnit );
        ERRIFGOTO( result, _ERR_EXIT );

        // 함수를 수행한다.

    }

_ERR_EXIT:
    result = Agent_finalize( hAgentUnit );
    ERRIFGOTO( result, _EXIT );
_EXIT:
    return result;
}

EResult Agent_create( hc_handle* phAgentUnit )
{
    EResult result = NO_ERROR;
    struct SAgentUnit* pstAgentUnit = NULL;

    if( phAgentUnit == NULL )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_PARAM, _ERR_EXIT );
    }

    pstAgentUnit = ( struct SAgentUnit* )malloc( sizeof( struct SAgentUnit ) );
    if( pstAgentUnit == NULL )
    {
        ERRASSIGNGOTO( result, ERR_OUT_OF_MEMORY, _ERR_EXIT );
    }

    memset( pstAgentUnit, 0, sizeof( struct SAgentUnit ) );

    pstAgentUnit->handleID = HANDLE_ID_AGENT_UNIT;

    pstAgentUnit->hWorkerFactory = INVALID_HANDLE;
    pstAgentUnit->hReceptor = INVALID_HANDLE;

    *phAgentUnit = pstAgentUnit;
    pstAgentUnit = NULL;

_ERR_EXIT:
    SAFEFREE( pstAgentUnit );
_EXIT:
    return result;
}

EResult Agent_finalize( hc_handle hAgentUnit )
{
    EResult result = NO_ERROR;
    struct SAgentUnit* pstAgentUnit = NULL;

    if( CHECK_HANDLE( hAgentUnit, HANDLE_ID_AGENT_UNIT ) == FALSE )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_HANDLE_ID, _ERR_EXIT );
    }
    pstAgentUnit = ( struct SAgentUnit* )hAgentUnit;

    if( pstAgentUnit->hWorkerFactory != NULL )
    {
        result = WorkerFactory_finalize( pstAgentUnit->hWorkerFactory );
        ERRIFGOTO( result, _ERR_EXIT );
    }
    if( pstAgentUnit->hReceptor != NULL )
    {
        result = Receptor_finalize( pstAgentUnit->hReceptor );
        ERRIFGOTO( result, _ERR_EXIT );
    }

_ERR_EXIT:
    SAFEFREE( pstAgentUnit );
_EXIT:
    return result;
}

EResult Agent_receiveSignal( hc_handle hAgentUnit )
{
    EResult result = NO_ERROR;
    struct SAgentUnit* pstAgentUnit = NULL;

    if( CHECK_HANDLE( hAgentUnit, HANDLE_ID_AGENT_UNIT ) == FALSE )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_HANDLE_ID, _ERR_EXIT );
    }
    pstAgentUnit = ( struct SAgentUnit* )hAgentUnit;

    if( pstAgentUnit->hReceptor == INVALID_HANDLE )
    {
        result = Receptor_create( &pstAgentUnit->hReceptor );
        ERRIFGOTO( result, _ERR_EXIT );
    }

    result = Receptor_receiveSignal( pstAgentUnit->hReceptor );
    ERRIFGOTO( result, _ERR_EXIT );

_ERR_EXIT:
_EXIT:
    return result;
}

EResult Agent_setTargetWorker( hc_handle hAgentUnit )
{
    EResult result = NO_ERROR;
    struct SAgentUnit* pstAgentUnit = NULL;
    
    if( CHECK_HANDLE( hAgentUnit, HANDLE_ID_AGENT_UNIT ) == FALSE )
    {
        ERRASSIGNGOTO( result, ERR_INVALID_HANDLE_ID, _ERR_EXIT );
    }
    pstAgentUnit = ( struct SAgentUnit* )hAgentUnit;

    if( pstAgentUnit->hWorkerFactory == NULL )
    {
        result = WorkerFactory_create( &pstAgentUnit->hWorkerFactory );   
        ERRIFGOTO( result, _ERR_EXIT );
    }

    // factory를 채우는 로직

_ERR_EXIT:
_EXIT:
    return result;
}