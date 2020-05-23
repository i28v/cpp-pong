#include "Ball.hpp"

Ball::~Ball()
{

}

void Ball::update()
{
   destR.x = xpos;
   destR.y = ypos;
   if((direction & NORTH) != 0)
   {
       ypos -= 4;
   }
   if((direction & SOUTH) != 0)
   {
       ypos += 4;
   }
   if((direction & EAST) != 0)
   {
       xpos += 4;
   }
   if((direction & WEST) != 0)
   {
       xpos -= 4;
   }
}

void Ball::setDirection(uint8_t value)
{
    direction = value;
}

uint8_t Ball::getDirection()
{
    return direction;
}
