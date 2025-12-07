#define WINUSERAPI __declspec(dllexport)
#include <windows.h>
#include "exports.h"

// #pragma comment(linker, "/export:SystemParametersInfoForDpi=kernelbase.SystemParametersInfoW")

// wtf x86 msvc
#ifndef _M_X64
#pragma comment(linker, "/export:GetDpiForWindow=_e_GetDpiForWindow")
__declspec(dllexport) UINT e_GetDpiForWindow(HWND hwnd) {
#else
__declspec(dllexport) UINT GetDpiForWindow(HWND hwnd) {
#endif
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:GetWindowDpiAwarenessContext=_e_GetWindowDpiAwarenessContext")
__declspec(dllexport) DPI_AWARENESS_CONTEXT e_GetWindowDpiAwarenessContext(HWND hwnd) {
#else
__declspec(dllexport) DPI_AWARENESS_CONTEXT GetWindowDpiAwarenessContext(HWND hwnd) {
#endif
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:SetThreadDpiAwarenessContext=_e_SetThreadDpiAwarenessContext")
__declspec(dllexport) DPI_AWARENESS_CONTEXT  e_SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext) {
#else
__declspec(dllexport) DPI_AWARENESS_CONTEXT  SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext) {
#endif
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:IsValidDpiAwarenessContext=_e_IsValidDpiAwarenessContext")
__declspec(dllexport) BOOL e_IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT value) {
#else
__declspec(dllexport) BOOL IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT value) {
#endif
    if(value == DPI_AWARENESS_UNAWARE) return TRUE;
    return FALSE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:GetThreadDpiAwarenessContext=_e_GetThreadDpiAwarenessContext")
__declspec(dllexport) DPI_AWARENESS_CONTEXT e_GetThreadDpiAwarenessContext() {
#else
__declspec(dllexport) DPI_AWARENESS_CONTEXT GetThreadDpiAwarenessContext() {
#endif
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:EnableNonClientDpiScaling=_e_EnableNonClientDpiScaling")
__declspec(dllexport) BOOL e_EnableNonClientDpiScaling(HWND hwnd) {
#else
__declspec(dllexport) BOOL EnableNonClientDpiScaling(HWND hwnd) {
#endif
    return TRUE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:AreDpiAwarenessContextsEqual=_e_AreDpiAwarenessContextsEqual")
__declspec(dllexport) BOOL e_AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT dpiContextA, DPI_AWARENESS_CONTEXT dpiContextB) {
#else
__declspec(dllexport) BOOL AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT dpiContextA, DPI_AWARENESS_CONTEXT dpiContextB) {
#endif
    if(dpiContextA == dpiContextB) return TRUE;
    return FALSE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:SystemParametersInfoForDpi=_e_SystemParametersInfoForDpi")
__declspec(dllexport) BOOL e_SystemParametersInfoForDpi(
#else
__declspec(dllexport) BOOL SystemParametersInfoForDpi(
#endif
  UINT  uiAction,
  UINT  uiParam,
  PVOID pvParam,
  UINT  fWinIni,
  UINT  dpi
) {
    return SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
}

#ifndef _M_X64
#pragma comment(linker, "/export:GetSystemMetricsForDpi=_e_GetSystemMetricsForDpi")
__declspec(dllexport) int e_GetSystemMetricsForDpi(
#else
__declspec(dllexport) int GetSystemMetricsForDpi(
#endif
  int  nIndex,
  UINT dpi
) {
    return GetSystemMetrics(nIndex);
}

#ifndef _M_X64
#pragma comment(linker, "/export:AdjustWindowRectExForDpi=_e_AdjustWindowRectExForDpi")
__declspec(dllexport) BOOL e_AdjustWindowRectExForDpi(
#else
__declspec(dllexport) BOOL AdjustWindowRectExForDpi(
#endif
   LPRECT lpRect,
   DWORD  dwStyle,
   BOOL   bMenu,
   DWORD  dwExStyle,
   UINT   dpi
) {
    return AdjustWindowRectEx(lpRect, dwStyle, bMenu, dwExStyle);
}

// required for vmware workstation 25H2
#ifndef _M_X64
#pragma comment(linker, "/export:SetDialogDpiChangeBehavior=_e_SetDialogDpiChangeBehavior")
#else
#pragma comment(linker, "/export:SetDialogDpiChangeBehavior=e_SetDialogDpiChangeBehavior")
#endif
__declspec(dllexport) BOOL e_SetDialogDpiChangeBehavior(
    HWND                        hDlg,
    DIALOG_DPI_CHANGE_BEHAVIORS mask,
    DIALOG_DPI_CHANGE_BEHAVIORS values
) {
    return TRUE;
}
// #pragma comment(linker, "/export:SetDialogDpiChangeBehavior=SetDialogDpiChangeBehavior_extend")


BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    return TRUE;
}