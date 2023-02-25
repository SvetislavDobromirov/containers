#include <gtest/gtest.h>

#include <array>
#include <typeinfo>

#include "../s21_containerplus.h"

TEST(Constructors, Test_1) {
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});
  std::array<int, 6> origin({1, 2, 3, 4, 5, 6});
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
}

TEST(front_back_test, Test_3) {
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});
  std::array<int, 6> origin({1, 2, 3, 4, 5, 6});
  EXPECT_EQ(my.front(), origin.front());
  EXPECT_EQ(my.back(), origin.back());
  EXPECT_EQ(*my.begin(), *origin.begin());
  int *t1 = my.end() - 1;
  int *t2 = origin.end() - 1;
  EXPECT_EQ(*t1, *t2);
  EXPECT_EQ(my.empty(), origin.empty());
  EXPECT_EQ(my[0], origin[0]);
  EXPECT_EQ(my[5], origin[5]);
  EXPECT_EQ(my.size(), origin.size());
  EXPECT_EQ(my.max_size(), my.max_size());
  s21::array<int, 6> my2({1, 2, 3, 4, 5, 6});
  my2.fill(99);
  my.swap(my2);
  EXPECT_EQ(my2[5], 6);
  EXPECT_EQ(my[5], 99);
}

TEST(Else_one_test, Test_) {
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});
  std::array<int, 6> origin({1, 2, 3, 4, 5, 6});
  EXPECT_EQ(*my.data(), 1);

  s21::array<int, 0> my3;
  // EXPECT_EQ(*my3.end(), *my3.data());
  // EXPECT_EQ(my3.back(), *my3.data());
}

TEST(Else_second_test, Test_) {
  s21::array<int, 6> my{1, 2, 3, 4, 5, 6};
  s21::array<int, 6> my2((s21::array<int, 6> &&) my);

  EXPECT_EQ(my2[0], 1);
  EXPECT_EQ(my2[3], 4);
  EXPECT_EQ(my2[5], 6);
}

TEST(Else_third_test, Test_) {
  s21::array<int, 6> my{1, 2, 3, 4, 5, 6};
  s21::array<int, 6> my2;
  my2 = (s21::array<int, 6> &&) my;
  EXPECT_EQ(my2[0], 1);
  EXPECT_EQ(my2[3], 4);
  EXPECT_EQ(my2[5], 6);
}
