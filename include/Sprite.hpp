#ifndef SPRITE_INCLUDED
#define SPRITE_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class Sprite
{
public:

    Sprite(const char* fileloc, int x, int y, int w, int h, SDL_Renderer** renderer);
    virtual ~Sprite();
    virtual void update(); 
    void drawTo(SDL_Renderer** renderer);
    int xpos = 0;
    int ypos = 0;
    SDL_Rect getRect();
    SDL_Texture* spriteTex = nullptr;
    SDL_Rect srcR, destR;
private:

};

#endif /* SPRITE_INCLUDED */
