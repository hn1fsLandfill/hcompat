#include <windows.h>
#include "exports.h"
#include "dpi.h"

#ifndef _M_X64
#pragma comment(linker, "/export:IsWindowArranged=_e_IsWindowArranged")
#else
#pragma comment(linker, "/export:IsWindowArranged=e_IsWindowArranged")
#endif

BOOL e_IsWindowArranged(HWND hwnd) {
    return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    return TRUE;
}