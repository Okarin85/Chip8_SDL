#include "cpu.h"

void initialiseCpu(){
    for (int i = 0; i < 4096; i++){
        cpu.memory[i] = 0;
    }
    for(int i = 0; i < 16; i++){
        cpu.V[i] = 0;
    }
    cpu.I = 0;
    cpu.pc = 512;
    cpu.opcode = 0;
}
