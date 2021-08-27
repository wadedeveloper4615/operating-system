[BITS 32]
global _test

section   .text
_test:
    push    ebp
    mov     ebp, esp
    mov     eax, [ebp+8]
    xor     edx, edx
    div     dword [ebp+12]
    mov     esp, ebp
    pop     ebp
    ret