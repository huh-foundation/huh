#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1024

typedef struct {
    int pc;
    int registers[4];
    int memory[MEM_SIZE];
    int stack[256];
    int sp;
    int flag;
} VM;

enum { HALT, LOAD, ADD, SUB, MUL, DIV, PUSH, POP, JMP, CMP, JE, JNE, CALL, RET };

void init_vm(VM *vm) {
    vm->pc = 0;
    vm->sp = -1;
    vm->flag = 0;
    for (int i = 0; i < 4; i++) vm->registers[i] = 0;
    for (int i = 0; i < MEM_SIZE; i++) vm->memory[i] = 0;
}

void load_program(VM *vm, int *program, int size) {
    for (int i = 0; i < size; i++) vm->memory[i] = program[i];
}

void run(VM *vm) {
    int running = 1;
    while (running) {
        int instruction = vm->memory[vm->pc++];
        switch (instruction) {
            case HALT: running = 0; break;
            case LOAD: {
                int reg = vm->memory[vm->pc++];
                int value = vm->memory[vm->pc++];
                vm->registers[reg] = value;
            } break;
            case ADD: {
                int reg1 = vm->memory[vm->pc++];
                int reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] += vm->registers[reg2];
            } break;
            case SUB: {
                int reg1 = vm->memory[vm->pc++];
                int reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] -= vm->registers[reg2];
            } break;
            case MUL: {
                int reg1 = vm->memory[vm->pc++];
                int reg2 = vm->memory[vm->pc++];
                vm->registers[reg1] *= vm->registers[reg2];
            } break;
            case DIV: {
                int reg1 = vm->memory[vm->pc++];
                int reg2 = vm->memory[vm->pc++];
                if (vm->registers[reg2] == 0) {
                    printf("Error: Division by zero.\n");
                    running = 0;
                } else {
                    vm->registers[reg1] /= vm->registers[reg2];
                }
            } break;
            case PUSH: {
                int reg = vm->memory[vm->pc++];
                vm->stack[++vm->sp] = vm->registers[reg];
            } break;
            case POP: {
                int reg = vm->memory[vm->pc++];
                if (vm->sp < 0) {
                    printf("Error: Stack underflow.\n");
                    running = 0;
                } else {
                    vm->registers[reg] = vm->stack[vm->sp--];
                }
            } break;
            case JMP: {
                int address = vm->memory[vm->pc++];
                vm->pc = address;
            } break;
            case CMP: {
                int reg1 = vm->memory[vm->pc++];
                int reg2 = vm->memory[vm->pc++];
                vm->flag = (vm->registers[reg1] == vm->registers[reg2]);
            } break;
            case JE: {
                int address = vm->memory[vm->pc++];
                if (vm->flag) vm->pc = address;
            } break;
            case JNE: {
                int address = vm->memory[vm->pc++];
                if (!vm->flag) vm->pc = address;
            } break;
            case CALL: {
                int address = vm->memory[vm->pc++];
                vm->stack[++vm->sp] = vm->pc;
                vm->pc = address;
            } break;
            case RET: {
                if (vm->sp < 0) {
                    printf("Error: Stack underflow on return.\n");
                    running = 0;
                } else {
                    vm->pc = vm->stack[vm->sp--];
                }
            } break;
            default: {
                printf("Unknown instruction: %d\n", instruction);
                running = 0;
            } break;
        }
    }
}

int main() {
    VM vm;
    init_vm(&vm);

    int program[] = {
        LOAD, 0, 10,
        LOAD, 1, 20,
        ADD, 0, 1,
        PUSH, 0,
        POP, 2,
        HALT
    };

    load_program(&vm, program, sizeof(program) / sizeof(int));
    run(&vm);

    return 0;
}
