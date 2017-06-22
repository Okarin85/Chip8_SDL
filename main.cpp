#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include <SDL.h>
#include <SDL_mixer.h>

#include "cpu.cpp"
#include "gfx.cpp"
#include "keyboard.cpp"
#include "opcode.cpp"



int main ( int argc, char** argv )
{
    initialiseCpu();
    initialiseScreen();

    FILE *game = NULL;
    game = fopen("BRIX","rb");
    fread(&cpu.memory[512], sizeof(unsigned char) * (4096 - 512), 1, game);
    fclose(game);

    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    Mix_Chunk *beep;
    Mix_AllocateChannels(1);
    beep = Mix_LoadWAV("beep.wav");

    while(cpu.running){
        executeOpcode();
        if(cpu.delayTimer > 0){
        cpu.delayTimer--;
        }
        if(cpu.soundTimer > 0){
        printf("%d\n", cpu.soundTimer);
        Mix_PlayChannel(-1, beep, 0);
        cpu.soundTimer--;
        }
        SDL_Delay(4);
    }

    Mix_FreeChunk(beep);
    Mix_CloseAudio();
    SDL_Quit();
    return 0;
}
