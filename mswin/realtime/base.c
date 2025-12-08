#define WINUSERAPI __declspec(dllexport)
#define WINBASEAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"

WINBASEAPI VOID QueryUnbiasedInterruptTimePrecise(
  PULONGLONG lpUnbiasedInterruptTimePrecise
) {
    QueryUnbiasedInterruptTime(lpUnbiasedInterruptTimePrecise);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}