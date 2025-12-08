#include <windows.h>
#include "exports.h"

#ifndef _M_X64
#pragma comment(linker, "/export:DCompositionCreateDevice3=_e_DCompositionCreateDevice3")
#else
#pragma comment(linker, "/export:DCompositionCreateDevice3=e_DCompositionCreateDevice3")
#endif

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