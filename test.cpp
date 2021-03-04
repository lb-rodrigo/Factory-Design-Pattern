#include "gtest/gtest.h"
#include "mult_test.hpp"
#include "div_test.hpp"
#include "pow_test.hpp"
#include "factory.hpp"
#include "add_test.hpp"
#include "sub_test.hpp"

int main(int argc, char **argv){

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
