#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MEM_SIZE 65536
#define STACK_SIZE 256

enum {
    HALT,  
    LOAD,  
    ADD,   
    SUB,   
    MUL,   
    DIV,   
    PUSH,  
    POP,   
    JMP,   
    CMP,   
    JE,    
    JNE,   
    CALL,  
    RET    
};

typedef struct {
    uint16_t pc;                
    uint16_t sp;               
    int32_t registers[4];       
    uint8_t memory[MEM_SIZE];   
    int32_t stack[STACK_SIZE];  
    uint8_t flags;              
} VM;

void init_vm(VM *vm) {
    vm->pc = 0;
    vm->sp = 0;
    for (int i = 0; i < 4; i++) {
        vm->registers[i] = 0;
    }
    for (int i = 0; i < MEM_SIZE; i++) {
        vm->memory[i] = 0;
    }
    vm->flags = 0;
}

void load_program(VM *vm, const uint8_t *program, size_t size) {
    for (size_t i = 0; i < size && i < MEM_SIZE; i++) {
        vm->memory[i] = program[i];
    }
}

void run(VM *vm) {
    uint8_t running = 1;
    while (running) {
        uint8_t opcode = vm->memory[vm->pc++];
        switch (opcode) {
            case HALT:
                running = 0;
                break;
            case LOAD: {
                uint8_t reg = vm->memory[vm->pc++];
                int32_t value = *(int32_t*)&vm->memory[vm->pc];
                vm->registers[reg] = value;
                vm->pc += 4;
                break;
            }
            case ADD: {
                uint8_t reg1 = vm->memory[vm->pc++];
                uint8_t reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] += vm->registers[reg2];
                break;
            }
            case SUB: {
                uint8_t reg1 = vm->memory[vm->pc++];
                uint8_t reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] -= vm->registers[reg2];
                break;
            }
            case MUL: {
                uint8_t reg1 = vm->memory[vm->pc++];
                uint8_t reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] *= vm->registers[reg2];
                break;
            }
            case DIV: {
                uint8_t reg1 = vm->memory[vm->pc++];
                uint8_t reg2 = vm->memory[vm->pc++];
                if (vm->registers[reg2] == 0) {
                    printf("Division by zero error\n");
                    running = 0;
                } else {
                    vm->registers[reg1] /= vm->registers[reg2];
                }
                break;
            }
            case PUSH: {
                if (vm->sp >= STACK_SIZE) {
                    printf("Stack overflow\n");
                    running = 0;
                } else {
                    uint8_t reg = vm->memory[vm->pc++];
                    vm->stack[vm->sp++] = vm->registers[reg];
                }
                break;
            }
            case POP: {
                if (vm->sp == 0) {
                    printf("Stack underflow\n");
                    running = 0;
                } else {
                    uint8_t reg = vm->memory[vm->pc++];
                    vm->registers[reg] = vm->stack[--vm->sp];
                }
                break;
            }
            case JMP: {
                uint16_t addr = *(uint16_t*)&vm->memory[vm->pc];
                vm->pc = addr;
                break;
            }
            case CMP: {
                uint8_t reg1 = vm->memory[vm->pc++];
                uint8_t reg2 = vm->memory[vm->pc++];
                vm->flags = (vm->registers[reg1] == vm->registers[reg2]);
                break;
            }
            case JE:
                if (vm->flags) {
                    uint16_t addr = *(uint16_t*)&vm->memory[vm->pc];
                    vm->pc = addr;
                } else {
                    vm->pc += 2;
                }
                break;
            case JNE:
                if (!vm->flags) {
                    uint16_t addr = *(uint16_t*)&vm->memory[vm->pc];
                    vm->pc = addr;
                } else {
                    vm->pc += 2;
                }
                break;
            case CALL: {
                if (vm->sp >= STACK_SIZE) {
                    printf("Stack overflow\n");
                    running = 0;
                } else {
                    uint16_t addr = *(uint16_t*)&vm->memory[vm->pc];
                    vm->stack[vm->sp++] = vm->pc + 2; // 반환 주소 저장
                    vm->pc = addr;
                }
                break;
            }
            case RET: {
                if (vm->sp == 0) {
                    printf("Stack underflow\n");
                    running = 0;
                } else {
                    vm->pc = vm->stack[--vm->sp]; 
                }
                break;
            }
            default:
                printf("Unknown instruction %d\n", opcode);
                running = 0;
                break;
        }
    }
}

__asm__(
".global print_registers\n"
"print_registers:\n"
"    movl 4(%esp), %eax\n"        
"    push %eax\n"                 
"    call printf\n"               
"    add $4, %esp\n"              
"    ret\n"
);

void print_registers(VM *vm) {
    for (int i = 0; i < 4; i++) {
        printf("Register[%d] = %d\n", i, vm->registers[i]);
    }
}

int main() {
    VM vm;
    init_vm(&vm);

    uint8_t program[] = {
        LOAD, 0, 0x0A, 0x00, 0x00, 0x00,  
        LOAD, 1, 0x14, 0x00, 0x00, 0x00,  
        ADD, 0, 1,                        
        HALT                              
    };
    load_program(&vm, program, sizeof(program));
    run(&vm);
    print_registers(&vm);

    return 0;
}
