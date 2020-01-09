# Software Requirement Specification of PSD(Please ShutDown)

- Version: 1.0
- Created: 2019.11.18


## 1. Introduction (개요)

- 

## 2. 액터

### 2.1 root
### 2.2 관리자
### 2.3 사용자


## 3. Requirements ( 기능 목록 정의 )

### 3.1 회원정보 관리
- 회원가입
- 회원정보 수정
- 회원탈퇴
	1. root
		- 관리자 및 사용자 탈퇴 가능
	2. 관리자
		- 사용자 탈퇴 가능
- 로그인
	로그인 이력 목록 확인
- 로그아웃
	로그아웃 이력 목록 확인
- 관리자 권한 부여
	Root만 사용 가능
	권한 종류( root, 관리자, 사용자 )

### 3.2 기기정보 관리
- 기기 목록 조회
	1. 사용자
	 	- 본인 기기 목록 조회
	2. 관리자
		- 본인 기기 목록 조회
		- 전체 기기 목록 조회
		- 특정 사용자 기기 목록 조회
- 기기정보 등록
- 기기정보 수정
	1. 사용자 및 관리자
		- 대표 기기 설정
- 기기정보 삭제
	1. 사용자
		- 본인 기기 정보 삭제
	2. 관리자
		- 본인 기기 정보 삭제
		- 전체 기기 정보 삭제
		- 특정 사용자 기기 정보 삭제
			다른 관리자의 기기 정보 삭제는 불가능.

### 3.3 PSD
- 시스템 종료


## 4. 멀티 플랫폼 지원

### 4.1 윈도우
### 4.2 리눅스
### 4.3 맥
### 4.4 안드로이드


## 5. Database Information ( DB 정보 )			
	
### 5.1 회원정보
No 	컬럼명							자료형			유일키		키
1.	회원 식별코드 		_id				ObjectId 		Y			PK
2. 	아이디			userId 			String			Y			
3.  비밀번호			password		String	
4. 	이름				nickname		String
5. 	권한 종류			permission		Number		
6. 	가입 날짜			joinDate		Date
7.	최근 수정 날짜		modifiedDate	Date				
         

### 5.2 기기정보
No	컬럼명							자료형			유일키		키
1.	기기 식별코드		_id				ObjevtId		Y			PK
2.	기기 이름			name			String			N		
3.	기기 OS 정보		os				String
4.	기기 IP 주소		ipAddress		String	
5.	기기 port 정보		port			String
6.	기기 로그인 정보	loginStatus		Boolean
7.	기기 사용자코드		userId			ObjectId
8.	기기 등록날짜		joinDate		Date
9.	최근 수정 날짜		modifiedDate	Date	
						
						
### 5.3 로그정보
No	컬럼명						유일키		키
1	로그 식별코드					Y			PK
2	기기 식별코드					N			
3	로그 종류					
4	로그 날짜					
						
