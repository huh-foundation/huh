section .data
    ; Declare as a variable if in camel case
    camelCaseVariable db 'This is a variable in camel case', 0
    ; Declare as a constant if in Pascal case
    PascalCaseConstant equ 42
    
    ; Declare as a variable if in kebab case
    kebab_case_variable db 'This is a variable in kebab case', 0
    ; Declare as a variable if in snake case
    snake_case_variable db 'This is a variable in snake case', 0

section .text
global _start

_start:
    ; If the variable name is in camel case
    ; Write code to use the variable here.
    ; Write the camelCaseVariable to the standard output (console)
    mov eax, 4
    mov ebx, 1
    mov ecx, camelCaseVariable
    mov edx, 30
    int 0x80

    ; If the variable name is in Pascal case
    ; Write code to use the constant here.
    ; Add PascalCaseConstant to eax and exit
    add eax, PascalCaseConstant

    ; If the variable name is in kebab case
    ; Write code to use the variable here.
    ; Write the kebab_case_variable to the standard output (console)
    mov eax, 4
    mov ebx, 1
    mov ecx, kebab_case_variable
    mov edx, 30
    int 0x80

    ; If the variable name is in snake case
    ; Write code to use the variable here.
    ; Write the snake_case_variable to the standard output (console)
    mov eax, 4
    mov ebx, 1
    mov ecx, snake_case_variable
    mov edx, 30
    int 0x80

    ; Program termination
    mov eax, 1
    int 0x80
