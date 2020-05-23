#include "Sprite.hpp"

Sprite::Sprite(const char* fileloc, int x, int y, int w, int h, SDL_Renderer** renderer)
{
    SDL_Surface* surfaceLoader = IMG_Load(fileloc);
    spriteTex = SDL_CreateTextureFromSurface(*renderer, surfaceLoader);
    SDL_FreeSurface(surfaceLoader);
    destR.h = h;
    destR.w = w;
    destR.x = x;
    destR.y = y;
    xpos = x;
    ypos = y;
}

Sprite::~Sprite()
{
    SDL_DestroyTexture(spriteTex);
}


void Sprite::update()
{
    destR.x = xpos;
    destR.y = ypos;
}

void Sprite::drawTo(SDL_Renderer** renderer)
{
    SDL_RenderCopy(*renderer, spriteTex, NULL, &destR);
}

SDL_Rect Sprite::getRect()
{
    return destR;
}
