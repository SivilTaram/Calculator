#include <stdio.h>
#include <tchar.h>
#include <string>
using namespace std;
class Calculator {
public:
	Calculator();
	string MakeFormula();

	string Solve(string formula);
};