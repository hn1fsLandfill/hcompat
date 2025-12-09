#include <windows.h>
#include <shared.h>
#include "exports.h"

#pragma export("UiaRaiseNotificationEvent")
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