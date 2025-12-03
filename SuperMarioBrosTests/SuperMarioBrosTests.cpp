#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"
#include"..\SuperMarioCode\Entity\Goomba\Goomba.h"
#include"..\SuperMarioCode\Entity\Player\Player.h"
#include<vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SuperMarioBrosTests
{
	TEST_CLASS(SuperMarioBrosTests)
	{
	public:
		
		TEST_METHOD(CoinValue)
		{
			Coin* test = new Coin();
			Assert::AreEqual(100, test->getValue());
		}
		TEST_METHOD(CoinUpdate)
		{

		}
		TEST_METHOD(CoinCollide)
		{

		}
		TEST_METHOD(CoinDeathPoints)
		{

		}
		TEST_METHOD(CoinDeathDecon)
		{
			Coin* test = new Coin();
			test->death();
		}
		TEST_METHOD(EntityVector)
		{
			sf::View* viewport = new sf::View();
			Coin* test = new Coin();
			Goomba* test2 = new Goomba(100,false);
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
			//if(!)
		}
	};
}
