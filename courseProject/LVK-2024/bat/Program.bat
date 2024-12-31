@ECHO OFF
cd /d C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build
call vcvarsall.bat x86
cd /d C:\labi\3sem\courseProject\LVK-2024\Assembler
ml /c /coff /Zi result.asm
link /OPT:NOREF /DEBUG /SUBSYSTEM:CONSOLE result.obj /NODEFAULTLIB:library user32.lib
cls
call result.exe
pause
exit