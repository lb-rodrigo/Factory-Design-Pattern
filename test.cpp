#include "add_test.hpp"
#include "sub_test.hpp"
#include "pow_test.hpp"

#include "gtest/gtest.h"

extern int mr_argc; 
extern char** my_argv;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
