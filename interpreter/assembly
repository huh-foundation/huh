section .data
    result db 0

section .text
    global _start

_start:
    mov ax, 5
    add ax, 3
    mov [result], ax

    mov eax, 4
    mov ebx, 1
    mov ecx, result
    mov edx, 2
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80
