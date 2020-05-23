#ifndef BALL_INCLUDED
#define BALL_INCLUDED

#include <stdint.h>
#include "Sprite.hpp"

#define NORTH 0b00000001
#define SOUTH 0b00000010
#define EAST  0b00000100
#define WEST  0b00001000


class Ball : public Sprite
{
public:
    using Sprite::Sprite;
    virtual ~Ball();
    void update();
    void setDirection(uint8_t value);
    uint8_t getDirection();
private:
    uint8_t direction;
};

#endif /* BALL_INCLUDED */
