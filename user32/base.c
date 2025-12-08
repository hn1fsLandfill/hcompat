#include <windows.h>
#include "exports.h"

// #pragma comment(linker, "/export:SystemParametersInfoForDpi=kernelbase.SystemParametersInfoW")

// wtf x86 msvc
#ifndef _M_X64
#pragma comment(linker, "/export:GetDpiForWindow=_e_GetDpiForWindow")
#else
#pragma comment(linker, "/export:GetDpiForWindow=e_GetDpiForWindow")
#endif

UINT e_GetDpiForWindow(HWND hwnd) {
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:GetWindowDpiAwarenessContext=_e_GetWindowDpiAwarenessContext")
#else
#pragma comment(linker, "/export:GetWindowDpiAwarenessContext=e_GetWindowDpiAwarenessContext")
#endif
DPI_AWARENESS_CONTEXT e_GetWindowDpiAwarenessContext(HWND hwnd) {
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:SetThreadDpiAwarenessContext=_e_SetThreadDpiAwarenessContext")
#else
#pragma comment(linker, "/export:SetThreadDpiAwarenessContext=e_SetThreadDpiAwarenessContext")
#endif

DPI_AWARENESS_CONTEXT e_SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext) {
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:IsValidDpiAwarenessContext=_e_IsValidDpiAwarenessContext")
#else
#pragma comment(linker, "/export:IsValidDpiAwarenessContext=e_IsValidDpiAwarenessContext")
#endif

BOOL e_IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT value) {
    if(value == DPI_AWARENESS_UNAWARE) return TRUE;
    return FALSE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:GetThreadDpiAwarenessContext=_e_GetThreadDpiAwarenessContext")
#else
#pragma comment(linker, "/export:GetThreadDpiAwarenessContext=e_GetThreadDpiAwarenessContext")
#endif

DPI_AWARENESS_CONTEXT e_GetThreadDpiAwarenessContext() {
    return DPI_AWARENESS_UNAWARE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:EnableNonClientDpiScaling=_e_EnableNonClientDpiScaling")
#else
#pragma comment(linker, "/export:EnableNonClientDpiScaling=e_EnableNonClientDpiScaling")
#endif

BOOL e_EnableNonClientDpiScaling(HWND hwnd) {
    return TRUE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:AreDpiAwarenessContextsEqual=_e_AreDpiAwarenessContextsEqual")
#else
#pragma comment(linker, "/export:AreDpiAwarenessContextsEqual=e_AreDpiAwarenessContextsEqual")
#endif

BOOL e_AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT dpiContextA, DPI_AWARENESS_CONTEXT dpiContextB) {
    // todo: find a more proper way?
    if(dpiContextA == dpiContextB) return TRUE;
    return FALSE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:SystemParametersInfoForDpi=_e_SystemParametersInfoForDpi")
#else
#pragma comment(linker, "/export:SystemParametersInfoForDpi=e_SystemParametersInfoForDpi")
#endif

BOOL e_SystemParametersInfoForDpi(
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
#else
#pragma comment(linker, "/export:GetSystemMetricsForDpi=e_GetSystemMetricsForDpi")
#endif

int e_GetSystemMetricsForDpi(
  int  nIndex,
  UINT dpi
) {
    return GetSystemMetrics(nIndex);
}

#ifndef _M_X64
#pragma comment(linker, "/export:AdjustWindowRectExForDpi=_e_AdjustWindowRectExForDpi")
#else
#pragma comment(linker, "/export:AdjustWindowRectExForDpi=e_AdjustWindowRectExForDpi")
#endif

BOOL e_AdjustWindowRectExForDpi(
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
BOOL e_SetDialogDpiChangeBehavior(
    HWND                        hDlg,
    DIALOG_DPI_CHANGE_BEHAVIORS mask,
    DIALOG_DPI_CHANGE_BEHAVIORS values
) {
    return TRUE;
}

#ifndef _M_X64
#pragma comment(linker, "/export:SetProcessDpiAwarenessContext=_e_SetProcessDpiAwarenessContext")
#else
#pragma comment(linker, "/export:SetProcessDpiAwarenessContext=e_SetProcessDpiAwarenessContext")
#endif

BOOL e_SetProcessDpiAwarenessContext(
  DPI_AWARENESS_CONTEXT value
) {
    SetLastError(ERROR_ACCESS_DENIED);
    return FALSE;
}


#ifndef _M_X64
#pragma comment(linker, "/export:IsWindowArranged=_e_IsWindowArranged")
#else
#pragma comment(linker, "/export:IsWindowArranged=e_IsWindowArranged")
#endif

BOOL e_IsWindowArranged(HWND hwnd) {
    return FALSE;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  reason, LPVOID lpReserved)
{
    return TRUE;
}