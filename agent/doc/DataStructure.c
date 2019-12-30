// agent 모듈의 데이터 구조 설계에 대한 문서이다.


// 메인 서버로 부터 정보를 받아서 기능을 수행하도록 하는 구조를 갖는다.
// 주요기능 들에 대해 나열한다.

// 1. 메인 서버로 부터 요청을 기다린다.
// 2. 들어온 요청을 분석하여 수행해야할 기능들로 map을 형성한다.
// 3. maps을 확인하여 기능 unit들을 생성한다.
// 4. 기능을 수행한다.
// 5. 1번으로 돌아간다.

/*
    agent
        agent란 main_server에서 받은 명령을 각 device의 System에 맞게 실행하기 위한 프로그램

    agent_main
        agent_main은 agent의 main함수를 포함하며 agent프로그램이 시작이 된다.
        각 기능 모듈을 호출하는 기능

    agent_receptor 
        main_server로부터 정보를 받고, 받은 정보를 파싱하여 정보를 분석하는 모듈

    agent_workerFactory
        receptor에 의해 분석한 신호를 토대로 수행할때 필요한 기능들을 선택하는 모듈

        agent_worker
            각 기능 unit을 나타낸다.
*/


/*
    agent 의 기능은 크게 3개로 나눈다.
    1. 메인 서버로 부터 수신한다.
    2. 수신한 정보를 파싱하여 기능 함수들을 등록한다.
    3. 등록된 함수들을 호출한다.

struct SAgentUnit
{
    1. 구조체 핸들 ID
    2. 패킷를 파싱하기 위한 패킷파서 핸들
    3. 함수를 등록한 BitMap handle
};

struct SPacketParser
{
    1. 구조체 핸들 ID
    2. TODO... ( 패킷의 정보를 담는 것 )
}

struct SReceptor
{
    1. socket handle
    2. 패킷에서 넘어오는 데이터 // TODO...
}


*/