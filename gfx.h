#ifndef GFX_H_INCLUDED
#define GFX_H_INCLUDED

    SDL_Surface *screen = NULL;
    SDL_Surface *pixels[64][32] = {NULL};
    int xorPixels[64][32];
    SDL_Rect pos;

#endif // GFX_H_INCLUDED
