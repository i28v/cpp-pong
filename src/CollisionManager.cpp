#include "CollisionManager.hpp"

CollisionManager::CollisionManager()
{

}

CollisionManager::~CollisionManager()
{

}

bool CollisionManager::checkCollision(SDL_Rect A, SDL_Rect B)
{
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;
    if(bottomA <= topB)
    {
        return false;
    }
    if(topA >= bottomB)
    {
        return false;
    }
    if(rightA <= leftB)
    {
        return false;
    }
    if(leftA >= rightB)
    {
        return false;
    }
    return true;
}
