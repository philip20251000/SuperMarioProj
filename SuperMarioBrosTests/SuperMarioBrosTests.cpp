#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"
#include"..\SuperMarioCode\Entity\Goomba\Goomba.h"
#include"..\SuperMarioCode\Entity\Player\Player.h"
#include"..\SuperMarioCode\Entity\BreakableBrick\BreakableBrick.h"
#include"..\SuperMarioCode\Entity\Entity.h"
#include<vector>
#include"..\SuperMarioCode\Game\Game.h"
#include"..\SuperMarioCode\Animations\Animations.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


TEST_CLASS(SuperMarioBrosTests)
{
public:

	TEST_METHOD(CoinValue)
	{
		Coin test;
		Assert::AreEqual(100, test.getValue());
	}
	TEST_METHOD(CoinDeathPoints)
	{
		Game* game = new Game();
		int x = game->getPoints();
		Coin test;
		test.death();
		int y = game->getPoints() - x;
		Assert::AreEqual(100, y);
		delete game;
	}
	TEST_METHOD(CoinDeathDecon)
	{
		Coin* test = new Coin();
		Assert::IsNotNull(test);
		int x = test->getEntities().size();
		test->death();
		int y = test->getEntities().size();
		Assert::AreEqual(x - y, 1);
		delete test;
	}
	TEST_METHOD(EntityVector)
	{
		sf::View* viewport = new sf::View();
		Coin* test = new Coin();
		Goomba* test2 = new Goomba(100, false);
		Player* test3 = new Player(viewport);
		std::vector<Entity*> entities = test->getEntities();
		test2->death();
		test3->death();
		Assert::AreEqual(1, (int)entities.size());
		Assert::IsNotNull(dynamic_cast<Coin*> (entities.at(0)));
		delete viewport;
		delete test;
		delete test2;
		delete test3;
	}
	TEST_METHOD(PlayerGroundCollision)
	{
		sf::View* viewport = new sf::View();
		Player* test = new Player(viewport);
		test->setFrame(Player::FrameType::CROUCH);
		test->update();
		test->setFrame(Player::FrameType::STAND_LEFT);
		test->update();
		test->setFrame(Player::FrameType::STAND_RIGHT);
		test->update();
		test->setFrame(Player::FrameType::WALK_LEFT);
		test->update();
		test->setFrame(Player::FrameType::WALK_RIGHT);
		Assert::IsNotNull(test->getSprite());
		for (int i = 0; i < test->getGrounds().size(); i++)
			Assert::IsTrue(test->getSprite()->getGlobalBounds().findIntersection(test->getGrounds().at(i)) == std::nullopt);
	}
	TEST_METHOD(TickUpdate)
	{
		sf::View* viewport = new sf::View();
		Player* test = new Player(viewport);
		test->setFrame(Player::FrameType::CROUCH);
		test->update();
		Assert::AreEqual(test->getTick(), (unsigned int)1);
		test->setFrame(Player::FrameType::STAND_LEFT);
		test->update();
		Assert::AreEqual(test->getTick(), (unsigned int)2);
		delete viewport;
		delete test;
	}
	TEST_METHOD(BBSpawned)
	{
		BreakableBrick brick(true, true);
		Assert::AreEqual(true, brick.getMystery());
		Assert::AreEqual(true, brick.getCoin());
	}
	TEST_METHOD(BBCoin)
	{
		BreakableBrick brick(false, true);
		Coin coin = brick.spawnCoin();
		Assert::AreEqual(100, coin.getValue());
	}
	TEST_METHOD(BBMushroom)
	{
		BreakableBrick brick(true, false);
		Goomba mushroom = brick.spawnMushroom();
		Assert::AreEqual(mushroom.getIsMushroom(), true);
		Assert::AreNotEqual(mushroom.getVelo().size.x, 0.f);
	}
	TEST_METHOD(BBdeath)
	{
		BreakableBrick brick(true, true);
		int y = brick.getEntities().size();
		brick.death();
		int x = brick.getEntities().size();
		Assert::AreEqual(y - x, 1);
	}
	TEST_METHOD(PlayerDeath)
	{
		sf::View* viewport = new sf::View();
		Player* test = new Player(viewport);
		Goomba* test2 = new Goomba(100,false);
		test->collide(test2);//when Player collide is called Goomba
		//is killing the Player
		Assert::AreEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		delete viewport;
		delete test;
		delete test2;
	}
	TEST_METHOD(GoombaDeath)
	{
		Game* game = new Game();
		sf::View* viewport = new sf::View();
		Player* test = new Player(viewport);
		Goomba* test2 = new Goomba(100, false);
		test2->collide(test);//when Goomba collide is called player
		//is killing the Goomba
		Assert::AreNotEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		Assert::AreEqual(game->bounceStreak, 1);
		test2->collide(test);
		Assert::AreNotEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		Assert::AreEqual(game->bounceStreak, 2);
		test->setFrame(Player::FrameType::WALK_LEFT);
		test2->collide(test);
		Assert::AreNotEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		Assert::AreEqual(game->bounceStreak, 1);
		delete game;
		delete viewport;
		delete test;
		delete test2;
	}
	TEST_METHOD(IsColliding)
	{
		Game* game = new Game();
		sf::View* viewport = new sf::View();
		Player* test = new Player(viewport);
		Goomba* test2 = new Goomba(100, false);
		int currentStreak = game->bounceStreak;
		(test->getSprite())->setPosition(sf::Vector2f(100.f, 100.f));
		(test2->getSprite())->setPosition(sf::Vector2f(100.f, 100.f));
		game->isColliding();
		int newStreak = game->bounceStreak;
		if (currentStreak == newStreak)
			Assert::AreEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		else if (currentStreak + 1 == newStreak)
			Assert::AreNotEqual((int)test->getFrame(), (int)Player::FrameType::DYING);
		else
			Assert::AreEqual(currentStreak + 1, newStreak);
		delete game;
		delete viewport;
		delete test;
		delete test2;
	}
	TEST_METHOD(AnimationTest)
	{
		sf::IntRect* testRect = new sf::IntRect();
		testRect->position = sf::Vector2i(0, 0);
		testRect->size = sf::Vector2i(100, 100);
		Animations* test = new Animations(testRect, false, 2, 2);
		//testing placement and size of boxes surronding sprites
		Assert::AreEqual(0, test->getFrame(0).position.x);
		Assert::AreEqual(50, test->getFrame(2).position.x);
		Assert::AreEqual(50, test->getFrame(1).size.x);
		Assert::AreEqual(50, test->getFrame(3).size.x);
		Assert::AreEqual(0, test->nextFrame().position.x);
		Assert::AreEqual(50, test->nextFrame().position.x);
		delete testRect;
		delete test;

	}
};
