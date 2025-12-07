#define WINUSERAPI __declspec(dllexport)
#define WINBASEAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"


// virtualmemory drama

#pragma comment(linker, "/export:DiscardVirtualMemory=kernelbase.DiscardVirtualMemory")
#pragma comment(linker, "/export:OfferVirtualMemory=kernelbase.OfferVirtualMemory")
#pragma comment(linker, "/export:ReclaimVirtualMemory=kernelbase.ReclaimVirtualMemory")


//#undef DiscardVirtualMemory
//
//typedef DWORD(*DiscardVirtualMemory_t)(PVOID, SIZE_T);
//DiscardVirtualMemory_t DiscardVirtualMemory_kbase;
//
//DWORD WINAPI DiscardVirtualMemory(
//  PVOID  VirtualAddress,
//  SIZE_T Size
//) {
//    return DiscardVirtualMemory_kbase(VirtualAddress, Size);
//}
#ifndef _M_X64
#pragma comment(linker, "/export:SetThreadDescription=_e_SetThreadDescription")
WINUSERAPI HRESULT e_SetThreadDescription(
#else
WINUSERAPI HRESULT SetThreadDescription(
#endif
  HANDLE hThread,
  PCWSTR lpThreadDescription
) {
    return -1;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
        // HMODULE kbase = LoadLibraryA("kernelbase.dll");
        // DiscardVirtualMemory_kbase = (DiscardVirtualMemory_t)GetProcAddress(kbase, "DiscardVirtualMemory");
    }
    return TRUE;
}