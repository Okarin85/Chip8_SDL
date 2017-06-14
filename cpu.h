#ifndef CPU_H_INCLUDED
#define CPU_H_INCLUDED

typedef struct{
    unsigned char memory[4096];
    unsigned char V[16];
    unsigned short I;
    unsigned short pc;

    unsigned short opcode;
}CPU;
CPU cpu;

#endif // CPU_H_INCLUDED
