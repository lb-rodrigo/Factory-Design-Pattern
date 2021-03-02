#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"

#include "factory.hpp"

TEST(AddTest, Normal) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] ="./main"; 
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "1";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);	

    char third[2] ="+"; 
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="2"; 
    input[3] = new char[strlen(third) + 1];
    strcpy(input[3], fourth);

    Base* val1 = new Op(1);
    Base* val2 = new Op(2);

    Base* result = new Add(val1, val2);

    EXPECT_EQ(test->parse(input,4)->evaluate(), result->evaluate());   
}

TEST(AddTest, InvalidFront) {
    Factory* test = new Factory();
    char** input = new char*[3];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "+";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[2] ="2";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    EXPECT_TRUE(test->parse(input,3) == nullptr);

}

TEST(AddTest, InvalidBack) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "1";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[2] ="0";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="+";
    input[3] = new char[strlen(third) + 1];
    strcpy(input[3], fourth);

    EXPECT_TRUE(test->parse(input,4) == nullptr);
}

TEST(AddTest, MultipleOperations) {
    Factory* test = new Factory();
    char** input = new char*[7];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "1";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[2] ="+";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[2] ="2";
    input[3] = new char[strlen(fourth) + 1];
    strcpy(input[3], fourth);

    char fifth[2] ="1";
    input[4] = new char[strlen(fifth) + 1];
    strcpy(input[4], fifth);

    char sixth[2] ="+";
    input[5] = new char[strlen(sixth) + 1];
    strcpy(input[5], sixth);

    char seventh[2] ="5";
    input[6] = new char[strlen(seventh) + 1];
    strcpy(input[6], seventh);

    Base* val1 = new Op(1);
    Base* val2 = new Op(21);
    Base* val3 = new Add(val1, val2);
    Base* val4 = new Op(5);
    Base* result = new Add(val3,val4);     


    EXPECT_EQ(test->parse(input,7)->evaluate(), result->evaluate());
}

TEST(AddTest, Negative) {
    Factory* test = new Factory();
    char** input = new char*[4];

    char first[7] ="./main";
    input[0] = new char[strlen(first) + 1];
    strcpy(input[0],first);

    char second[2] = "1";
    input[1] = new char[strlen(second) + 1];
    strcpy(input[1], second);

    char third[2] ="+";
    input[2] = new char[strlen(third) + 1];
    strcpy(input[2], third);

    char fourth[3] ="-2";
    input[3] = new char[strlen(third) + 1];
    strcpy(input[3], fourth);

    Base* val1 = new Op(1);
    Base* val2 = new Op(-2);

    Base* result = new Add(val1, val2);

    EXPECT_EQ(test->parse(input,4)->evaluate(), result->evaluate());
}

#endif
