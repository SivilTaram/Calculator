#include "pch.h"
#include "CppUnitTest.h"
#include "..\..\Calculator\Calculator\Calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorTest
{
	TEST_CLASS(CalculatorTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
		}
	};
}
