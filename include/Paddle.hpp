#ifndef PADDLE_INCLUDED
#define PADDLE_INCLUDED

#include "Sprite.hpp"

class Paddle : public Sprite
{
public:
    using Sprite::Sprite;
    virtual ~Paddle();
    void update();
private:
};


#endif /* PADDLE_INCLUDED */
