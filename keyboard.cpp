#include "keyboard.h"
#include "opcode.h"

void inputFetch(){

        while(SDL_PollEvent(&event))
            switch(event.type)
            {
                case SDL_QUIT:
                    cpu.running = 0;
                break;

                case SDL_KEYDOWN:

                    switch(event.key.keysym.sym){

                        case SDLK_1:
                            //cpu.V[x] = 0x1;
                            key[0] = 1;
                        break;

                        case SDLK_2:
                            //cpu.V[x] = 0x2;
                            key[1] = 1;
                        break;

                        case SDLK_3:
                            //cpu.V[x] = 0x3;
                            key[2] = 1;
                        break;

                        case SDLK_4:
                            //cpu.V[x] = 0xC;
                            key[3] = 1;
                        break;

                        case SDLK_a:
                            //cpu.V[x] = 0x4;
                            key[4] = 1;
                        break;

                        case SDLK_z:
                            //cpu.V[x] = 0x5;
                            key[5] = 1;
                        break;

                        case SDLK_e:
                            //cpu.V[x] = 0x6;
                            key[6] = 1;
                        break;

                        case SDLK_r:
                            //cpu.V[x] = 0xD;
                            key[7] = 1;
                        break;

                        case SDLK_q:
                            //cpu.V[x] = 0x7;
                            key[8] = 1;
                        break;

                        case SDLK_s:
                            //cpu.V[x] = 0x8;
                            key[9] = 1;
                        break;

                        case SDLK_d:
                            //cpu.V[x] = 0x9;
                            key[10] = 1;
                        break;

                        case SDLK_f:
                            //cpu.V[x] = 0xE;
                            key[11] = 1;
                        break;

                        case SDLK_w:
                            //cpu.V[x] = 0xA;
                            key[12] = 1;
                        break;

                        case SDLK_x:
                            //cpu.V[x] = 0x0;
                            key[13] = 1;
                        break;

                        case SDLK_c:
                            //cpu.V[x] = 0xB;
                            key[14] = 1;
                        break;

                        case SDLK_v:
                            //cpu.V[x] = 0xF;
                            key[15] = 1;
                        break;

                        default:
                            printf("Key not implemented\n");
                        break;
                    }
                break;


            default:
                printf("Unrecognized input\n");
            break;

            case SDL_KEYUP:{
                switch(event.key.keysym.sym){

                        case SDLK_1:
                            //cpu.V[x] = 0x1;
                            key[0] = 0;
                        break;

                        case SDLK_2:
                            //cpu.V[x] = 0x2;
                            key[1] = 0;
                        break;

                        case SDLK_3:
                            //cpu.V[x] = 0x3;
                            key[2] = 0;
                        break;

                        case SDLK_4:
                            //cpu.V[x] = 0xC;
                            key[3] = 0;
                        break;

                        case SDLK_a:
                            //cpu.V[x] = 0x4;
                            key[4] = 0;
                        break;

                        case SDLK_z:
                            //cpu.V[x] = 0x5;
                            key[5] = 0;
                        break;

                        case SDLK_e:
                            //cpu.V[x] = 0x6;
                            key[6] = 0;
                        break;

                        case SDLK_r:
                            //cpu.V[x] = 0xD;
                            key[7] = 0;
                        break;

                        case SDLK_q:
                            //cpu.V[x] = 0x7;
                            key[8] = 0;
                        break;

                        case SDLK_s:
                            //cpu.V[x] = 0x8;
                            key[9] = 0;
                        break;

                        case SDLK_d:
                            //cpu.V[x] = 0x9;
                            key[10] = 0;
                        break;

                        case SDLK_f:
                            //cpu.V[x] = 0xE;
                            key[11] = 0;
                        break;

                        case SDLK_w:
                            //cpu.V[x] = 0xA;
                            key[12] = 0;
                        break;

                        case SDLK_x:
                            //cpu.V[x] = 0x0;
                            key[13] = 0;
                        break;

                        case SDLK_c:
                            //cpu.V[x] = 0xB;
                            key[14] = 0;
                        break;

                        case SDLK_v:
                            //cpu.V[x] = 0xF;
                            key[15] = 0;
                        break;

                        default:
                            printf("Key not implemented\n");
                        break;
                    }
                break;

                }


    }
}

void waitInput(){

        while(SDL_WaitEvent(&event))
            switch(event.type)
            {
                case SDL_QUIT:
                    cpu.running = 0;
                break;

                case SDL_KEYDOWN:

                    switch(event.key.keysym.sym){

                        case SDLK_1:
                            //cpu.V[x] = 0x1;
                            key[0] = 1;
                        break;

                        case SDLK_2:
                            //cpu.V[x] = 0x2;
                            key[1] = 1;
                        break;

                        case SDLK_3:
                            //cpu.V[x] = 0x3;
                            key[2] = 1;
                        break;

                        case SDLK_4:
                            //cpu.V[x] = 0xC;
                            key[3] = 1;
                        break;

                        case SDLK_a:
                            //cpu.V[x] = 0x4;
                            key[4] = 1;
                        break;

                        case SDLK_z:
                            //cpu.V[x] = 0x5;
                            key[5] = 1;
                        break;

                        case SDLK_e:
                            //cpu.V[x] = 0x6;
                            key[6] = 1;
                        break;

                        case SDLK_r:
                            //cpu.V[x] = 0xD;
                            key[7] = 1;
                        break;

                        case SDLK_q:
                            //cpu.V[x] = 0x7;
                            key[8] = 1;
                        break;

                        case SDLK_s:
                            //cpu.V[x] = 0x8;
                            key[9] = 1;
                        break;

                        case SDLK_d:
                            //cpu.V[x] = 0x9;
                            key[10] = 1;
                        break;

                        case SDLK_f:
                            //cpu.V[x] = 0xE;
                            key[11] = 1;
                        break;

                        case SDLK_w:
                            //cpu.V[x] = 0xA;
                            key[12] = 1;
                        break;

                        case SDLK_x:
                            //cpu.V[x] = 0x0;
                            key[13] = 1;
                        break;

                        case SDLK_c:
                            //cpu.V[x] = 0xB;
                            key[14] = 1;
                        break;

                        case SDLK_v:
                            //cpu.V[x] = 0xF;
                            key[15] = 1;
                        break;

                        default:
                            printf("Key not implemented\n");
                        break;
                    }
                break;


            default:
                printf("Unrecognized input\n");
            break;

            case SDL_KEYUP:{
                switch(event.key.keysym.sym){

                        case SDLK_1:
                            //cpu.V[x] = 0x1;
                            key[0] = 0;
                        break;

                        case SDLK_2:
                            //cpu.V[x] = 0x2;
                            key[1] = 0;
                        break;

                        case SDLK_3:
                            //cpu.V[x] = 0x3;
                            key[2] = 0;
                        break;

                        case SDLK_4:
                            //cpu.V[x] = 0xC;
                            key[3] = 0;
                        break;

                        case SDLK_a:
                            //cpu.V[x] = 0x4;
                            key[4] = 0;
                        break;

                        case SDLK_z:
                            //cpu.V[x] = 0x5;
                            key[5] = 0;
                        break;

                        case SDLK_e:
                            //cpu.V[x] = 0x6;
                            key[6] = 0;
                        break;

                        case SDLK_r:
                            //cpu.V[x] = 0xD;
                            key[7] = 0;
                        break;

                        case SDLK_q:
                            //cpu.V[x] = 0x7;
                            key[8] = 0;
                        break;

                        case SDLK_s:
                            //cpu.V[x] = 0x8;
                            key[9] = 0;
                        break;

                        case SDLK_d:
                            //cpu.V[x] = 0x9;
                            key[10] = 0;
                        break;

                        case SDLK_f:
                            //cpu.V[x] = 0xE;
                            key[11] = 0;
                        break;

                        case SDLK_w:
                            //cpu.V[x] = 0xA;
                            key[12] = 0;
                        break;

                        case SDLK_x:
                            //cpu.V[x] = 0x0;
                            key[13] = 0;
                        break;

                        case SDLK_c:
                            //cpu.V[x] = 0xB;
                            key[14] = 0;
                        break;

                        case SDLK_v:
                            //cpu.V[x] = 0xF;
                            key[15] = 0;
                        break;

                        default:
                            printf("Key not implemented\n");
                        break;
                    }
                break;

                }


    }
}
