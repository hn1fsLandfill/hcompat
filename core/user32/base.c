#include <windows.h>
#include <shared.h>
#include "exports.h"
#include "dpi.h"

#pragma export("IsWindowArranged")
BOOL e_IsWindowArranged(HWND hwnd) {
    return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    return TRUE;
}