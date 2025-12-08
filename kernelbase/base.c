#include <windows.h>
#include "exports.h"

#ifndef _M_X64
#pragma comment(linker, "/export:CompareObjectHandles=_e_CompareObjectHandles")
#else
#pragma comment(linker, "/export:CompareObjectHandles=e_CompareObjectHandles")
#endif

// return false for now; TODO
BOOL e_CompareObjectHandles(
  HANDLE hFirstObjectHandle,
  HANDLE hSecondObjectHandle
) {
  return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}