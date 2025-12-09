mkdir out
cd out
mkdir %VSCMD_ARG_TGT_ARCH%
cd %VSCMD_ARG_TGT_ARCH%

cl /I ..\..\common ..\..\core\kernel32\base.c /link kernel32.lib /DLL /out:hernel32.dll || goto fail
cl /I ..\..\common ..\..\core\user32\base.c /link user32.lib /DLL /out:hser32.dll || goto fail
cl /I ..\..\common ..\..\core\netapi32\base.c /link netapi32.lib /DLL /out:hetapi32.dll || goto fail
cl /I ..\..\common ..\..\core\kernelbase\base.c /link kernel32.lib /DLL /out:hernelbase.dll || goto fail
cl /I ..\..\common ..\..\core\comctl32\base.c /link comctl32.lib /DLL /out:homctl32.dll || goto fail
cl /I ..\..\common ..\..\winrt\uiautomationcore\base.c /link uiautomationcore.lib /DLL /out:HIAutomationCore.dll || goto fail
cl /I ..\..\common ..\..\winrt\combase\base.c /link mincore.lib user32.lib /DLL /out:hombase.dll || goto fail
cl /I ..\..\common ..\..\dx\dcomp\base.c /link dcomp.lib /DLL /out:hcomp.dll || goto fail

cl /I ..\..\common ..\..\mswin\version\base.c /link version.lib /DLL /out:api-ms-win-core-version-l1-1-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\libraryloader\base.c /link kernel32.lib /DLL /out:api-ms-win-core-libraryloader-l1-1-1.dll || goto fail
copy api-ms-win-core-libraryloader-l1-1-1.dll api-ms-win-core-libraryloader-l1-2-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\heap\base.c /link kernel32.lib /DLL /out:api-ms-win-core-heap-l2-1-0.dll || goto fail
cl /I ..\..\common ..\..\mswin\realtime\base.c /link kernel32.lib /DLL /out:api-ms-win-core-realtime-l1-1-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\localization\base.c /link kernel32.lib /DLL /out:api-ms-win-core-localization-l1-2-2.dll || goto fail
cl /I ..\..\common ..\..\mswin\namedpipe\base.c /link kernel32.lib /DLL /out:api-ms-win-core-namedpipe-l1-2-1.dll || goto fail
cl /I ..\..\common ..\..\mswin\file\base.c /link kernel32.lib /DLL /out:api-ms-win-core-file-l1-2-2.dll || goto fail
copy api-ms-win-core-file-l1-2-2.dll api-ms-win-core-file-l2-1-2.dll
rem cl ..\..\mswin\handle\base.c /link kernel32.lib /DLL /out:api-ms-win-core-handle-l1-1-0.dll || goto fail

del *.obj
del *.exp
del *.lib
del *.manifest

cd ..\..
exit /b

:fail
echo failure
cd ..\..
exit /b