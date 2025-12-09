#include <windows.h>
#include <shared.h>
#include "exports.h"

#pragma export("DCompositionCreateDevice3")
HRESULT e_DCompositionCreateDevice3(
	void	*RenderingDevice,
	REFIID	RefIID,
	void **DCompositionDevice)
{
    // stub
	*DCompositionDevice = NULL;
	return E_NOINTERFACE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}