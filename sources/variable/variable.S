section .data
    ; Declare as a variable if in camel case
    camelCaseVariable db 'This is a variable in camel case', 0
    ; Declare as a constant if in Pascal case
    PascalCaseConstant equ 42

section .text
global _start

_start:
    ; If the variable name is in camel case
    ; Write code to use the variable here.

    ; If the variable name is in Pascal case
    ; Write code to use the constant here.

    ; Program termination
    mov eax, 1
    int 0x80
