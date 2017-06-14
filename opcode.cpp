#include "opcode.h"

void executeOpcode(){
cpu.opcode = (cpu.memory[cpu.pc] << 8) + cpu.memory[cpu.pc + 1];

x    = (cpu.opcode & 0x0F00) >> 8;
y    = (cpu.opcode & 0x00F0) >> 4;
n    =  cpu.opcode & 0x000F;
nn   =  cpu.opcode & 0x00FF;
nnn  =  cpu.opcode & 0x0FFF;

printf("opcode : ");
printf("%04x\n", cpu.opcode);
printf("pc : ");
printf("%d\n", cpu.pc);

switch(cpu.opcode & 0xF000){

    case 0x1000:
        cpu.pc = nnn;
    break;

    case 0x3000:
        if(cpu.V[x] == nn){
            cpu.pc += 2;
        }
    cpu.pc += 2;
    break;

    case 0x7000:
        cpu.V[x] = (cpu.V[x] += nn) & 0xFF;
    cpu.pc += 2;
    break;

    case 0xA000:
        cpu.I = nnn;
    cpu.pc += 2;
    break;

    case 0xC000:
        cpu.V[x] = rand() & nn;
    cpu.pc += 2;
    break;

    case 0xD000:
        drawSprite(x, y, n);
        SDL_Flip(screen);
        SDL_Delay(100);
    cpu.pc += 2;
    break;

    default:
        printf("opcode not implemented\n");
    cpu.pc += 2;
    break;
    }
}
