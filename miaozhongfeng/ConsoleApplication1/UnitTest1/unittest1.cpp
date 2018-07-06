#include "stdafx.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication1/Calculator.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
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
		}
		TEST_METHOD(TestMethod2)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("100+1+1");
			Assert::AreEqual(ret, (string)"100+1+1=102");
		}
		TEST_METHOD(TestMethod3)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("100+5");
			Assert::AreEqual(ret, (string)"100+5=105");
		}
		TEST_METHOD(TestMethod4)
		{
			// TODO: 在此输入测试代码
			Calculator* calc = new Calculator();
			string ret = calc->Solve("5+100");
			Assert::AreEqual(ret, (string)"5+100=105");
		}

	};
}