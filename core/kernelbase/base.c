#include <windows.h>
#include <shared.h>
#include "exports.h"

// maybe find a better way to check?
#pragma export("CompareObjectHandles")
BOOL e_CompareObjectHandles(
  HANDLE hFirstObjectHandle,
  HANDLE hSecondObjectHandle
) {
  if(hFirstObjectHandle == hSecondObjectHandle) return TRUE;
  return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}