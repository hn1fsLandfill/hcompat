#define WINUSERAPI
#define WINBASEAPI
#include <windows.h>
#include "exports.h"

// todo: turn this into a macro?
#ifndef _M_X64
#pragma comment(linker, "/export:NetGetAadJoinInformation=_e_NetGetAadJoinInformation")
#else
#pragma comment(linker, "/export:NetGetAadJoinInformation=e_NetGetAadJoinInformation")
#endif

HRESULT e_NetGetAadJoinInformation(LPCWSTR pcszTenantId, void **ppJoinInfo) {
    *ppJoinInfo = NULL;
    return S_OK;
}

#ifndef _M_X64
#pragma comment(linker, "/export:NetFreeAadJoinInformation=_e_NetFreeAadJoinInformation")
#else
#pragma comment(linker, "/export:NetFreeAadJoinInformation=e_NetFreeAadJoinInformation")
#endif

VOID e_NetFreeAadJoinInformation(void *pJoinInfo) {
    // just a bland stub
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}