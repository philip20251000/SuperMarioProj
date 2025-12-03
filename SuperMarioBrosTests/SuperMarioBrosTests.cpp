#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"

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

		}
	};
}
