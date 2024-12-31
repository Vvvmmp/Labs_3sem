.586P
.MODEL FLAT, STDCALL

includelib "..\Debug\SE_asm01a.lib"
includelib kernel32.lib

ExitProcess			PROTO: DWORD
SetConsoleTitleA	PROTO: DWORD
GetStdHandle		PROTO: DWORD
WriteConsoleA		PROTO: DWORD, : DWORD, : DWORD, : DWORD, : DWORD
getMin				PROTO: DWORD, : DWORD
getMax				PROTO: DWORD, : DWORD

.STACK 4096

.CONST 
constitle	DB 'SE_asm01b', 0
Arr				DD 2, 3, 4, 8, 1 ,2 ,2, 7, 4, 5

.DATA
result1			BYTE "getMax + getMin = ", 0
result			sdword 0
consolehandle	DD 0h

.CODE
main PROC

	invoke SetConsoleTitleA, offset constitle

	push -11
	call GetStdHandle
	mov consolehandle, eax

	invoke getMin, offset Arr, lengthof Arr

	mov result, eax

	invoke getMax, offset Arr, lengthof Arr

	add result, eax
	add result, 30h
	mov eax, result

	mov result1 + 18, al

	invoke WriteConsoleA, consolehandle, offset result1, sizeof result1, 0, 0

	push 0
	call ExitProcess

main ENDP

END main
