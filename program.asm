section .text
global _start

_start:
    push ebp
    mov ebp, esp
    cmp dword [ebp + 0x8], 0
    push esi