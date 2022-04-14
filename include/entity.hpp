#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
// TODO installer la librairie en local comme ça on est tranquille !!!!!!
#include <iostream>
#include <math.h>
#include "tools.hpp"

class Entity : public sf::Sprite
{
    public:
        // Sprite constructor
        Entity();
        void setVelocity(double velocity);
        double getVelocity();
        void setSize(unsigned int size);
        unsigned int getSize();

        bool isCollision(Entity entity);
        void collisions(Entity* entity);

    private :
        double velocity;
        unsigned int size;
};

#endif
