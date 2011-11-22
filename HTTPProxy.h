#pragma once

#include "resource.h"
#include "initsock.h"
CInitSock _CInitSock;

typedef struct Client_{
	SAI saiClient;
	SOCKET sClient;
	SOCKET sServer;
	HANDLE hThread;
	HANDLE hEvents[2]; // 0 for sClient, 1 for sServer
	bool bValid;
} CLIENT, *PCLIENT;
LPCRITICAL_SECTION g_pClientLink;
PCLIENT g_pClientLink;
HANDLE g_RecycleEvent;
int g_BanList[1024];


void ServerMainThread(void* Unused);
	void ClientThread(void* pClient);
	void RecycleThread(void *Unused);
	void AddBanList();