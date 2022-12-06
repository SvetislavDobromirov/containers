#include <gtest/gtest.h>

TEST(test, test_1) {
  
  EXPECT_EQ(a.GetCols(), 0);
  //EXPECT_TRUE(b.EqMatrix(c));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
