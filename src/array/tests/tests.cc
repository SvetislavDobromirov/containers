#include <gtest/gtest.h>

#include <array>
#include <typeinfo>

#include "../s21_array.h"

TEST(Constructors, Test_1) {
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});
  std::array<int, 6> origin({1, 2, 3, 4, 5, 6});
  // std::cout << typeid(my).name() << std::endl;
  // std::cout << typeid(origin).name() << std::endl;
  for (long unsigned int i = 0; i < origin.size(); i++) {
    EXPECT_TRUE(my.at(i) == origin.at(i));
  }
}

TEST(Constructors, Test_2) {
  s21::array<int, 5> my1({2, 3, 4, 5, 6});
  std::array<int, 5> origin1({2, 3, 4, 5, 6});
  s21::array<int, 5> my2(my1);
  std::array<int, 5> origin2(origin1);
  for (long unsigned int i = 0; i < origin1.size(); i++) {
    EXPECT_TRUE(my2.at(i) == origin2.at(i));
  }
}

TEST(Constructors, Test_3) {
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});
  std::array<int, 6> origin({1, 2, 3, 4, 5, 6});
  // std::cout << typeid(my.at(2)).name() << std::endl;
  // std::cout << typeid(origin.at(2)).name() << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
