#include <windows.h>
#include <shared.h>
#include "exports.h"

#pragma comment(linker, "/export:FlsGetValue2=kernelbase.FlsGetValue")

// maybe find a better way to check?
#pragma export("CompareObjectHandles")
BOOL e_CompareObjectHandles(
  HANDLE hFirstObjectHandle,
  HANDLE hSecondObjectHandle
) {
  if(hFirstObjectHandle == hSecondObjectHandle) return TRUE;
  return FALSE;
}

// doesn't work for now
// #pragma export("VirtualAlloc2")
PVOID e_VirtualAlloc2(HANDLE Process, PVOID BaseAddress, SIZE_T Size, ULONG AllocationType, ULONG PageProtection, void *ExtendedParameters, ULONG ParameterCount) {
  PVOID ret = VirtualAllocEx(Process, BaseAddress, Size, 0, PageProtection);
  
  if(ret == NULL) {
    DWORD error = GetLastError();
    DbgPrint("virtualallocex failed with 0x%x\r\n", error);
    SetLastError(error);
  }

  return ret;
}

#pragma export("MapViewOfFile3")
PVOID e_MapViewOfFile3(
  HANDLE FileMapping,
  HANDLE Process,
  PVOID BaseAddress,
  ULONG64 Offset,
  SIZE_T ViewSize,
  ULONG AllocationType,
  ULONG PageProtection,
  MEM_EXTENDED_PARAMETER *ExtendedParameters,
  ULONG ParameterCount
) {
  DWORD low = Offset >> 32;
  DWORD high = Offset & 0xffffffff;

  DbgPrint("0x%lx | 0x%x 0x%x\r\n", Offset, low, high);

  DWORD desiredAccess = 0;

  if(PageProtection & PAGE_READONLY) desiredAccess |= FILE_MAP_READ;
  if(PageProtection & PAGE_READWRITE) desiredAccess |= FILE_MAP_READ | FILE_MAP_WRITE;

  DebugBreak();

  return MapViewOfFileEx(FileMapping, desiredAccess, low, high, ViewSize, BaseAddress);
}

#pragma export("UnmapViewOfFile2")
BOOL e_UnmapViewOfFile2(HANDLE Process, PVOID BaseAddress, ULONG UnmapFlags) {
  return UnmapViewOfFileEx(BaseAddress, UnmapFlags);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    if (reason == DLL_PROCESS_ATTACH) {
    
    }
    return TRUE;
}