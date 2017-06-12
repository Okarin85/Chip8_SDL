#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>

typedef struct{
    unsigned char memory [4096] = {0};
    unsigned char V [16] = {0};
    unsigned short I = 0;
    unsigned short pc = 512;

    unsigned short opcode = 0;
}Cpu;

Cpu cpu;

int main ( int argc, char** argv )
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    SDL_Surface *screen = NULL;
    screen = SDL_SetVideoMode(640, 320, 32, SDL_HWSURFACE);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 127, 127, 127));

    SDL_Surface *pixels[64][32] = {NULL};
    SDL_Rect pos;

    FILE *game = NULL;
    game = fopen("MAZE","rb");
    fread(&cpu.memory[512], sizeof(unsigned char) * (4096 - 512), 1, game);
    fclose(game);

    for(int i = 0; i < 64; i++){
        for(int j = 0; j < 32; j++){
            pixels[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
            SDL_FillRect(pixels[i][j], NULL, SDL_MapRGB(screen->format, 255, 255, 255));
            pos.x = i * 10;
            pos.y = j * 10;
            SDL_BlitSurface(pixels[i][j], NULL, screen, &pos);
            SDL_Flip(screen);
        }
    }

    for(int i = 0; i < (4096 - 512); i++){
        cpu.opcode = (cpu.memory[cpu.pc] << 8) + cpu.memory[cpu.pc + 1];

        unsigned short x    = (cpu.opcode & 0x0F00) >> 8;
        unsigned short y    = (cpu.opcode & 0x00F0) >> 4;
        unsigned short n    =  cpu.opcode & 0x000F;
        unsigned short nn   =  cpu.opcode & 0x00FF;
        unsigned short nnn  =  cpu.opcode & 0x0FFF;

        printf("opcode : ");
        printf("%04x\n", cpu.opcode);

            switch(cpu.opcode & 0xF000){

                case 0x1000:
                    cpu.pc = nnn;
                break;

                case 0x3000:
                    if(cpu.V[x] == (nn)){
                        cpu.pc += 2;
                        printf("pc increased by 2\n");
                    }
                    else{
                        printf("pc not increased by 2\n");
                    }
                cpu.pc += 2;
                break;

                case 0x7000:
                    cpu.V[x] = (cpu.V[x] += nn) & 0xFF;
                cpu.pc += 2;
                break;

                case 0xA000:
                    cpu.I = nnn;
                    printf("I : ");
                    printf("%d\n", cpu.I);
                    cpu.pc += 2;
                break;

                case 0xC000:
                    cpu.V[x] = rand() & nn;
                    printf("V[x] : ");
                    printf("%d\n", cpu.V[x]);
                    cpu.pc += 2;
                break;

                case 0xD000:
                    for(int i = 0; i < n; i++){
                        unsigned char line = cpu.memory[cpu.I + i];
                        for(int j = 0; j < 8; j++){
                            unsigned char pixel = line & (0x80 >> j);
                            if(pixel != 0){
                                pixels[cpu.V[x] + j][cpu.V[y] + i] = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
                                SDL_FillRect(pixels[cpu.V[x] + j][cpu.V[y] + i], NULL, SDL_MapRGB(screen->format, 0, 0, 0));
                                pos.x = (cpu.V[x] + j) * 10;
                                pos.y = (cpu.V[y] + i) * 10;
                                SDL_BlitSurface(pixels[cpu.V[x] + j][cpu.V[y] + i], NULL, screen, &pos);
                            }
                        }
                    }
                SDL_Flip(screen);
                SDL_Delay(16 * 4);
                cpu.pc += 2;
                break;

                default:
                    printf("opcode not implemented\n");
                cpu.pc += 2;
                break;
            }
    }
    SDL_Quit();
    return 0;
}
