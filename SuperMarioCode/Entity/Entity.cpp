#include"Entity.h"

Entity::Entity()
{
	pos = sf::FloatRect();
}


Entity::~Entity()
{

}



void Entity::setVelo(sf::FloatRect newVelo)
{
	velo = newVelo;
}


void Entity::setPos(sf::FloatRect newPos)
{
	pos = newPos;
}
