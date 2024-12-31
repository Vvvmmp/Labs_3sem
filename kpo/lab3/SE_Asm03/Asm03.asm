.586
.model flat, stdcall
includelib kernel32.lib
MessageBoxA PROTO :DWORD, :DWORD, :DWORD, :DWORD
ExitProcess PROTO :DWORD

.stack 4096

.const 
button DD 0

.data
    HW DD 0
    window BYTE "Окно", 0
    zeroMessage BYTE "Есть нулевой элемент", 0
    noZeroMessage BYTE "Нулевых элементов нет", 0
    sumMessage BYTE "Сумма:   ", 0
    myArray BYTE 1, 0, 5, 4, 5, 6, 7
    sum BYTE 0

    myBytes BYTE 10h, 20h, 30h, 40h
	myWords WORD 8Ah, 3Bh, 44h, 5Fh, 99h
	myDoubles DWORD 1, 0, 3, 4, 5, 6
	myPointer DWORD myDoubles

.code

main PROC
    mov EBX, myPointer
    mov EAX, [EBX + 8]
    mov EDX, [EBX]

    mov EAX, 0               
    mov EBX, 0               
    mov ECX, 0 
    mov DL, 0
    mov ESI, OFFSET myArray  

for_start:
    cmp ECX, 7               
    jge for_end              

    mov AL, [ESI + ECX]      
    add DL, AL           

    cmp AL, 0                
    jne not_zero             
    mov EBX, 1               

not_zero:
    inc ECX                  
    jmp for_start            

for_end:
    cmp EBX, 1              
    je show_zero             
    mov ESI, OFFSET noZeroMessage
    jmp show_message

show_zero:
    mov ESI, OFFSET zeroMessage

show_message:
mov sum, DL
    INVOKE MessageBoxA, HW, ESI, OFFSET window, button          
mov AL, sum
   mov EDI, OFFSET sumMessage + 7
    mov EBX, 10 
   
convert:
    xor EDX, EDX             
    div EBX                  
    add DL, '0'              
    mov [EDI], DL           
    dec EDI                  
    test EAX, EAX           
    jnz convert              

    INVOKE MessageBoxA, HW, OFFSET sumMessage, OFFSET window, button

    INVOKE ExitProcess, 0

main ENDP
end main
