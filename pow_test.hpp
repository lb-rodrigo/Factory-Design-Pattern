#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"

#include "factory.hpp"

TEST(PowTest, Normal) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "5";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[3] ="**";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="2";
    input[3] = new char[strlen(fourth) + 1];
    strcpy(input[3], fourth);

    Base* val1 = new Op(5);
    Base* val2 = new Op(2);

    Base* result = new Pow(val1, val2);

    EXPECT_EQ(test->parse(input,4)->evaluate(), result->evaluate());
}

TEST(PowTest, MultipleOperations) {
    Factory* test = new Factory();
    char** input = new char*[6];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "2";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[3] ="**";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="2";
    input[3] = new char[strlen(fourth) + 1];
    strcpy(input[3], fourth);

    char fifth[3] ="**";
    input[4] = new char[strlen(fifth) + 1];
    strcpy(input[4], fifth);

    char sixth[2] ="2";
    input[5] = new char[strlen(sixth) + 1];
    strcpy(input[5], sixth);

    Base* val1 = new Op(2);
    Base* val2 = new Op(2);
    Base* val3 = new Pow(val1, val2);
    Base* val4 = new Op(2);
    Base* result = new Pow(val3,val4);


    EXPECT_EQ(test->parse(input,6)->evaluate(), result->evaluate());
}

TEST(PowTest, ZeroPower) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] = "./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "5";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[3] ="**";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="0";
    input[3] = new char[strlen(fourth) + 1];
    strcpy(input[3], fourth);

    Base* val1 = new Op(5);
    Base* val2 = new Op(0);

    Base* result = new Pow(val1, val2);

    EXPECT_EQ(test->parse(input,4)->evaluate(), result->evaluate());
}


TEST(PowTest, DecimalPower) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] = "./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "5";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[3] ="**";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[4] ="2.5";
    input[3] = new char[strlen(fourth) + 1];
    strcpy(input[3], fourth);

    Base* val1 = new Op(5);
    Base* val2 = new Op(2.5);

    Base* result = new Pow(val1, val2);

    EXPECT_EQ(test->parse(input,4)->evaluate(), result->evaluate());
}

#endif
