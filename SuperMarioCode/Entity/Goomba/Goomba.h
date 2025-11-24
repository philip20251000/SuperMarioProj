#include"..\Entity.h"
#pragma once

class Goomba : public Entity
{
public:
	Goomba(int pointValue, bool isMushroom);
	~Goomba();
	void update() override;
	void collide(Entity*) override;
	void death() override;
	int getValue();
	bool getIsMushroom();
private:
	int pointValue;
	bool isMushroom;
};