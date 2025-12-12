#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "verifier.h"
#include "pe.h"

typedef void (*MessageBoxA_t)(HWND, LPCSTR, LPCSTR, UINT);

static RTL_VERIFIER_DLL_DESCRIPTOR provider_hooks[] = {
    {NULL, 0, NULL, NULL},
};

void NTAPI loadCallback(PWSTR DllName, PVOID DllBase, SIZE_T DllSize, PVOID Reserved) {
    DbgPrint("loaded %ws\n\r", DllName);
}

static RTL_VERIFIER_PROVIDER_DESCRIPTOR provider = {
    .Length = sizeof(RTL_VERIFIER_PROVIDER_DESCRIPTOR),
    .ProviderDlls = provider_hooks,
    .ProviderDllLoadCallback = loadCallback,
    .ProviderDllUnloadCallback = NULL,
    .VerifierImage = NULL,
    .VerifierFlags = 0,
    .VerifierDebug = 0,
    .RtlpGetStackTraceAddress = NULL,
    .RtlpDebugPageHeapCreate = NULL,
    .ProviderNtdllHeapFreeCallback = NULL,
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, PRTL_VERIFIER_PROVIDER_DESCRIPTOR *lpReserved)
{
    if(reason == DLL_VERIFIER_LOAD) {
        DbgPrint("hpatcher verifier startup\r\n");
        patchCurrentProcess();
        *lpReserved = &provider;
    }
    if(reason == DLL_PROCESS_ATTACH) {
        // FIXME: maybe use the systemroot variable here and account for WOW64?
        DbgPrint("adding hcompats directory to dll search path\r\n");
        #ifndef _M_X64
        if(!SetDllDirectoryA("C:\\Windows\\hcompat")) {
        #else
        if(!SetDllDirectoryA("C:\\Windows\\hcompat-x64")) {
        #endif
            DWORD result = GetLastError();
            DbgPrint("oops - 0x%x 0x%x\r\n", result, HRESULT_FROM_WIN32(result));
        }
        // HMODULE user32 = LoadLibraryA("user32.dll");
        // MessageBoxA_t MessageBoxA_r = (MessageBoxA_t)GetProcAddress(user32, "MessageBoxA");
        // MessageBoxA_r(NULL, "hcompat has loaded into the process!!! :steamhappy:", "hcompat", 0);
        // FreeLibrary(user32);
    }
    return TRUE;
}