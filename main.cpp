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
    game = fopen("BRIX","rb");
    fread(&cpu.memory[512], sizeof(unsigned char) * (4096 - 512), 1, game);
    fclose(game);

    while(cpu.running){
        executeOpcode();
    }

    SDL_Quit();
    return 0;
}
