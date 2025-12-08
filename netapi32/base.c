#define WINUSERAPI __declspec(dllexport)
#define WINBASEAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"

WINBASEAPI HRESULT NetGetAadJoinInformation(LPCWSTR pcszTenantId, void **ppJoinInfo) {
    *ppJoinInfo = NULL;
    return S_OK;
}

WINUSERAPI VOID NetFreeAadJoinInformation(void *pJoinInfo) {
    // just a bland stub
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}