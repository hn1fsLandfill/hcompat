#include <windows.h>
#include "exports.h"

// virtualmemory drama
#pragma comment(linker, "/export:DiscardVirtualMemory=kernelbase.DiscardVirtualMemory")
#pragma comment(linker, "/export:OfferVirtualMemory=kernelbase.OfferVirtualMemory")
#pragma comment(linker, "/export:ReclaimVirtualMemory=kernelbase.ReclaimVirtualMemory")

#ifndef _M_X64
#pragma comment(linker, "/export:SetThreadDescription=_e_SetThreadDescription")
#else
#pragma comment(linker, "/export:SetThreadDescription=e_SetThreadDescription")
#endif

HRESULT e_SetThreadDescription(
  HANDLE hThread,
  PCWSTR lpThreadDescription
) {
    return -1;
}

#ifndef _M_X64
#pragma comment(linker, "/export:IsWow64Process2=_e_IsWow64Process2")
#else
#pragma comment(linker, "/export:IsWow64Process2=e_IsWow64Process2")
#endif

BOOL e_IsWow64Process2(
  HANDLE hProcess,
  USHORT *pProcessMachine,
  USHORT *pNativeMachine
) {
    return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {

    }
    return TRUE;
}