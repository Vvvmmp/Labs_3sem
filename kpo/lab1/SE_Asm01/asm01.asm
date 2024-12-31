.586							
.model flat, stdcall				
includelib kernel32.lib			
	

ExitProcess PROTO :DWORD									
MessageBoxA PROTO :DWORD, :DWORD, :DWORD , :DWORD		

.STACK 4096				

.CONST					

.DATA						
MB_OK EQU 1					

STR1 DB "Ассемблер", 0
STR2 DB "Моя первая программа", 0	
HW DD ?						

.CODE
main PROC					
START:

INVOKE MessageBoxA, HW, OFFSET STR2,OFFSET STR1, MB_OK 
	push 0
call ExitProcess
main ENDP				

end main			