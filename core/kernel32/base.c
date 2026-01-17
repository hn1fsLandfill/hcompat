#include <windows.h>
#include <shared.h>
#include "exports.h"

// virtualmemory drama
#pragma comment(linker, "/export:DiscardVirtualMemory=kernelbase.DiscardVirtualMemory")
#pragma comment(linker, "/export:OfferVirtualMemory=kernelbase.OfferVirtualMemory")
#pragma comment(linker, "/export:ReclaimVirtualMemory=kernelbase.ReclaimVirtualMemory")

#pragma export("SetThreadDescription")
HRESULT e_SetThreadDescription(
  HANDLE hThread,
  PCWSTR lpThreadDescription
) {
    return -1;
}


#pragma export("IsWow64Process2")
BOOL e_IsWow64Process2(
  HANDLE hProcess,
  USHORT *pProcessMachine,
  USHORT *pNativeMachine
) {
    return FALSE;
}

#pragma export_ord("GetProcAddress", "677")
FARPROC e_GetProcAddress(
  HMODULE hModule,
  LPCSTR  lpProcName
) {
  FARPROC ret = GetProcAddress(hModule, lpProcName);

  if(ret == NULL) {
    DbgPrint("ATTEMPT TO OBTAIN FUNCTION %s FAILED!!!\r\n", lpProcName);
    DebugBreak();
  }

  return ret;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {

    }
    return TRUE;
}