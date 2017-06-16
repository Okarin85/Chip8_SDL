#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL/SDL.h>
#include "cpu.cpp"
#include "gfx.cpp"
#include "opcode.cpp"

int main ( int argc, char** argv )
{
    initialiseCpu();
    initialiseScreen();

    FILE *game = NULL;
    game = fopen("11768","rb");
    fread(&cpu.memory[512], sizeof(unsigned char) * (4096 - 512), 1, game);
    fclose(game);

    while(cpu.running){
        for(int i = 0; i < 4; i++){
        executeOpcode();
        }
        cpu.delayTimer--;
    }

    SDL_Quit();
    return 0;
}
