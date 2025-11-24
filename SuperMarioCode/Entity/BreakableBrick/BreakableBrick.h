#include"..\Entity.h"
#include"..\Coin\Coin.h"
#include"..\Goomba\Goomba.h"
#pragma once

class BreakableBrick : public Entity
{
public:
	BreakableBrick(bool mystery, bool coin);
	~BreakableBrick();
	Coin spawnCoin();
	Goomba spawnMushroom();
	void update() override;
	void collide(Entity*) override;
	void death() override;
private:
	bool mystery;
	bool hasCoin;
	bool hasMushroom;
};