#include <windows.h>
#include <roapi.h>
#include <objbase.h>
#include <shared.h>
#include "exports.h"

// fuck com
// how in the fuck are factories and all of this bullshit more "simpler" or "better" than the old fashioned win32 apis

#pragma export_ord("RoGetActivationFactory", "307")
HRESULT e_RoGetActivationFactory(
 HSTRING activatableClassId,
 REFIID  iid,
 void    **factory
) {
    #if 0
    wchar_t *h;
    StringFromIID(iid, &h);
    MessageBoxW(NULL, h, L"iid request", 0);
    CoTaskMemFree(h);
    #endif
    if(IsEqualIID(&IID_IActivationFactory,iid)) {
        return E_NOINTERFACE;
    }
    return RoGetActivationFactory(activatableClassId, iid, factory);
}

#pragma export_ord("RoActivateInstance", "301")
HRESULT e_RoActivateInstance(
 HSTRING      activatableClassId,
 IInspectable **instance
) {
    MessageBoxA(NULL, "h", "h", 0);
    return RoActivateInstance(activatableClassId, instance);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
        
    }
    return TRUE;
}