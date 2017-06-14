#include "gfx.h"

void initialiseScreen(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    screen = SDL_SetVideoMode(640, 320, 32, SDL_HWSURFACE);
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 127, 127, 127));

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
}

void drawSprite(unsigned char x, unsigned char y, unsigned char n){
    for(int i = 0; i < n; i++){
        if(cpu.V[x] >= 64){
            cpu.V[x] = 0;
        }
        if(cpu.V[y] >= 32){
            cpu.V[y] = 0;
        }

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
}
