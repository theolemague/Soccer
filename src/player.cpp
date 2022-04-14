#include "player.hpp"

Player::Player(const char* imageFileName)
{
    
    
    sf::Texture texture;
    if (!texture.loadFromFile(imageFileName))
        std::cerr << "Error while loading image, check file name." << std::endl;

    texture.setSmooth(true);
    
    this->setTexture(texture);
    this->setOrigin(texture.getSize().x/2, texture.getSize().y/2);
    this->setSize(texture.getSize().x);
}

void Player::movePlayer()
{
    sf::Vector2f positions = this->getPosition();
    float rotation = this->getRotation();
    double velocity = this->getVelocity();
    
    double x = positions.x + cos(toRad(rotation))*velocity;
    if (x<LIMIT_LEFT) {
        x = LIMIT_LEFT;
        velocity = 0;
    }
    if (x>LIMIT_RIGHT) {
        x = LIMIT_RIGHT;
        velocity = 0;
    }
    double y = positions.y + sin(toRad(rotation))*velocity;
    if (y<LIMIT_TOP) {
        y = LIMIT_LEFT;
        velocity = 0;
    }
    if (y>LIMIT_BOTTOM) {
        y = LIMIT_BOTTOM;
        velocity = 0;
    }

    velocity *= SPEED_COEF;
    this->setVelocity(velocity);
    this->setPosition(x, y);
}

void Player::moveLeft()
{
    this->setRotation(this->getRotation() - ROTATION_STEP );
}

void Player::moveRight()
{
    this->setRotation(this->getRotation() + ROTATION_STEP );
}

void Player::accelerate()
{
    double velocity = this->getVelocity() + SPEED_STEP;
    this->setVelocity(velocity);
    if (velocity > SPEED_MAX) this->setVelocity(SPEED_MAX);
}

void Player::slowDown()
{
    double velocity = this->getVelocity() - SPEED_STEP;
    this->setVelocity(velocity);
    if (velocity < 0) this->setVelocity(0);
    
}
