#ifndef BALL_H
#define BALL_H

#include "entity.hpp"

class Ball : public Entity
{
    public:
        // Sprite constructor
        Ball(const char* imageFileName);
        void moveBall();
};

#endif
