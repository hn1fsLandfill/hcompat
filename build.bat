mkdir out
cd out
mkdir %VSCMD_ARG_TGT_ARCH%
cd %VSCMD_ARG_TGT_ARCH%

cl /I ..\..\common ..\..\kernel32\base.c /link kernel32.lib /DLL /out:hernel32.dll || goto fail
cl /I ..\..\common ..\..\user32\base.c /link user32.lib /DLL /out:hser32.dll || goto fail
cl /I ..\..\common ..\..\netapi32\base.c /link netapi32.lib /DLL /out:hetapi32.dll || goto fail
cl /I ..\..\common ..\..\kernelbase\base.c /link kernel32.lib /DLL /out:hernelbase.dll || goto fail
cl /I ..\..\common ..\..\uiautomationcore\base.c /link uiautomationcore.lib /DLL /out:HIAutomationCore.dll || goto fail
cl /I ..\..\common ..\..\dcomp\base.c /link dcomp.lib /DLL /out:hcomp.dll || goto fail

cl /I ..\..\common ..\..\mswin\version\base.c /link version.lib /DLL /out:api-ms-win-core-version-l1-1-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\libraryloader\base.c /link kernel32.lib /DLL /out:api-ms-win-core-realtime-l1-1-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\heap\base.c /link kernel32.lib /DLL /out:api-ms-win-core-heap-l2-1-0.dll || goto fail
cl /I ..\..\common ..\..\mswin\realtime\base.c /link kernel32.lib /DLL /out:api-ms-win-core-realtime-l1-1-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\localization\base.c /link kernel32.lib /DLL /out:api-ms-win-core-localization-l1-2-2.dll || goto fail
rem cl ..\..\mswin\handle\base.c /link kernel32.lib /DLL /out:api-ms-win-core-handle-l1-1-0.dll || goto fail

del *.obj
del *.exp
del *.lib

cd ..\..
exit /b

:fail
echo failure
cd ..\..
exit /b