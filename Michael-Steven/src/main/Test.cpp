//
// Created by Michael_Shan on 2020/3/3.
//

#include "config.h"
#include "Calculator.h"

TEST(Calculator, Solve){
    Calculator* calc = new Calculator();
    string ret = calc->Solve("41-12/12+12-99");
    EXPECT_STREQ(ret.c_str(), "41-12/12+12-99=-47");
}
