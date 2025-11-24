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


void Entity::setVelo(sf::Vector2f newVelo)
{
	velo = newVelo;
}


sf::Vector2f Entity::getVelo()
{
	return velo;
}


void Entity::setPos(sf::Vector2f newPos)
{
	pos = newPos;
}


sf::Vector2f Entity::getPos()
{
	return pos;
}

const sf::Sprite* Entity::getSprite()
{
	return sprite;
}