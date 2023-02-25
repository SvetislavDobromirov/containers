#include "../s21_containers.h"
#include <gtest/gtest.h>

using namespace s21;

TEST(stack_1, stack_test_1) {

  stack<int> st1;
  st1.push(1);
  EXPECT_EQ(1, st1.top());

  st1.push(31);
  EXPECT_EQ(31, st1.top());

  st1.pop();
  EXPECT_EQ(1, st1.top());

  EXPECT_EQ(0, st1.empty());
  st1.pop();
  EXPECT_EQ(1, st1.empty());
}

TEST(stack_2, stack_test_2) {

  stack<int> st1 = {1, 2, 3, 4};
  stack<int> st2 = {5, 6, 7, 8};
  st1.swap(st2);
  EXPECT_EQ(8, st1.top());
  EXPECT_EQ(4, st2.top());
  stack<int> st3 = std::move(st1);
  EXPECT_EQ(8, st3.top());
  EXPECT_EQ(4, st3.size());
  stack<int> st5(st1);
  stack<int> st6 = st5;

  // EXPECT_EQ(8, st6.top());
}

TEST(stack_3, stack_test_3) {

  stack<int> st1 = {1, 2, 3, 4};
  stack<int> st2 = st1;
  EXPECT_EQ(4, st2.top());
}

TEST(stack_23, stack_test_3) {

  stack<int> st1 = {1, 2, 3, 4};
  st1.emplace_back(4, 6);
  EXPECT_EQ(6, st1.top());
}