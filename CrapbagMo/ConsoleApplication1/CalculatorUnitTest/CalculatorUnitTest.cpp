#include "pch.h"
#include "../ConsoleApplication1/Calculator.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest
{
	TEST_CLASS(CalculatorUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
			ret = calc->Solve("22+22");
			Assert::AreEqual(ret, (string)"22+22=44");
		}

		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-22");
			Assert::AreEqual(ret, (string)"22-22=0");
			ret = calc->Solve("10-20");
			Assert::AreEqual(ret, (string)"10-20=-10");
		}

		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3*2");
			Assert::AreEqual(ret, (string)"3*2=6");
			ret = calc->Solve("5*6");
			Assert::AreEqual(ret, (string)"5*6=30");
		}

		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22/22");
			Assert::AreEqual(ret, (string)"22/22=1");
			ret = calc->Solve("20/10");
			Assert::AreEqual(ret, (string)"20/10=2");
		}
	};
}
