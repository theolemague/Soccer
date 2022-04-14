#ifndef SPRITE_H
#define SPRITE_H

#include "entity.hpp"

class Player : public Entity
{
    public:
        // Sprite constructor
        Player(const char* imageFileName);
        void movePlayer();
        void moveLeft();
        void moveRight();
        void accelerate();
        void slowDown();
        // bool isCollisionBall(Ball ball);
        // void kickBall(Ball* ball);
};

#endif // SPRITE_H
