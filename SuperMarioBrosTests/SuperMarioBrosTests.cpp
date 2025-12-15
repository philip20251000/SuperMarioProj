#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"
#include"..\SuperMarioCode\Entity\Goomba\Goomba.h"
#include"..\SuperMarioCode\Entity\Player\Player.h"
#include"..\SuperMarioCode\Entity\BreakableBrick\BreakableBrick.h"
#include"..\SuperMarioCode\Entity\Entity.h"
#include<vector>
#include"..\SuperMarioCode\Game\Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SuperMarioBrosTests
{
	TEST_CLASS(SuperMarioBrosTests)
	{
	public:

		TEST_METHOD(CoinValue)
		{
			Coin test;
			Assert::AreEqual(100, test.getValue());
		}
		TEST_METHOD(CoinUpdate)
		{

		}
		TEST_METHOD(CoinCollide)
		{

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
		TEST_METHOD(BBupdate)
		{

		}
		TEST_METHOD(BBcollide)
		{

		}
		TEST_METHOD(BBdeath)
		{
			BreakableBrick brick(true, true);
			int y = brick.getEntities().size();
			brick.death();
			int x = brick.getEntities().size();
			Assert::AreEqual(y - x, 1);
		}
	};
}
