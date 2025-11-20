//#include"..\Entity\Entity.h"
#include <SFML/Graphics.hpp>
class Game {
public:
	void run();
	Game();
	~Game();
private:
	bool wPressed, sPressed, dPressed, aPressed;
	//std::vector<Entity*> entities;


};