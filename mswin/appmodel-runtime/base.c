#include <windows.h>
#include <shared.h>
#include "exports.h"

enum apppolicy_termination_method {
  apppolicy_exitprocess,
  apppolicy_terminateprocess
};

#pragma export("AppPolicyGetProcessTerminationMethod")
LONG e_AppPolicyGetProcessTerminationMethod(HANDLE processToken, enum apppolicy_termination_method *policy) {
    *policy = apppolicy_exitprocess;
    return ERROR_SUCCESS;
}

#pragma export("AppPolicyGetThreadInitializationType")
LONG e_AppPolicyGetThreadInitializationType(HANDLE processToken, char *policy) {
    *policy = 0;
    return ERROR_SUCCESS;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}