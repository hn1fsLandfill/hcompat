#define WINUSERAPI __declspec(dllexport)
#define WINBASEAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"

#ifndef _M_X64
#pragma comment(linker, "/export:QueryUnbiasedInterruptTimePrecise=_e_QueryUnbiasedInterruptTimePrecise")
#else
#pragma comment(linker, "/export:QueryUnbiasedInterruptTimePrecise=e_QueryUnbiasedInterruptTimePrecise")
#endif
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