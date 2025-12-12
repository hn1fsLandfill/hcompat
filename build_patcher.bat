mkdir out
cd out
mkdir %VSCMD_ARG_TGT_ARCH%
cd %VSCMD_ARG_TGT_ARCH%

cl /I ..\..\common ..\..\patcher\base.c /link ntdll.lib /DLL /out:hpatcher.dll || goto fail

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