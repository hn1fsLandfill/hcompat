mkdir out
cd out
mkdir %VSCMD_ARG_TGT_ARCH%
cd %VSCMD_ARG_TGT_ARCH%

cl /I ..\..\common ..\..\patcher\base.c /link ntdll.lib /DLL /out:hpatcher.dll || goto fail
if %VSCMD_ARG_TGT_ARCH%==x86 copy hpatcher.dll hpatcher32.dll

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