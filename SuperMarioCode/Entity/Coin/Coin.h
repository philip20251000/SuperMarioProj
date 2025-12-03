#include"..\Entity.h"
#pragma once
class Coin :public Entity
{
public:
	Coin();
	~Coin();
	int getValue();
	void update() override;
	void collide(Entity*) override;
	void death() override;
private:
	int pointValue;
	bool spawned;
	enum FrameType
	{
	};
	std::unordered_map<FrameType, Animations*> frames;
};