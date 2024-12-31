.586
.model flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST
button DD 0

.DATA
HW DD 0
resultString DB 256 DUP(?), 0
window BYTE "Окно", 0
ushortL dw 10
shortN dw -55

.CODE
main PROC
	LEA EDI, resultString
mov AX, ushortL
call ConvertToDecimal
mov BYTE PTR [EDI], ' '
inc EDI
mov AX, shortN
call ConvertToDecimal
mov BYTE PTR [EDI], 0
INVOKE MessageBoxA, HW, OFFSET resultString, OFFSET window, button
INVOKE ExitProcess, 0
main ENDP
ConvertToDecimal PROC
	push EAX
	push EBX
	push ECX
	push EDX
	cmp AX, 0
	jge PositiveNumber
	neg AX
	mov BYTE PTR [EDI], '-'
	inc EDI
PositiveNumber:
	xor EBX, EBX
	mov BX, 10
	xor ECX, ECX
ConvertLoop:
	xor EDX, EDX
	div BX
	push DX
	inc ECX
	test AX, AX
	jnz ConvertLoop
RestoreDigits:
	pop DX
	add DL, '0'
	mov BYTE PTR [EDI], DL
	inc EDI
	loop RestoreDigits
	pop EDX
	pop ECX
	pop EBX
	pop EAX
	RET
ConvertToDecimal ENDP
end main
