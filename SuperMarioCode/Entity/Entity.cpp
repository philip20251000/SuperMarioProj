#include"Entity.h"

Entity::Entity()
{

}


Entity::~Entity()
{

}


std::vector<Entity*> Entity::getEntities()
{
	return entities;
}


void Entity::setVelo(sf::FloatRect newVelo)
{
	velo = newVelo;
}


sf::FloatRect Entity::getVelo()
{
	return velo;
}


void Entity::setPos(sf::FloatRect newPos)
{
	pos = newPos;
}


sf::FloatRect Entity::getPos()
{
	return pos;
}

const sf::Sprite* Entity::getSprite()
{
	return sprite;
}