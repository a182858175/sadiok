#include "stdafx.h"
#include <Windows.h>
#include "..\ActivationSDK.h"
#include <WinSock.h>

extern "C" __declspec(dllexport) bool ActivationHandlerQQ(int  EventId, int  ActivationErrorCode,int  WinsockErrorCode, char *ServerResponseString, char *pActivationKey);
int _tmain(int argc, _TCHAR* argv[])
{
	char server_response[1024];
	char activation_key[256];

	ActivationHandlerQQ(EVENT_SHOW_ACTIVATION, 0, 0, server_response, activation_key);
	MessageBoxA(NULL, activation_key, "º§ªÓKey", MB_OK);

	ActivationHandlerQQ(EVENT_CHECK_RESPONSE, RESPONSE_ERROR_KEY_NOT_FOUND, 0, server_response, activation_key);
	return 0;
}

