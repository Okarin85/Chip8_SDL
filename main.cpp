#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "cpu.cpp"
#include "gfx.cpp"
#include "keyboard.cpp"
#include "opcode.cpp"


int main ( int argc, char** argv )
{
    initialiseCpu();
    initialiseScreen();

    FILE *game = NULL;
    game = fopen("TETRIS","rb");
    fread(&cpu.memory[512], sizeof(unsigned char) * (4096 - 512), 1, game);
    fclose(game);

    while(cpu.running){
        executeOpcode();
        if(cpu.delayTimer > 0){
        cpu.delayTimer--;
        }
        if(cpu.soundTimer > 0){
        cpu.soundTimer--;
        }
        SDL_Delay(4);
    }

    SDL_Quit();
    return 0;
}
