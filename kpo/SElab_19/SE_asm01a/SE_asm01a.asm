.586P
.MODEL FLAT, STDCALL
.CODE

getMin PROC uses ecx esi ebx, parm01: dword, parm02: dword

      mov   ecx, parm02
      mov   esi, parm01
      mov   eax, [parm01]

CYCLE: 

      mov   ebx, [esi]
      add   esi, 4
      cmp   eax, ebx
      jl    False
      xchg  eax, ebx

False: 

      loop  CYCLE

	  ret

getMin ENDP

getMax PROC uses ecx esi ebx, parm01: dword, parm02: dword

      mov   ecx, parm02
      mov   esi, parm01
      mov   eax, [esi]

CYCLE: 

      mov   ebx, [esi]
      add   esi, 4
      cmp   eax, ebx
      jg    False
      xchg  eax, ebx

False: 

      loop  CYCLE

	  ret

getMax ENDP

end