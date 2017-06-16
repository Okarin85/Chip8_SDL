#include "cpu.h"

void initialiseCpu(){
    for (int i = 0; i < 4096; i++){
        cpu.memory[i] = 0;
    }
    for(int i = 0; i < 16; i++){
        cpu.V[i] = 0;
    }
    for(int i = 0; i < 80; i++){
        cpu.memory[i] = font[i];
    }
    cpu.I = 0;
    cpu.pc = 512;
    cpu.delayTimer = 0;
    cpu.soundTimer = 0;

    cpu.opcode = 0;
    cpu.running = 1;
}
