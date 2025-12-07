mkdir out
cd out
mkdir %VSCMD_ARG_TGT_ARCH%
cd %VSCMD_ARG_TGT_ARCH%
cl ..\..\user32\base.c /link user32.lib /DLL /out:hser32.dll || goto fail
cl ..\..\kernel32\base.c /link kernel32.lib /DLL /out:hernel32.dll || goto fail
cl ..\..\mswin\version\base.c /link version.lib /DLL /out:api-ms-win-core-version-l1-1-1.dll || goto fail
cl ..\..\mswin\libraryloader\base.c /link kernel32.lib /DLL /out:api-ms-win-core-libraryloader-l1-2-1.dll || goto fail
cl ..\..\mswin\heap\base.c /link kernel32.lib /DLL /out:api-ms-win-core-heap-l2-1-0.dll || goto fail
cd ..\..
exit /b

:fail
echo failure
exit /b