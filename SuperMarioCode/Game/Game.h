#include"..\Entity\Entity.h"
#include <SFML/Graphics.hpp>

class SuperMarioBrosTests;

class Game {
public:
	void run();
	Game();
	~Game();
	int getPoints() { return points; };
	friend class SuperMarioBrosTests;
private:
	bool wPressed, sPressed, dPressed, aPressed;
	std::vector<Entity*> entities;
	unsigned int tick;
	sf::Texture* background;
	sf::View viewport;
	int bounceStreak = 0;
	void isColliding();
	int points=0;
};