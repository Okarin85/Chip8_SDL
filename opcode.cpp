#include "opcode.h"

void executeOpcode(){
cpu.opcode = (cpu.memory[cpu.pc] << 8) + cpu.memory[cpu.pc + 1];

x    = (cpu.opcode & 0x0F00) >> 8;
y    = (cpu.opcode & 0x00F0) >> 4;
n    =  cpu.opcode & 0x000F;
nn   =  cpu.opcode & 0x00FF;
nnn  =  cpu.opcode & 0x0FFF;
/*
printf("opcode : ");
printf("%04x\n", cpu.opcode);
printf("pc : ");
printf("%04x\n", cpu.pc);
printf("I : ");
printf("%04x\n", cpu.I);
printf("DealyTimer : ");
printf("%04x\n", cpu.delayTimer);
printf("y : ");
printf("%04x\n", y);
printf("x : ");
printf("%04x\n", x);
printf("\n");

for(int i = 0; i < 16; i++){
    printf("cpu.V");
    printf("%01x", i);
    printf(" : ");
    printf("%02x\n", cpu.V[i]);
}
printf("\n");
*/
switch(cpu.opcode & 0xF000){

    case 0x0000:
        switch (cpu.opcode & nn) {
            case 0x0000:
                printf("The opdcode 0x0000 hasn't been implemented yet\n");
            cpu.pc += 2;
            break;

            case 0x00E0:
                resetScreen();
            cpu.pc += 2;
            break;

            case 0x00EE:
                cpu.sp--;
                cpu.pc = cpu.stack[cpu.sp];
            cpu.pc += 2;
            break;
        }
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

    case 0x4000:
        if(cpu.V[x] != nn){
            cpu.pc += 2;
        }
    cpu.pc += 2;
    break;

    case 0x5000:
        if(cpu.V[x] == cpu.V[y]){
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
        switch(cpu.opcode & n){

        case 0x0000:
            cpu.V[x] = cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0001:
            cpu.V[x] = cpu.V[x] | cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0002:
            cpu.V[x] = cpu.V[x] & cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0003:
            cpu.V[x] = cpu.V[x] ^ cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0004:
             if(cpu.V[x] >= 255){
             cpu.V[15] = 1;
             }
             else{
                cpu.V[15] = 0;
             }
             cpu.V[x] += cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0005:
             if(cpu.V[x] > cpu.V[y]){
             cpu.V[15] = 1;
             }
             else{
                cpu.V[15] = 0;
             }
             cpu.V[x] = cpu.V[x] - cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x0006:
            cpu.V[15] = (cpu.V[x] & 0x1);
            cpu.V[x] = (cpu.V[x] >> 1);
        cpu.pc += 2;
        break;

        case 0x0007:
            if(cpu.V[x] < cpu.V[y]){
                cpu.V[15] = 1;
            }
            else{
                cpu.V[15] = 0;
            }
            cpu.V[x] -= cpu.V[y];
        cpu.pc += 2;
        break;

        case 0x000E:
            cpu.V[15] = cpu.V[x] >> 7;
            cpu.V[x] = cpu.V[x] << 1;
        cpu.pc += 2;
        break;

        default:
            printf("opcode 0x800? hasn't been implemented yet\n");
        cpu.pc += 2;
        }
    break;

    case 0x9000:
        if(cpu.V[x] != cpu.V[y]){
            cpu.pc += 2;
        }
    cpu.pc += 2;
    break;

    case 0xA000:
        cpu.I = nnn;
    cpu.pc += 2;
    break;

    case 0xB000:
        cpu.pc = cpu.V[0] + nnn;
    break;

    case 0xC000:
        cpu.V[x] = (rand() & nn);
    cpu.pc += 2;
    break;

    case 0xD000:
        drawSprite(x, y, n);
        SDL_Flip(screen);
    cpu.pc += 2;
    break;

    case 0xE000:
        switch(cpu.opcode & nn){
        case 0x00A1:
            inputFetch();
            if (key[cpu.V[x]] == 0){
                cpu.pc += 2;
            }
        cpu.pc += 2;
        break;

        case 0x009E:
            inputFetch();
            if (key[cpu.V[x]] != 0){
                cpu.pc += 2;
            }
        cpu.pc += 2;
        break;

        default:
            printf("opcode 0xEx?? hasn't been implemented yet\n");
        cpu.pc += 2;
        break;
        }
    break;

    case 0xF000:
        switch(cpu.opcode & nn){

        case 0x0007:
            cpu.V[x] = cpu.delayTimer;
        cpu.pc += 2;
        break;

        case 0x000A:
            waitInput();
        cpu.pc += 2;
        break;

        case 0x0015:
            cpu.delayTimer = cpu.V[x];
        cpu.pc += 2;
        break;

        case 0x0018:
            printf("opcode that touch the soundtimer");
            cpu.soundTimer = cpu.V[x];
        cpu.pc += 2;
        break;

        case 0x001E:
            cpu.I += cpu.V[x];
        cpu.pc += 2;
        break;

        case 0x0029:
            cpu.I = cpu.V[x] * 5;
        cpu.pc += 2;
        break;

        case 0x0033:
            cpu.memory[cpu.I]     =  cpu.V[x] / 100;
            cpu.memory[cpu.I + 1] =  (cpu.V[x] / 10) % 10;
            cpu.memory[cpu.I + 2] =  (cpu.V[x] % 100) % 10;
        cpu.pc += 2;
        break;

        case 0x0055:
            for (int i = 0; i <= x; i++){
                cpu.memory[cpu.I + i] = cpu.V[i];
            }
        cpu.pc += 2;
        break;

        case 0x0065:
            for (int i = 0; i <= x; i++){
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
