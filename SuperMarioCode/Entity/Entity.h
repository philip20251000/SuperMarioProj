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
	std::vector<Entity*> getEntities();
	Entity();
	~Entity();
	void setVelo(sf::Vector2f);
	sf::Vector2f getVelo();
	sf::Vector2f getPos();
	void setPos(sf::Vector2f);
	const sf::Sprite* getSprite();

protected:
	sf::Texture* texture = nullptr;
	std::vector<Entity*> entities;
	sf::Vector2f pos;
	sf::Vector2f velo;
	const sf::Sprite* sprite;
	std::vector<sf::Vector2f> grounds;
	std::vector<sf::Vector2f> grounds2;
	std::vector<sf::Vector2f> walls;
	bool shouldUpdate;
	enum FrameType
	{
	};
	std::unordered_map<FrameType, Animations*> frames;
	unsigned int tick = 0;
};