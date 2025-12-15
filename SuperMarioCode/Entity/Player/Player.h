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
	bool changingBackground = false;
	enum FrameType
	{
		STAND_LEFT,
		STAND_RIGHT,
		WALK_LEFT,
		WALK_RIGHT,
		JUMP_LEFT,
		JUMP_RIGHT,
		JUMP,
		CROUCH_IN_TUBE,
		CROUCH,
		DYING
	};
	void setFrame(FrameType x) { curMove = x; }
	FrameType getFrame() { return curMove; }
	Player(sf::View*);
	~Player();
private:
	FrameType curMove = STAND_RIGHT;
	std::unordered_map<FrameType, Animations*> frames;
	sf::View* viewport = nullptr;
	bool superSize = false;
	double scale;
	void grow();
	void shrink();
};