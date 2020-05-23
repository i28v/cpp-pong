#include "Paddle.hpp"


Paddle::~Paddle()
{

}

void Paddle::update() 
{
    destR.x = xpos;
    destR.y = ypos;
}
