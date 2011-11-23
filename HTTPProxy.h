#pragma once

#include "resource.h"
#include "initsock.h"
#include <Windows.h>
#define SINGLE 
CInitSock _CInitSock;

typedef struct Client_{
	SAI saiClient;
	SOCKET sClient;
	SOCKET sServer;
	HANDLE hThread;
	HANDLE hEvents[2]; // 0 for sClient, 1 for sServer
	bool bValid;
	struct Client_ *pNext;
} CLIENT, *PCLIENT;
LPCRITICAL_SECTION g_pClientCs;
PCLIENT g_pClientLink;
HANDLE g_RecycleEvent;
ULONG g_BanList[1024];


void ServerMainThread(void* Unused);
	void ClientThread(void* pClient);
	void RecycleThread(void *Unused);
	void AddBanList();