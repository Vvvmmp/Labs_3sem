.586P
.MODEL FLAT, STDCALL

includelib kernel32.lib
includelib libucrt.lib

ExitProcess			PROTO: DWORD
GetStdHandle		PROTO: DWORD
WriteConsoleA		PROTO: DWORD, : DWORD, : DWORD, : DWORD, : DWORD

EXTRN getMax@8: proc
EXTRN getMin@8: proc

.STACK 4096

.CONST 
consoletitle	DB 'SE_asm01d', 0
Arr				DD 2, 3, 4, 8, 1 ,2 ,20, 7, 4, 5

.DATA
result1			BYTE "getMax + getMin =     ", 0
result			sdword 0
consolehandle	DD 0h

.CODE
main PROC

	

	push -11
	call GetStdHandle
	mov consolehandle, eax
	
	push lengthof Arr
	push offset Arr
	call getMin@8

	mov result, eax

	push lengthof Arr
	push offset Arr
	call getMax@8

	add result, eax
	
	mov eax, result

	mov EBX, EAX                                
    mov ECX, 10                                 
    lea EDI, [result1 + 19] 
  ConvertToString1:
    xor EDX, EDX                                
    div ECX                                     
    add DL, '0'                                 
    mov [EDI], DL                               
    dec EDI                                     
    test EAX, EAX                               
    jnz ConvertToString1

	invoke WriteConsoleA, consolehandle, offset result1, sizeof result1, 0, 0

	push 0
	call ExitProcess

main ENDP

END main