#include "stdafx.h"
#include "CppUnitTest.h"
#include"Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CalculatorUnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("11+22");
			Assert::AreEqual(ret, (string)"11+22=33");
			//Calculator* calc2 = new Calculator();
			//string ret2 = calc2->Solve("7*20");
			//Assert::AreEqual(ret2, (string)"7*20=140");
		}

	};
}