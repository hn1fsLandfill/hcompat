#include <windows.h>
#include <shared.h>
#include "exports.h"

// virtualmemory drama
#pragma comment(linker, "/export:DiscardVirtualMemory=kernelbase.DiscardVirtualMemory")
#pragma comment(linker, "/export:OfferVirtualMemory=kernelbase.OfferVirtualMemory")
#pragma comment(linker, "/export:ReclaimVirtualMemory=kernelbase.ReclaimVirtualMemory")

#pragma comment(linker, "/export:FlsGetValue2=kernel32.FlsGetValue")

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

// deno seems to try to get these windows 11 api functions?
// works without them but just in case for chromium

#pragma export("GetTempPath2W")
DWORD e_GetTempPath2W(DWORD BufferLength, LPWSTR Buffer) {
  return GetTempPathW(BufferLength, Buffer);
}

#pragma export("GetTempPath2A")
DWORD e_GetTempPath2A(DWORD BufferLength, LPWSTR Buffer) {
  return GetTempPathA(BufferLength, Buffer);
}

#include "lib.h"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {

    }
    return TRUE;
}