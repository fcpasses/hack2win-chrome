// dllmain.cpp : Defines the entry point for the DLL application.

#include <Windows.h>
#include "payload.h"

extern "C"
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
		case DLL_PROCESS_ATTACH:
		case DLL_THREAD_ATTACH:
		case DLL_THREAD_DETACH:
		case DLL_PROCESS_DETACH:
			return TRUE;
		case 1337:
			payload((volatile context*)lpReserved);
			return TRUE;
    }
	// return FALSE from DLL_PROCESS_ATTACH to make LoadLibrary fail
}

