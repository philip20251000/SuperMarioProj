#include <SFML/Graphics.hpp>
#pragma once
class Animations
{
public:
	sf::IntRect nextFrame();
	sf::IntRect getFrame(int frame);
	Animations(sf::IntRect* zone, bool rightToLeft, int frameVertical, int frameHorizontal);
	~Animations();
private:
	sf::IntRect* zone;
	bool rightToLeft;
	int frames;
};