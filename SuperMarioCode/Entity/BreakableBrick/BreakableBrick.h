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
	bool getMystery() { return mystery; };
	bool getCoin() { return hasCoin; };
private:
	bool mystery;
	bool hasCoin;
	bool hasMushroom;
	enum FrameType
	{
	};
	std::unordered_map<FrameType, Animations*> frames;
};