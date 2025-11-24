#include "pch.h"
#include "CppUnitTest.h"
#include"..\SuperMarioCode\Entity\Coin\Coin.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SuperMarioBrosTests
{
	TEST_CLASS(SuperMarioBrosTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Coin* test = new Coin();
			Assert::AreEqual(100, test->getValue());
		}
	};
}
