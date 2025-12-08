#define WINUSERAPI __declspec(dllexport)
#define WINBASEAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"

// return false for now; TODO
WINBASEAPI BOOL CompareObjectHandles(
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