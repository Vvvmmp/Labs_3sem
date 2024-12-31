.586
.model flat, stdcall
includelib libucrt.lib
includelib kernel32.lib
includelib ..\Debug\StaticLibrary.lib
ExitProcess PROTO:DWORD 
.stack 4096


 outnum PROTO : DWORD

 outstr	   PROTO : DWORD

 lenght	   PROTO : DWORD

 atoii	   PROTO : DWORD,  : DWORD

 fibonachi  PROTO : DWORD

 factorial  PROTO : DWORD

 power	   PROTO : DWORD,  : DWORD

.const
		newline byte 13, 10, 0
		LTRL1 dword 1
		LTRL2 byte 'myprint: ', 0
		LTRL3 byte '      -----------------------', 0
		LTRL4 byte '      test operation with num', 0
		LTRL5 dword 4
		LTRL6 dword 17
		LTRL7 byte 'a= ', 0
		LTRL8 byte 'b= ', 0
		LTRL9 dword 100
		LTRL10 dword 10
		LTRL11 dword 2
		LTRL12 byte '1) res= ', 0
		LTRL13 dword 5
		LTRL14 byte '2) res= ', 0
		LTRL15 byte 'test My Min: ', 0
		LTRL16 byte 'min: ', 0
		LTRL17 byte '      ---------------------------------', 0
		LTRL18 byte '      test function from static library', 0
		LTRL19 byte 'hello', 0
		LTRL20 byte 'lenght: ', 0
		LTRL21 byte '5125', 0
		LTRL22 byte 'atoii: ', 0
		LTRL23 dword 6
		LTRL24 byte 'power: ', 0
		LTRL25 dword 40
		LTRL26 byte 'fibonachi: ', 0
		LTRL27 byte 'Factorial: ', 0
		LTRL28 byte 'test My Factorial: ', 0
		LTRL29 byte '      -------------------', 0
		LTRL30 byte '      test number systems', 0
		LTRL31 dword 11
		LTRL32 dword 1004
		LTRL33 dword 12345
		LTRL34 dword 8090
		LTRL35 byte 'bin: ', 0
		LTRL36 byte 'oct: ', 0
		LTRL37 byte 'dec: ', 0
		LTRL38 byte 'hex: ', 0
.data
		temp sdword ?
		buffer byte 256 dup(0)
	ERROR_MINUS byte 'ERROR 404: LEAVE THE RANGE',0
	ERROR_DIVIDE byte 'ERROR 303: DIVIDE BY ZERO',0
		facti dword 0
		factres dword 0
		myminresult dword 0
		roota dword 0
		rootb dword 0
		rootres dword 0
		rootmm dword 0
		rootle dword 0
		roote dword 0
		rootbin dword 0
		rootoct dword 0
		rootdec dword 0
		roothex dword 0
.code

;----------- fact ------------
_fact PROC,
	factnumber : dword  
; ~~~ сохранение регистров ~~~
push ebx
push edx
; ~~~~~~~~~~~~~~~~~~~~~~
push LTRL1

pop ebx
mov facti, ebx

push LTRL1

pop ebx
mov factres, ebx

mov edx, factnumber
cmp edx, facti

jg cycle1
jmp cyclenext1
cycle1:
push factres
push facti
pop ebx
pop eax
imul eax, ebx
jnc out_range_mul_31
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_mul_31:
push eax

pop ebx
mov factres, ebx

push facti
push LTRL1
pop ebx
pop eax
add eax, ebx
jnc out_range_37
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_37:
push eax

pop ebx
mov facti, ebx

mov edx, factnumber
cmp edx, facti

jg cycle1
cyclenext1:
push factres
push factnumber
pop ebx
pop eax
imul eax, ebx
jnc out_range_mul_45
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_mul_45:
push eax

pop ebx
mov factres, ebx

; ~~~ восстановление регистров ~~~
pop edx
pop ebx
; ~~~~~~~~~~~~~~~~~~~~~~~~
mov eax, factres
ret
_fact ENDP
;------------------------------


;----------- myprint ------------
_myprint PROC,
	myprinta : dword  
; ~~~ сохранение регистров ~~~
push ebx
push edx
; ~~~~~~~~~~~~~~~~~~~~~~
push offset newline
call outstr


push offset LTRL2
call outstr


push myprinta
call outstr

; ~~~ восстановление регистров ~~~
pop edx
pop ebx
; ~~~~~~~~~~~~~~~~~~~~~~~~
ret
_myprint ENDP
;------------------------------


;----------- mymin ------------
_mymin PROC,
	mymina : dword, myminb : dword  
; ~~~ сохранение регистров ~~~
push ebx
push edx
; ~~~~~~~~~~~~~~~~~~~~~~
mov edx, mymina
cmp edx, myminb

jg right2
jl wrong2
right2:
push myminb

pop ebx
mov myminresult, ebx

jmp next2
wrong2:
push mymina

pop ebx
mov myminresult, ebx

next2:
; ~~~ восстановление регистров ~~~
pop edx
pop ebx
; ~~~~~~~~~~~~~~~~~~~~~~~~
mov eax, myminresult
ret
_mymin ENDP
;------------------------------


;----------- MAIN ------------
main PROC

push offset LTRL3
call outstr

push offset newline
call outstr


push offset LTRL4
call outstr

push offset newline
call outstr


push offset LTRL3
call outstr

push offset newline
call outstr

push LTRL5

pop ebx
mov roota, ebx

push LTRL6

pop ebx
mov rootb, ebx


push offset LTRL7
call outstr


push roota
call outnum

push offset newline
call outstr


push offset LTRL8
call outstr


push rootb
call outnum

push offset newline
call outstr

push roota
push rootb
push LTRL9
push LTRL10
pop ebx
pop eax
cmp ebx, eax
jle positive_value_164
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
positive_value_164:
sub eax, ebx
push eax
pop ebx
pop eax
imul eax, ebx
jnc out_range_mul_165
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_mul_165:
push eax
push LTRL11
pop ebx
pop eax
cmp ebx, 0
jne division_by_zero_error_167
push offset ERROR_DIVIDE
call outstr

INVOKE ExitProcess,0
division_by_zero_error_167:
cdq
idiv ebx
push eax
pop ebx
pop eax
add eax, ebx
jnc out_range_168
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_168:
push eax

pop ebx
mov rootres, ebx


push offset LTRL12
call outstr


push rootres
call outnum

push rootres
push rootb
pop ebx
pop eax
add eax, ebx
jnc out_range_180
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_180:
push eax

push LTRL10
push LTRL13
call power
push eax
pop ebx
pop eax
add eax, ebx
jnc out_range_187
push offset ERROR_MINUS
call outstr

INVOKE ExitProcess,0
out_range_187:
push eax

pop ebx
mov rootres, ebx

push offset newline
call outstr


push offset LTRL14
call outstr


push rootres
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL15
call outstr


push rootb
push roota
call _mymin
push eax

pop ebx
mov rootmm, ebx


push offset LTRL16
call outstr


push rootmm
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL17
call outstr

push offset newline
call outstr


push offset LTRL18
call outstr

push offset newline
call outstr


push offset LTRL17
call outstr

push offset newline
call outstr


push offset LTRL19
call lenght
push eax

pop ebx
mov rootle, ebx


push offset LTRL20
call outstr


push rootle
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL21
push offset buffer
call atoii
push eax

pop ebx
mov roote, ebx


push offset LTRL22
call outstr

push roote
push LTRL23
pop ebx
pop eax
cmp ebx, 0
jne division_by_zero_error_281
push offset ERROR_DIVIDE
call outstr

INVOKE ExitProcess,0
division_by_zero_error_281:
cdq
idiv ebx
push eax

pop ebx
mov roote, ebx


push roote
call outnum

push offset newline
call outstr

push offset newline
call outstr


push LTRL10
push LTRL13
call power
push eax

pop ebx
mov roote, ebx


push offset LTRL24
call outstr


push roote
call outnum

push offset newline
call outstr

push offset newline
call outstr


push LTRL25
call fibonachi
push eax

pop ebx
mov roote, ebx


push offset LTRL26
call outstr


push roote
call outnum

push offset newline
call outstr

push offset newline
call outstr


push LTRL13
call factorial
push eax

pop ebx
mov roote, ebx


push offset LTRL27
call outstr


push roote
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL28
call outstr


push LTRL13
call _fact
push eax

pop ebx
mov roote, ebx


push roote
call outnum

push offset newline
call outstr

push offset newline
call outstr


push offset LTRL29
call outstr

push offset newline
call outstr


push offset LTRL30
call outstr

push offset newline
call outstr


push offset LTRL29
call outstr

push offset newline
call outstr

push LTRL31

pop ebx
mov rootbin, ebx

push LTRL32

pop ebx
mov rootoct, ebx

push LTRL33

pop ebx
mov rootdec, ebx

push LTRL34

pop ebx
mov roothex, ebx


push offset LTRL35
call outstr


push rootbin
call outnum

push offset newline
call outstr


push offset LTRL36
call outstr


push rootoct
call outnum

push offset newline
call outstr


push offset LTRL37
call outstr


push rootdec
call outnum

push offset newline
call outstr


push offset LTRL38
call outstr


push roothex
call outnum

push offset newline
call outstr

push 0
call ExitProcess
main ENDP
end main
