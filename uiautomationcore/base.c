#include <windows.h>
#include "exports.h"

#ifndef _M_X64
#pragma comment(linker, "/export:UiaRaiseNotificationEvent=_e_UiaRaiseNotificationEvent")
#else
#pragma comment(linker, "/export:UiaRaiseNotificationEvent=e_UiaRaiseNotificationEvent")
#endif

HRESULT e_UiaRaiseNotificationEvent(
    void *provider,
    void *notificationKind,
    void *notificationProcessing,
    char *displayString,
    char *activityId
) {
    return E_NOTIMPL;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}