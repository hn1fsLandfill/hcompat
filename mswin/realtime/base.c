#include <windows.h>
#include <shared.h>
#include "exports.h"

#pragma export("QueryUnbiasedInterruptTimePrecise")
VOID e_QueryUnbiasedInterruptTimePrecise(
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