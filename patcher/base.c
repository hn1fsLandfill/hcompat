#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "verifier.h"
#include "ldr.h"
#include "pe.h"

// enable for now
//#define useAVCallback

typedef void (*MessageBoxA_t)(HWND, LPCSTR, LPCSTR, UINT);
typedef void (*ShellMessageBoxA_t)(HINSTANCE, HWND, LPCSTR, LPCSTR, UINT, ...);

static RTL_VERIFIER_DLL_DESCRIPTOR provider_hooks[] = {
    {NULL, 0, NULL, NULL},
};

static RTL_VERIFIER_PROVIDER_DESCRIPTOR provider = {
    .Length = sizeof(RTL_VERIFIER_PROVIDER_DESCRIPTOR),
    .ProviderDlls = provider_hooks,
    #ifdef useAVCallback
    .ProviderDllLoadCallback = loadCallbackAV,
    #else
    .ProviderDllLoadCallback = NULL,
    #endif
    .ProviderDllUnloadCallback = NULL,
    .VerifierImage = NULL,
    .VerifierFlags = 0,
    .VerifierDebug = 0,
    .RtlpGetStackTraceAddress = NULL,
    .RtlpDebugPageHeapCreate = NULL,
    .ProviderNtdllHeapFreeCallback = NULL,
};

#ifndef useAVCallback
void hookLoadCallback() {
    DbgPrint("hpatcher: registering dll load hook\r\n");
    HMODULE ntdll = LoadLibraryA("ntdll.dll");
    LdrRegisterDllNotification_t LdrRegisterDllNotification =
        (LdrRegisterDllNotification_t)GetProcAddress(ntdll, "LdrRegisterDllNotification");
    LdrUnregisterDllNotification_t LdrUnregisterDllNotification =
        (LdrUnregisterDllNotification_t)GetProcAddress(ntdll, "LdrUnregisterDllNotification");
    DBG_LDRP_DLL_NOTIFICATION_BLOCK *loadCookie;
    DWORD ret = LdrRegisterDllNotification(0, loadNotificationCallback, NULL, &loadCookie);
    if(ret) {
        DbgPrint("hpatcher failed to register dll notification :( %x\r\n",ret);
        DebugBreak();
    }
}
#endif

#define HCOMPAT_WOW64_ERROR_MSG "hcompat does not support WOW64 processes currently.\n\n" \
    "Your program may or may not work unless you manually patch it to use hcompat."

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, PRTL_VERIFIER_PROVIDER_DESCRIPTOR *lpReserved)
{
    if(reason == DLL_VERIFIER_LOAD) {
        DbgPrint("hpatcher verifier startup\r\n");
        patchCurrentProcess();
        #ifdef useAVCallback
        DbgPrint("Using AV callback for dll load callbacks\r\n");
        #else
        hookLoadCallback();
        #endif
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
        BOOL IsWOW = FALSE;

        IsWow64Process(GetCurrentProcess(),&IsWOW);
        
        if(IsWOW) {
            HMODULE shlwapi = LoadLibraryA("shlwapi.dll");
            ShellMessageBoxA_t ShellMessageBoxA = (ShellMessageBoxA_t)GetProcAddress(shlwapi, "ShellMessageBoxA");
            ShellMessageBoxA(NULL, NULL, HCOMPAT_WOW64_ERROR_MSG, "hcompat", MB_ICONERROR);
            FreeLibrary(shlwapi);
        }
    }
    return TRUE;
}