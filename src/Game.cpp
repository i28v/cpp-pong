#include "Game.hpp"

Game::Game()
{

}
Game::~Game()
{
    
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen == true)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }
        isRunning = true;
    } 
    else 
    {
        isRunning = false;
    }
    collisionManager = new CollisionManager();
    background = new Sprite("assets/background.png", 0, 0, 640, 480, &renderer);
    paddle = new Paddle("assets/player.png", 64, 440, 64, 16, &renderer);
    ball = new Ball("assets/ball.png", 64, 256, 16, 16, &renderer);
    ball->setDirection(SOUTH | EAST);
}

void Game::handleEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        default:
            break;
    }
}

void Game::update()
{
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if(keystates[SDL_SCANCODE_LEFT] && paddle->xpos > 4)
    {
        paddle->xpos -= 10;
    }
    if(keystates[SDL_SCANCODE_RIGHT] && paddle->xpos < (640 - 68)) 
    {
        paddle->xpos += 10;
    }
    paddle->update();
    ball->update();
    if(collisionManager->checkCollision(paddle->getRect(), ball->getRect()))
    {
        if((ball->getDirection() & SOUTH) != 0)
        {
            ball->setDirection((ball->getDirection() ^ SOUTH) | NORTH);
        }
    }
    if(ball->xpos > (630 - 10) && (ball->getDirection() & EAST) != 0)
    {
        ball->setDirection((ball->getDirection() ^ EAST) | WEST);
    }
    else if(ball->xpos < 10 && (ball->getDirection() & WEST) != 0)
    {
        ball->setDirection((ball->getDirection() ^ WEST) | EAST);
    }
    if(ball->ypos < 4 && (ball->getDirection() & NORTH) != 0)
    {
        ball->setDirection((ball->getDirection() ^ NORTH) | SOUTH);
    }
    updateCycleCount++;
    // std::cout << updateCycleCount << std::endl;
}

void Game::render()
{
    SDL_RenderClear(renderer);
    background->drawTo(&renderer);
    paddle->drawTo(&renderer);
    ball->drawTo(&renderer);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    delete collisionManager;
    delete paddle;
    delete ball;
    delete background;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);  
    SDL_Quit();
}

bool Game::running()
{
    return isRunning;
}
