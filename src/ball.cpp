#include "ball.hpp"

Ball::Ball(const char* imageFileName)
{
    
    
    sf::Texture texture;
    if (!texture.loadFromFile(imageFileName))
        std::cerr << "Error while loading image, check file name." << std::endl;

    texture.setSmooth(true);
    
    this->setTexture(texture);
    this->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    this->setSize(texture.getSize().x);
}

// void Ball::setVelocity(double velocity)
// {
//     this->velocity = velocity;
// }

// double Ball::getVelocity()
// {
//     return this->velocity;
// }

// unsigned int Ball::getSize()
// {
//     return this->size;
// }

void Ball::moveBall()
{
    sf::Vector2f positions = this->getPosition();
    float rotation = this->getRotation();
    double velocity = this->getVelocity();

    
    double x = positions.x + cos(toRad(rotation))*velocity;
    if (x<LIMIT_LEFT) {
        x = LIMIT_LEFT;
        this->setRotation(180 - rotation);
    }
    if (x>LIMIT_RIGHT) {
        x = LIMIT_RIGHT;
        this->setRotation(180 - rotation);
    }

    double y = positions.y + sin(toRad(rotation))*velocity;
    if (y<LIMIT_TOP) {
        y = LIMIT_LEFT;
        this->setRotation(360 - rotation);
    }
    if (y>LIMIT_BOTTOM) {
        y = LIMIT_BOTTOM;
        this->setRotation(360 - rotation);

    }
    velocity *= SPEED_COEF;
    this->setVelocity(velocity);
    this->setPosition(x, y);
}
