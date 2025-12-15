#include <SFML/Graphics.hpp>
#include<unordered_map>
#include<vector>
#include"..\Animations\Animations.h"
#pragma once
class Entity
{
public:
	virtual void update() = 0;
	virtual void collide(Entity*) = 0;
	virtual void death() = 0;
	std::vector<Entity*> getEntities() { return entities; }
	Entity();
	~Entity();
	void setVelo(sf::FloatRect);
	sf::FloatRect getVelo() { return velo; }
	sf::FloatRect getPos() { return pos; }
	void setPos(sf::FloatRect);
	const sf::Sprite* getSprite() { return sprite; }
	std::vector<sf::FloatRect> getGrounds() { return grounds; }
	unsigned int getTick() { return tick; }

protected:
	sf::Texture* texture = nullptr;
	std::vector<Entity*> entities;
	sf::FloatRect pos;
	sf::FloatRect velo;
	const sf::Sprite* sprite = nullptr;
	std::vector<sf::FloatRect> grounds;
	std::vector<sf::FloatRect> grounds2;
	std::vector<sf::FloatRect> walls;
	bool shouldUpdate;
	unsigned int tick = 0;
};