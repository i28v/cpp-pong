#ifndef GAME_INCLUDED
#define GAME_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <stdint.h>
#include "Sprite.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "CollisionManager.hpp"

class Game
{
public:
    Game();
    virtual ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
private:
    uint64_t updateCycleCount = 0;
    bool isRunning = false;
    CollisionManager* collisionManager = nullptr;
    SDL_Window* window = nullptr;
    SDL_Renderer *renderer = nullptr;
    Sprite* background = nullptr;
    Paddle* paddle = nullptr;
    Ball* ball = nullptr;
};

#endif /* GAME_INCLUDED */
