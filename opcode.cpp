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

    case 0x0:

        switch (cpu.opcode & 0x00FF) {
            case 0x0:

            break;

            case 0x00EE:
                cpu.sp--;
                cpu.pc = cpu.stack[cpu.sp];
            break;

        } //End nested switch
    break;

    case 0x1000:
        cpu.pc = nnn;
    break;

    case 0x2000:
        cpu.stack[cpu.sp] = cpu.pc;
        cpu.sp++;
        cpu.pc = nnn;
    break;

    case 0x3000:
        if(cpu.V[x] == nn){
            cpu.pc += 2;
        }
    cpu.pc += 2;
    break;

    case 0x6000:
        cpu.V[x] = nn;
        cpu.pc += 2;
        break;

    case 0x7000:
        cpu.V[x] = (cpu.V[x] += nn) & 0xFF;
    cpu.pc += 2;
    break;

    case 0x8000:
        cpu.V[x] = cpu.V[y];
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
        printf("x : ");
        printf("%d\n", x);
        printf("y : ");
        printf("%d\n", y);
        SDL_Flip(screen);
        SDL_Delay(100);
    cpu.pc += 2;
    break;

    case 0xF000:
        switch(cpu.opcode & nn){

        case 0x0029:
            cpu.I = cpu.V[x] * 5;
            printf("cpu.I : ");
            printf("%d\n", cpu.I);
        cpu.pc += 2;
        break;

        case 0x0033:
            cpu.memory[cpu.I]     =  cpu.V[(cpu.opcode & 0x0F00) >> 8] / 100;
            cpu.memory[cpu.I + 1] = (cpu.V[(cpu.opcode & 0x0F00) >> 8] / 10) % 10;
            cpu.memory[cpu.I + 2] = (cpu.V[(cpu.opcode & 0x0F00) >> 8] % 100) % 10;
        cpu.pc += 2;
        break;

        case 0x0065:
            for (int i = 0; i < x; i++){
                cpu.V[i] = cpu.memory[cpu.I + i];
            }
        cpu.pc += 2;
        break;

        default:
            printf("opcode 0xF0?? is not implemented\n");
        }
    break;

    default:
            printf("opcode not implemented\n");
        cpu.running = 0;
    break;
    }
}
