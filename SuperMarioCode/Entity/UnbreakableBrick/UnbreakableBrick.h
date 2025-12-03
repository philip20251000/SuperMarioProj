#include"../Entity.h"
#pragma once

class UnbreakableBrick : public Entity
{
public:
	UnbreakableBrick(sf::Vector2f pos);
	~UnbreakableBrick();
private:
	enum FrameType
	{
	};
	std::unordered_map<FrameType, Animations*> frames;
};