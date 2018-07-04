// Calculator.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>  

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

class Calculator {
public:
	Calculator() {};
	string MakeFormula() {
		string formula = "";
		srand((unsigned int)time(NULL));
		int count = random(1, 3);
		int start = 0;
		int number1 = random(1, 100);
		formula += to_string(number1);
		while (start <= count) {
			int operation = random(0, 3);
			int number2 = random(1, 10);
			formula += op[operation] + to_string(number2);
			start++;
		}
		return formula;
	};

	string Solve(string formula) {
		vector<string>* tempStack = new vector<string>();
		stack<char>* operatorStack = new stack<char>();
		int len = formula.length();
		int k = 0;
		for (int j = -1; j < len - 1; j++) {
			char formulaChar = formula[j + 1]; //取出后一个字符
			if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
				formulaChar == '*' || formulaChar == '/') { //是最后一个字符或者是加减乘除
				if (j == len - 2) {
					tempStack->push_back(formula.substr(k));
				}
				else {
					if (k <= j) {
						tempStack->push_back(formula.substr(k, j-k+1)); //截取之前的子字符串
					}
					if (operatorStack->empty()) { //如果此时运算符栈为空，那么直接把该运算符压入运算符栈
						operatorStack->push(formulaChar);
					}
					else {
						char stackChar = operatorStack->top(); //取出栈顶字符
						if ((stackChar == '+' || stackChar == '-')
							&& (formulaChar == '*' || formulaChar == '/')) { //栈顶是加减而当前运算符是乘除
							operatorStack->push(formulaChar); //运算符栈压入当前运算符
						}
						else {
							char cc = operatorStack->top();
							string ss = "";
							ss.push_back(cc);
							tempStack->push_back(ss); 
							operatorStack->pop();
							operatorStack->push(formulaChar); 
						}
					}
				}
				k = j + 2;
			}
		}
		while (!operatorStack->empty()) {
			tempStack->push_back(string(1, operatorStack->top()));
			operatorStack->pop();
		}
		stack<string>* calcStack = new stack<string>();
		for (int i = 0; i < tempStack->size(); i++) {
			string peekChar = tempStack->at(i);
			if (peekChar != "+" && peekChar != "-"
				&& peekChar != "/" && peekChar != "*") {
				calcStack->push(peekChar);
			}
			else {
				int a1 = 0;
				int b1 = 0;
				if (!calcStack->empty()) {
					b1 = stoi(calcStack->top());
					calcStack->pop();
				}
				if (!calcStack->empty()) {
					a1 = stoi(calcStack->top());
					calcStack->pop();
				}
				if (peekChar == "+") {
					calcStack->push(to_string(a1 + b1));
				}
				else if (peekChar == "-") {
					calcStack->push(to_string(a1 - b1));
				}
				else if (peekChar == "*") {
					calcStack->push(to_string(a1 * b1));
				}
				else if (peekChar == "/") {
					calcStack->push(to_string(a1 / b1));
				}
			}
		}
		return formula + "=" + calcStack->top();
	}
private:
	string op[4] = { "+", "-", "*", "/" };
};


int main()
{
	Calculator* calc = new Calculator();
	string question = calc->MakeFormula();
	cout << question << endl;
	string ret = calc->Solve("15÷5 + 3 - 2");// question);// "11+22");
	cout << ret << endl;
	cout << "That's the sample. Now enter for finish" << endl;
	getchar();

	//  13 + 17 - 1 = 29
	//	11 * 15 - 5 = 160
	//	3 + 10 + 4 - 16 = 1
	//	15÷5 + 3 - 2 = 4
	
	/*for (int i = 0; i < 10000000; i++) {
		Calculator* calc = new Calculator();
		string question = calc->MakeFormula();
		cout << question << endl;
		string ret = calc->Solve("11+22");
		cout << ret << endl;
	}*/
}

