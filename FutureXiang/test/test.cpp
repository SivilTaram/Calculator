//
// Created by xiangweilai on 2020/2/28.
//

#include "gtest/gtest.h"
#include "Calculator.h"

TEST(test, simpleAdd) {
    Calculator* calc = new Calculator();
    string ret = calc->Solve("11+22");
    ASSERT_EQ(ret, (string)"11+22=33");
}

TEST(test, sequence) {
    Calculator* calc = new Calculator();
    string ret = calc->Solve("3*4/6-2+5");
    ASSERT_EQ(ret, (string)"3*4/6-2+5=5");
}

TEST(test, priority) {
    Calculator* calc = new Calculator();
    string ret = calc->Solve("1+2*3/6");
    ASSERT_EQ(ret, (string)"1+2*3/6=2");
}

TEST(test, complex) {
    Calculator* calc = new Calculator();
    string ret = calc->Solve("2+2/2-2*2");
    ASSERT_EQ(ret, (string)"2+2/2-2*2=-1");
}