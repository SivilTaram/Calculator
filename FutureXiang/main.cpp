//
// Created by xiangweilai on 2020/2/28.
//

#include "Calculator.h"
#include <ctime>

int main(int argc, char *argv[])
{
    srand((unsigned int)time(NULL));  // BUG FIX: srand MUST BE OF OUT THE LOOP (otherwise seed will always be the same)

    int n = stoi(string(argv[1]));  // IMPLEMENT: input from command

    freopen("subject.txt", "w", stdout);  // IMPLEMENT: output to file "subject.txt"
    
    Calculator* calc = new Calculator();
    for (int i = 0; i < n; ++i) {
        string question = calc->MakeFormula();
        string ret = calc->Solve(question);
        cout << ret << endl;
    }
}
