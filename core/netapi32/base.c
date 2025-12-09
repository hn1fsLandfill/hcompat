#include <windows.h>
#include <shared.h>
#include "exports.h"

#pragma export("NetGetAadJoinInformation")
HRESULT e_NetGetAadJoinInformation(LPCWSTR pcszTenantId, void **ppJoinInfo) {
    *ppJoinInfo = NULL;
    return S_OK;
}

#pragma export("NetFreeAadJoinInformation")
VOID e_NetFreeAadJoinInformation(void *pJoinInfo) {
    // just a bland stub
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}