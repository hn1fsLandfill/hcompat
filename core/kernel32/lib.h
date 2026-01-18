// fancy macros
#define REDIRECT_DLL(name, prefix) { \
    if(_stricmp(dllName, name) == 0) { \
        DbgPrint("LoadLibrary: %s detected, replacing first letter\r\n", lpLibFileName); \
        dllName[0] = prefix; \
    } \
}
#define REDIRECT_DLL_WIDE(name, prefix) { \
    if(_wcsicmp(dllName, name) == 0) { \
        DbgPrint("LoadLibrary: %ls detected, replacing first letter\r\n", lpLibFileName); \
        dllName[0] = prefix; \
    } \
}
#define REDIRECT_DLLHANDLE(name, redirect) { \
    if(_stricmp(lpModuleName, name) == 0) { \
        DbgPrint("GetModuleHandle: redirecting %s to %s\r\n", lpModuleName, redirect); \
        return GetModuleHandleExA(dwFlags, redirect, phModule); \
    } \
}
#define REDIRECT_DLLHANDLE_WIDE(name, redirect) { \
    if(_wcsicmp(lpModuleName, name) == 0) { \
        DbgPrint("GetModuleHandle: redirecting %ls to %ls\r\n", lpModuleName, redirect); \
        return GetModuleHandleExW(dwFlags, redirect, phModule); \
    } \
}

#pragma export_ord("LoadLibraryExW", "939")
HMODULE e_LoadLibraryExW(LPCWSTR lpLibFileName, HANDLE hFile, DWORD dwFlags) {
  WCHAR *dllName = wcsdup(lpLibFileName);
  REDIRECT_DLL_WIDE(L"kernelbase", 'h');
  REDIRECT_DLL_WIDE(L"kernel32", 'h');
  REDIRECT_DLL_WIDE(L"kernelbase.dll", 'h');
  REDIRECT_DLL_WIDE(L"kernel32.dll", 'h');

  DbgPrint("loading %ls\r\n", dllName);
  return LoadLibraryExW(dllName, hFile, 0);
}

#pragma export_ord("LoadLibraryExA", "938")
HMODULE e_LoadLibraryExA(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags) {
  CHAR *dllName = strdup(lpLibFileName);
  REDIRECT_DLL("kernelbase", 'h');
  REDIRECT_DLL("kernel32", 'h');
  REDIRECT_DLL("kernelbase.dll", 'h');
  REDIRECT_DLL("kernel32.dll", 'h');

  DbgPrint("loading %s\r\n", dllName);
  return LoadLibraryExA(dllName, hFile, 0);
}

#pragma export_ord("LoadLibraryW", "940")
HMODULE e_LoadLibraryW(LPCWSTR lpLibFileName) {
  return e_LoadLibraryExW(lpLibFileName, NULL, 0);
}

#pragma export_ord("LoadLibraryA", "937")
HMODULE e_LoadLibraryA(LPCSTR lpLibFileName) {
  return e_LoadLibraryExA(lpLibFileName, NULL, 0);
}

#pragma export_ord("GetModuleHandleExA", "620")
BOOL e_GetModuleHandleExA(DWORD dwFlags, LPCSTR lpModuleName, HMODULE *phModule) {
  if(dwFlags & GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS) {
    return GetModuleHandleExA(dwFlags, lpModuleName, phModule);
  }

  DbgPrint("%s\r\n", lpModuleName);
  REDIRECT_DLLHANDLE("kernel32", "hernel32");
  REDIRECT_DLLHANDLE("kernelbase", "hernelbase");
  REDIRECT_DLLHANDLE("kernel32.dll", "hernel32.dll");
  REDIRECT_DLLHANDLE("kernelbase.dll", "hernelbase.dll");

  return GetModuleHandleExA(dwFlags, lpModuleName, phModule);
}

#pragma export_ord("GetModuleHandleExW", "621")
BOOL e_GetModuleHandleExW(DWORD dwFlags, LPCWSTR lpModuleName, HMODULE *phModule) {
  if(dwFlags & GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS) {
    return GetModuleHandleExW(dwFlags, lpModuleName, phModule);
  }

  DbgPrint("%ls\r\n", lpModuleName);
  REDIRECT_DLLHANDLE_WIDE(L"kernel32", L"hernel32");
  REDIRECT_DLLHANDLE_WIDE(L"kernelbase", L"hernelbase");
  REDIRECT_DLLHANDLE_WIDE(L"kernel32.dll", L"hernel32.dll");
  REDIRECT_DLLHANDLE_WIDE(L"kernelbase.dll", L"hernelbase.dll");

  return GetModuleHandleExW(dwFlags, lpModuleName, phModule);
}

#pragma export_ord("GetModuleHandleA", "619")
HMODULE e_GetModuleHandleA(LPCSTR lpModuleName) {
  HMODULE out = NULL;
  e_GetModuleHandleExA(0, lpModuleName, &out);
  return out;
}

#pragma export_ord("GetModuleHandleW", "622")
HMODULE e_GetModuleHandleW(LPCWSTR lpModuleName) {
  HMODULE out = NULL;
  e_GetModuleHandleExW(0, lpModuleName, &out);
  return out;
}

#pragma export_ord("GetProcAddress", "677")
FARPROC e_GetProcAddress(
  HMODULE hModule,
  LPCSTR  lpProcName
) {
  FARPROC ret = GetProcAddress(hModule, lpProcName);

  if(ret == NULL) DbgPrint("ATTEMPT TO OBTAIN FUNCTION %s from %p FAILED!!!\r\n", lpProcName, hModule);

  return ret;
}