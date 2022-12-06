#include <gtest/gtest.h>
#include "../s21_vector.h"

//#include "vector_test.cc"

TEST(test, test_1) {
  //std::vector<int> obj = {1,2,3};
  Vector<int> obj(2);
 // Vector<int> obj;
  EXPECT_EQ(0, 0);
  
  //EXPECT_TRUE(b.EqMatrix(c));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
