#pragma export("GetDpiForWindow")
UINT e_GetDpiForWindow(HWND hwnd) {
    return DPI_AWARENESS_UNAWARE;
}

#pragma export("GetWindowDpiAwarenessContext")
DPI_AWARENESS_CONTEXT e_GetWindowDpiAwarenessContext(HWND hwnd) {
    return DPI_AWARENESS_UNAWARE;
}

#pragma export("SetThreadDpiAwarenessContext")
DPI_AWARENESS_CONTEXT e_SetThreadDpiAwarenessContext(DPI_AWARENESS_CONTEXT dpiContext) {
    return DPI_AWARENESS_UNAWARE;
}

#pragma export("IsValidDpiAwarenessContext")
BOOL e_IsValidDpiAwarenessContext(DPI_AWARENESS_CONTEXT value) {
    if(value == DPI_AWARENESS_UNAWARE) return TRUE;
    return FALSE;
}

#pragma export("GetThreadDpiAwarenessContext")
DPI_AWARENESS_CONTEXT e_GetThreadDpiAwarenessContext() {
    return DPI_AWARENESS_UNAWARE;
}

#pragma export("EnableNonClientDpiScaling")
BOOL e_EnableNonClientDpiScaling(HWND hwnd) {
    return TRUE;
}

#pragma export("AreDpiAwarenessContextsEqual")
BOOL e_AreDpiAwarenessContextsEqual(DPI_AWARENESS_CONTEXT dpiContextA, DPI_AWARENESS_CONTEXT dpiContextB) {
    // todo: find a more proper way?
    if(dpiContextA == dpiContextB) return TRUE;
    return FALSE;
}

#pragma export("SystemParametersInfoForDpi")
BOOL e_SystemParametersInfoForDpi(
  UINT  uiAction,
  UINT  uiParam,
  PVOID pvParam,
  UINT  fWinIni,
  UINT  dpi
) {
    return SystemParametersInfoW(uiAction, uiParam, pvParam, fWinIni);
}

#pragma export("GetSystemMetricsForDpi")
int e_GetSystemMetricsForDpi(
  int  nIndex,
  UINT dpi
) {
    return GetSystemMetrics(nIndex);
}

#pragma export("AdjustWindowRectExForDpi")
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
#pragma export("SetDialogDpiChangeBehavior")
BOOL e_SetDialogDpiChangeBehavior(
    HWND                        hDlg,
    DIALOG_DPI_CHANGE_BEHAVIORS mask,
    DIALOG_DPI_CHANGE_BEHAVIORS values
) {
    return TRUE;
}

#pragma export("SetProcessDpiAwarenessContext")
BOOL e_SetProcessDpiAwarenessContext(
  DPI_AWARENESS_CONTEXT value
) {
    SetLastError(ERROR_ACCESS_DENIED);
    return FALSE;
}

