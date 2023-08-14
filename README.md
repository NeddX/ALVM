# ALVM
Basic partial ISA virtual machine written in C++20.
The ISA is almost identical to that of x86 and the syntax is a mix of AT&T, Intel. The assembler directives are also inspired by MASM and NASM.

# Build
## Linux
- Requires CMake 3.20+
- Clang 16.0.6+
- Make
Do ```chmod 772 build``` and then run ```build```.
If the compilation was successful, you should see the binaries at ```bin/```.

## Windows
Coming up.

# Usage
## ALASM
Command format: ```alasm [file] [options]```
Compiles the ALVM assembler code to bytecode in binary.

Options:
- ```-o [path]```: Specifies the output location.
- ```--dump-intermediate```: Stores the code generated by the assembler (assemblers are not one to one mapping to machine code so there might be slight differences in the code generated by assemblers).

## ALVM
Command format: ```alvm [file]```
Execute the bytecode.

# Plans
- Wrote few terminal games in ALVM bytecode.
- Write a very basic C compiler that compiles to ALVM bytecode.
- Compile ALVM bytecode to machine code by first generating x86 AT&T assembly and then compiling it with GCC to machine.
- Create a scripting language that compiled to ALVM bytecode.
