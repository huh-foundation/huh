## **HUH Virtual Machine (VM) Implementation Documentation**

### **Overview**

This project is an implementation of a simple virtual machine (VM) using a mix of **C** and **assembly** language. The VM simulates a basic computer architecture with registers, memory, a stack, and an instruction set. This VM can interpret and execute a set of predefined instructions, which include basic arithmetic operations, jumps, stack manipulation, and function calls.

---

### **Features**

1. **Registers**: 
   - The VM includes **4 general-purpose registers** (`registers[0]` to `registers[3]`).
   
2. **Memory**:
   - The VM has a **64KB memory space** that stores programs and data (`memory[65536]`).

3. **Stack**:
   - A **256-slot stack** is used for function calls, local variables, and temporary values (`stack[256]`).

4. **Instruction Set**:
   - Basic instructions such as `LOAD`, `ADD`, `SUB`, `MUL`, `DIV`, `PUSH`, `POP`, `JMP`, `CMP`, and `CALL`.
   - Flow control via jump instructions (`JMP`, `JE`, `JNE`) and function call/return (`CALL`, `RET`).

5. **Assembly Integration**:
   - A simple assembly function (`print_registers`) is used for enhanced performance when printing register values.

6. **Error Handling**:
   - Handles basic errors such as **division by zero**, **stack overflow**, and **stack underflow**.

---

### **Installation & Setup**

1. **Requirements**:
   - A C compiler (e.g., GCC)
   - Make sure `libc` is installed (for printf functionality)
   - Assembly compiler (e.g., NASM or the assembler included in GCC)

2. **Compiling**:
   To compile the code, run the following command in the project directory:

   ```bash
   gcc -o vm vm.c
   ```

3. **Running**:
   After compiling, the executable can be run using:

   ```bash
   ./vm
   ```

---

### **Instruction Set**

The VM supports the following instructions:

| Instruction | Opcode | Description                                  |
|-------------|--------|----------------------------------------------|
| `HALT`      | 0x00   | Stops the program execution                  |
| `LOAD`      | 0x01   | Loads an immediate value into a register      |
| `ADD`       | 0x02   | Adds two registers and stores the result      |
| `SUB`       | 0x03   | Subtracts one register from another           |
| `MUL`       | 0x04   | Multiplies two registers                      |
| `DIV`       | 0x05   | Divides one register by another               |
| `PUSH`      | 0x06   | Pushes the value of a register onto the stack |
| `POP`       | 0x07   | Pops a value from the stack into a register   |
| `JMP`       | 0x08   | Jumps to a specified memory address           |
| `CMP`       | 0x09   | Compares two registers and sets a flag        |
| `JE`        | 0x0A   | Jumps if the comparison flag is true          |
| `JNE`       | 0x0B   | Jumps if the comparison flag is false         |
| `CALL`      | 0x0C   | Calls a subroutine (saves return address)     |
| `RET`       | 0x0D   | Returns from a subroutine                     |

---

### **Example Program**

Here is an example program that can be loaded into the VM:

```c
uint8_t program[] = {
    LOAD, 0, 0x0A, 0x00, 0x00, 0x00,  // Load 10 into register 0
    LOAD, 1, 0x14, 0x00, 0x00, 0x00,  // Load 20 into register 1
    ADD, 0, 1,                        // Add register 1 to register 0
    HALT                              // Halt the program
};
```

This simple program:
1. Loads the value `10` into `register[0]`.
2. Loads the value `20` into `register[1]`.
3. Adds the values of `register[0]` and `register[1]` and stores the result in `register[0]`.
4. Halts the program execution.

---

### **Architecture**

- **Registers**: The VM contains 4 general-purpose 32-bit registers for computations.
- **Memory**: The VM’s memory space is 64KB, which is used to store both the program and data.
- **Stack**: The stack is used for function calls and temporary data storage. It has 256 slots.
- **Flags**: A single flag is used for conditional jumps (`JE`, `JNE`).

---

### **Error Handling**

1. **Division by Zero**:
   - When attempting to divide by zero, the VM will output an error message and halt the program.
   
2. **Stack Overflow/Underflow**:
   - If a `PUSH` instruction is executed when the stack is full or a `POP` is executed when the stack is empty, an error message will be displayed, and the VM will halt.

---

### **Extending the VM**

To extend the VM:
1. Add more instructions by expanding the `enum` and handling the new opcodes in the `run()` function.
2. Implement new functionality in C or assembly and modify the instruction set accordingly.

---

### **Limitations**

1. The VM does not support floating-point arithmetic.
2. There is no memory protection, so invalid memory access could lead to undefined behavior.
3. The program size is limited by the `MEM_SIZE` (64KB in this implementation).

---

### **Future Improvements**

1. **I/O Instructions**: Add instructions to interact with external devices or files.
2. **Interrupt Handling**: Add support for interrupt handling for more advanced VM control.
3. **Optimized Assembly Integration**: Further optimize performance by implementing critical parts in assembly.
4. **Debugging**: Add features like step-through debugging, breakpoints, and stack inspection.

---

### **Conclusion**

This virtual machine project provides a basic yet functional platform to simulate the operation of a CPU with a custom instruction set. It can be extended to support more advanced features, offering a foundation for learning about low-level computing, virtual machines, and even operating system concepts.

