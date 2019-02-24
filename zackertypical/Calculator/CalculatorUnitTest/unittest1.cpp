#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Calculator/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3+10+4-16");
			Assert::AreEqual(ret, (string)"3+10+4-16=1");
			ret =  calc->Solve("11*15-5");
			Assert::AreEqual(ret, (string)"11*15-5=160");
		}

	};
}