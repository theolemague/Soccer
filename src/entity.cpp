#include "entity.hpp"

Entity::Entity()
{
}

void Entity::setVelocity(double velocity)
{
    this->velocity = velocity;
}

double Entity::getVelocity()
{
    return this->velocity;
}

void Entity::setSize(unsigned int size)
{
    this->size = size;
}
unsigned int Entity::getSize()
{
    return this->size;
}


bool Entity::isCollision(Entity entity)
{
    sf::Vector2f pos1 = this->getPosition();
    sf::Vector2f pos2 = entity.getPosition();

    double distance = sqrt(pow(abs(pos1.x - pos2.x),2) + pow(abs(pos1.y - pos2.y), 2));
    return distance < (this->size/2 + entity.getSize()/2);
}

void Entity::collisions(Entity* entity)
{
    // ball->setRotation(this->getRotation());
    // ball->setVelocity(this->getVelocity() * PLAYER_POWER);


    sf::Vector2f pos1 = entity->getPosition();
    sf::Vector2f pos2 = this->getPosition();

    double b1 = toRad(entity->getRotation());
    double a1 = atan2(pos2.y - pos1.y, pos2.x - pos1.x);
    double g1 = b1 - a1;
    double u12 = entity->getVelocity()* sin(g1);
    double u11 = entity->getVelocity()* cos(g1);

    // std::cout << "a1 " <<a1 << ", b1 " <<b1 << ", c1 " <<g1<<std::endl;
    // std::cout << "u11 " <<u12 <<", u12 " <<u12 << std::endl;

    double b2 = toRad(this->getRotation());
    double a2 = atan2(pos1.y - pos2.y, pos1.x - pos2.x);
    double g2 = b2 - a2;
    double u21 = this->getVelocity()* cos(g2);
    double u22 = this->getVelocity()* sin(g2);

    // std::cout << "a2 " <<a2 << ", b2 " <<b2 << ", c2 " <<g2<<std::endl;
    // std::cout << "u21 " <<u21 << ", u22 " <<u22 <<std::endl;

    int m1 = 1, m2=10;
    double v12 = -((m1 - m2)*u12 + 2*m2*u21)/(m2+m1);
    double v21 = -((m2 - m1)*u21 + 2*m1*u12)/(m2+m1);
    // std::cout << "v12 " <<v12 << ", v21 " <<v21 <<std::endl;

    double v1x =-sin(a1)*u11 + cos(a1)*v12;
    double v1y = cos(a1)*u11 + sin(a1)*v12;

    // std::cout << "v1x " <<v1x << ", v1y " <<v1y <<std::endl;

    double v2x =-sin(a2)*u22 - cos(a2)*v21;
    double v2y = cos(a2)*u22 - sin(a2)*v21;

    // std::cout << "v2x " <<v2x << ", v2y " <<v2y <<std::endl;
    entity->setRotation(toDegrees(atan2(v1y,v1x)));
    this->setRotation(toDegrees(atan2(v2y,v2x)));

    entity->setVelocity(sqrt(pow(v1x,2) + pow(v1y,2)));
    this->setVelocity(sqrt(pow(v2x,2) + pow(v2y,2)));

    std::cout << "Player speed " << this->getVelocity() << " rotation " <<this->getRotation() <<std::endl;
    std::cout << "Ball speed " << entity->getVelocity() << " rotation " <<entity->getRotation() <<std::endl;
    


}