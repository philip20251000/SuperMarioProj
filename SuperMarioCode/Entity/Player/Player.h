#include <SFML/Graphics.hpp>
#include"..\Entity.h"
#pragma once
class Player : public Entity
{
public:
	void update() override;
	void collide(Entity*) override;
	void death() override;
	void setSuper(bool super) { superSize = super; }
	Player(sf::View*);
	~Player();
private:
	sf::View* viewport = nullptr;
	bool superSize = false;
};