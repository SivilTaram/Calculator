#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculater/calculator.h"
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
		}
		TEST_METHOD(TestMethod2)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22-10");
			Assert::AreEqual(ret, (string)"22-10=12");
		}
		TEST_METHOD(TestMethod3)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22*10");
			Assert::AreEqual(ret, (string)"22*10=220");
		}
		TEST_METHOD(TestMethod4)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("22/11");
			Assert::AreEqual(ret, (string)"22/11=2");
		}
		TEST_METHOD(TestMethod5)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("3-2+1");
			Assert::AreEqual(ret, (string)"3-2+1=2");
		}
		TEST_METHOD(TestMethod6)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("100/10+3");
			Assert::AreEqual(ret, (string)"100/10+3=13");
		}
		TEST_METHOD(TestMethod7)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("100-10*2");
			Assert::AreEqual(ret, (string)"100-10*2=80");
		}
		TEST_METHOD(TestMethod8)
		{
			Calculator* calc = new Calculator();
			string ret = calc->Solve("100/10*2");
			Assert::AreEqual(ret, (string)"100/10*2=20");
		}
	};
}
