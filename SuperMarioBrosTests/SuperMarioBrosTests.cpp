#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"
#include"..\SuperMarioCode\Game\Game.h"


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
			Game* game = new Game();
			int x = game->getPoints();
			Coin test;
			test.death();
			int y = game->getPoints()-x;
			Assert::AreEqual(100, y);
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
	};
}
