.586
.MODEL flat, stdcall
includelib kernel32.lib
ExitProcess PROTO :DWORD
MessageBoxA PROTO, : DWORD, : DWORD, : DWORD, : DWORD

.stack 4096

.const
button DD 0

.data
HW DD 0
window BYTE "Окно", 0
string BYTE  "Сумма:  ", 0
num1 byte 3
num2 byte 4


.code

main Proc
START:
mov AL, num1
add AL, num2
add AL, '0'
mov ESI, offset string

mov [ESI + 7], AL

INVOKE MessageBoxA, HW, offset string, offset window, button

INVOKE ExitProcess, 0
main ENDP
end main