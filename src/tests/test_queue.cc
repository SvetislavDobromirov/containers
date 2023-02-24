#include "../queue/s21_queue.h"
#include <gtest/gtest.h>

using namespace s21;

TEST(queue_1, queue_test_1) {
  queue<int> q2;
  q2.pop();

  q2.push(1);
  q2.push(2);
  q2.push(3);

  EXPECT_EQ(1, q2.front());
  EXPECT_EQ(3, q2.back());
  q2.pop();
  EXPECT_EQ(2, q2.front());
  EXPECT_EQ(0, q2.empty());
  q2.pop();
  q2.pop();
  EXPECT_EQ(1, q2.empty());
}

TEST(queue_2, queue_test_2) {
  queue<int> q2 = {1, 2, 3};
  EXPECT_EQ(3, q2.size());
  queue<int> q3 = q2;
  EXPECT_EQ(1, q3.front());
  EXPECT_EQ(3, q3.back());
  queue<int> q4 = {5, 6, 7};
  q2.swap(q4);
  EXPECT_EQ(1, q4.front());
  EXPECT_EQ(3, q4.back());
}

TEST(queue_3, queue_test_3) {
  queue<int> q2 = {1, 2, 3};
  queue<int> q3(q2);
  EXPECT_EQ(1, q3.front());
  EXPECT_EQ(3, q3.back());
}
