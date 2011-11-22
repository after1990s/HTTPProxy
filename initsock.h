#ifndef __INITSOCK_H
#define __INITSOCK_H
#include <WinSock2.h>
#pragma comment(lib,"WS2_32")
typedef struct sockaddr_in SAI;
typedef struct sockaddr SA;
class CInitSock{
public:
	CInitSock(BYTE minorVer=2, BYTE majorVer=2){
		WSADATA wsaData;
		WORD sockVersion = MAKEWORD(minorVer, majorVer);
		if(::WSAStartup(sockVersion, &wsaData)!=0){
			exit(0);
		}
	}
	~CInitSock(){
		::WSACleanup();
	}
};

#endif