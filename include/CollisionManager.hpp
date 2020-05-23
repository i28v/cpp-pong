#ifndef COLLISIONMANAGER_INCLUDED
#define COLLISIONMANAGER_INCLUDED

#include <SDL2/SDL.h>

class CollisionManager 
{
public:
    CollisionManager();
    virtual ~CollisionManager();
    bool checkCollision(SDL_Rect A, SDL_Rect B);
private:
    int leftA, leftB, rightA, rightB, topA, topB, bottomA, bottomB;
};

#endif /* COLLISIONMANAGER_INCLUDED */
