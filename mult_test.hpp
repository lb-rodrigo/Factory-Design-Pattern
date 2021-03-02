#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "base.hpp"
#include "factory.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "op.hpp"
#include <cmath>
#include <cstring>



TEST(MultTest, Simple_Mult) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="*"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="3"; 
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* one = new Op(1);
  Base* three = new Op(3);

  Base* result = new Mult(one, three);

	EXPECT_EQ(test->parse(input, 4)->evaluate(), result->evaluate());
	EXPECT_EQ(test->parse(input, 4)->stringify(), result->stringify());
}


TEST(MultTest, Neg_Mult) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main";
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[3] ="-1";
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="*";
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="3";
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* one = new Op(-1);
  Base* three = new Op(3);

  Base* result = new Mult(one, three);

        EXPECT_EQ(test->parse(input, 4)->evaluate(), result->evaluate());
        EXPECT_EQ(test->parse(input, 4)->stringify(), result->stringify());
}


TEST(MultTest, Mult_Zero) {
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main";
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1";
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="*";
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="0";
  input[3] = new char[strlen(third) + 1];
  strcpy(input[3], fourth);

  Base* one = new Op(1);
  Base* zero = new Op(0);

  Base* result = new Mult(one, zero);

	EXPECT_EQ(test->parse(input, 4)->evaluate(), result->evaluate());
	EXPECT_EQ(test->parse(input, 4)->stringify(), result->stringify());
}

TEST(MultTest, Mult_Mult){
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main"; 
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1"; 
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="*"; 
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1"; 
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[2] ="*"; 
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="1"; 
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[2] ="*"; 
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="3"; 
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

  Base* one = new Op(1);
  Base* one_2 = new Op(1);
  Base* result = new Mult(one, one_2);
  
  Base* one_3 = new Op(1);
  Base* result_2 = new Mult(result, one_3);
  Base* three = new Op(3);
  Base* result_3 = new Mult(result_2, three);

	EXPECT_EQ(test->parse(input, 8)->evaluate(), result_3->evaluate()); 
	EXPECT_EQ(test->parse(input, 8)->stringify(), result_3->stringify());
  }


TEST(MultTest, Mult_Div){
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main";
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1";
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="*";
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="1";
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[2] ="*";
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="1";
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[2] ="/";
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="3";
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

  Base* one = new Op(1);
  Base* one_2 = new Op(1);
  Base* result = new Mult(one, one_2);

  Base* one_3 = new Op(1);
  Base* result_2 = new Mult(result, one_3);
  Base* three = new Op(3);
  Base* result_3 = new Div(result_2, three);

        EXPECT_EQ(test->parse(input, 8)->evaluate(), result_3->evaluate());
        EXPECT_EQ(test->parse(input, 8)->stringify(), result_3->stringify());
  }



TEST(MultTest, Post_Invalid){
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main"; 
	  input[0] = new char[strlen(first) + 1];
	  strcpy(input[0],first);

  char second[2] ="1"; 
	  input[1] = new char[strlen(second) + 1];
	  strcpy(input[1], second);

  char third[2] ="*"; 
	  input[2] = new char[strlen(third) + 1];
	  strcpy(input[2], third);

  char fourth[2] ="1"; 
 	 input[3] = new char[strlen(third) + 1];
	  strcpy(input[3], fourth);

  char fifth[2] ="*";
         input[1] = new char[strlen(fourth) + 1];
         strcpy(input[1], third);

	EXPECT_TRUE(test->parse(input, 4) == nullptr);
}

TEST(MultTest, Pre_Invalid){
  Factory* test = new Factory();
  char** input = new char*[4];

  char first[7] ="./main";
          input[0] = new char[strlen(first) + 1];
          strcpy(input[0],first);

  char second[2] ="*";
          input[1] = new char[strlen(second) + 1];
          strcpy(input[1], second);

  char third[2] ="1";
          input[2] = new char[strlen(third) + 1];
          strcpy(input[2], third);

  char fourth[2] ="*";
         input[3] = new char[strlen(third) + 1];
          strcpy(input[3], fourth);

  char fifth[2] ="1";
         input[1] = new char[strlen(fourth) + 1];
         strcpy(input[1], third);

        EXPECT_TRUE(test->parse(input, 4) == nullptr);
}

TEST(MultTest, Decimal_Mult){
  Factory* test = new Factory();
  char** input = new char*[8];

  char first[7] ="./main";
  input[0] = new char[strlen(first) + 1];
  strcpy(input[0],first);

  char second[2] ="1";
  input[1] = new char[strlen(second) + 1];
  strcpy(input[1], second);

  char third[2] ="0";
  input[2] = new char[strlen(third) + 1];
  strcpy(input[2], third);

  char fourth[2] ="*";
  input[3] = new char[strlen(fourth) + 1];
  strcpy(input[3], fourth);

  char fifth[2] ="3";
  input[4] = new char[strlen(fifth) + 1];
  strcpy(input[4], fifth);

  char sixth[2] ="+";
  input[5] = new char[strlen(sixth) + 1];
  strcpy(input[5], sixth);

  char seventh[2] ="1";
  input[6] = new char[strlen(seventh) + 1];
  strcpy(input[6], seventh);

  char eigth[2] ="5";
  input[7] = new char[strlen(eigth) + 1];
  strcpy(input[7], eigth);

	Base* one = new Op(10);
  	Base* one_2 = new Op(3);
	Base* result = new Mult(one, one_2);

	Base* one_3 = new Op(15);
	Base* result_2 = new Add(result, one_3);
//	Base* three = new Op(3.5);
//	Base* result_3 = new Div(result_2, three);

        EXPECT_EQ(test->parse(input, 8)->evaluate(), result_2->evaluate());
        EXPECT_EQ(test->parse(input, 8)->stringify(), result_2->stringify());
  }



#endif // __MULT_TEST_HPP__
