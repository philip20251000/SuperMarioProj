#include"BreakableBrick.h"

BreakableBrick::BreakableBrick(bool mystery, bool coin)
{

}


BreakableBrick::~BreakableBrick()
{

}


Coin BreakableBrick::spawnCoin()
{
	Coin spawned;
	return spawned;
}


Goomba BreakableBrick::spawnMushroom()
{
	Goomba spawned(100,true);
	return spawned;
}


void BreakableBrick::update()
{

}


void BreakableBrick::collide(Entity*)
{

}


void BreakableBrick::death()
{

}