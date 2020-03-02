

//#include "stdafx.h"
#include <stack>
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <ctime>
#include <string>
#include "Calculator.h"
#include<fstream>

#define random(a,b) (rand()%(b-a+1)+a)

using namespace std;

Calculator::Calculator() {}

string Calculator::MakeFormula() {
	string formula = "";
	int count = random(2, 3);
	int start = 1;
	int number1 = random(0, 100);
	//cout << number1 << endl;
	formula += to_string(number1);
	int lastNumber = number1;
	while (start <= count) {
		int operation = random(0, 3);
		int number2 = random(0, 100);
		if(operation<3) formula += op[operation] + to_string(number2);//如果是+-*
		else {
			int tp = random(1, lastNumber);
			for (int i = tp; i >= 1; i--) {
				if (lastNumber % i == 0) {
					tp = i;
					break;
				}
			}
			number2 = tp;
			formula += op[operation] + to_string(number2);
		}
		if (operation == 2) lastNumber = lastNumber * number2;
		else if (operation == 3) lastNumber = lastNumber / number2;
		else lastNumber = number2;
	
		//lastNumber = number2;
	//	cout << "lastNUmber: " << lastNumber << endl;
		start++;
	}
	return formula;
};

string Calculator::Solve(string formula) {
	vector<string>* tempStack = new vector<string>();
	stack<char>* operatorStack = new stack<char>();
	int len = formula.length();
	int k = 0;
	for (int j = -1; j < len - 1; j++) {
		char formulaChar = formula[j + 1];
		if (j == len - 2 || formulaChar == '+' || formulaChar == '-' ||
			formulaChar == '*' || formulaChar == '/') {
			if (j == len - 2) {
				tempStack->push_back(formula.substr(k));
			}
			else {
				if (k <= j) {
					tempStack->push_back(formula.substr(k, j + 1));
				}
				if (operatorStack->empty()) {
					operatorStack->push(formulaChar);
				}
				else {
					char stackChar = operatorStack->top();
					if ((stackChar == '+' || stackChar == '-')
						&& (formulaChar == '*' || formulaChar == '/')) {
						operatorStack->push(formulaChar);
					}
					else {
						while (!operatorStack->empty()) {
							string tmp = "";
							tmp.append(1,operatorStack->top());
							tempStack->push_back(tmp);
							operatorStack->pop();
						}
						
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

int main()
{
	Calculator calc = Calculator();
	string path = "result.txt";
	ofstream out;
	out.open(path, ios::out);
	int n;
	cin >> n;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < n; i++) {
		string question = calc.MakeFormula();
		//cout << question << endl;
		string ret = calc.Solve(question);
		out <<  ret << endl;
	}
	out.close();
	return 0;
}


