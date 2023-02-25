
#include "../s21_containerplus.h"
#include <gtest/gtest.h>
#include <vector>

TEST(Vreload_sq_breaks, Test_1) {
  vector<int> obj = {1, 2, 3, 4, 5};
  vector<int> obj_V = {1, 2, 3, 4, 5};
  EXPECT_EQ(obj[1], obj_V[1]);
  EXPECT_EQ(obj.at(2), obj_V.at(2));
  EXPECT_ANY_THROW(obj_V[9]);
  EXPECT_ANY_THROW(obj_V.at(9));
  EXPECT_EQ(obj[0], obj_V[0]);
  EXPECT_EQ(obj.at(0), obj_V.at(0));
  EXPECT_ANY_THROW(obj_V.at(-1));
  EXPECT_ANY_THROW(obj_V[-1]);
  // EXPECT_TRUE(b.EqMatrix(c));
}

TEST(Vpush_back, Test_1) {
  vector<int> obj;
  std::vector<int> obj_V;

  for (int i = 0; i < 130; i++)
    obj.push_back(i);
  for (int i = 0; i < 130; i++)
    obj_V.push_back(i);
  EXPECT_EQ(obj.at(127), obj_V.at(127));
  EXPECT_EQ(obj[127], obj_V[127]);
  EXPECT_EQ(obj.capacity(), obj_V.capacity());
  EXPECT_EQ(obj.size(), obj_V.size());
  EXPECT_EQ(*(obj.begin()), *(obj_V.begin()));
  obj.clear();
  obj_V.clear();
  EXPECT_EQ(obj.size(), obj_V.size());
}

TEST(Vpop_back, Test_1) {
  vector<int> obj(2);
  std::vector<int> obj_V(2);
  obj.push_back(1);
  obj_V.push_back(1);
  EXPECT_EQ(obj.empty(), obj_V.empty());
  obj.pop_back();
  obj_V.pop_back();
  EXPECT_EQ(obj.empty(), obj_V.empty());
  EXPECT_EQ(obj.max_size(), obj_V.max_size());
}

TEST(Vcopy1, Test_1) {
  vector<int> obj = {1, 2, 3};
  vector<int> obj_2(obj);
  EXPECT_EQ(obj.at(2), obj_2.at(2));
}

TEST(Vmove1, Test_1) {
  vector<int> obj = {1, 2, 3};
  vector<int> obj_2 = {5, 6, 7};
  obj = (vector<int> &&) obj_2;
  EXPECT_EQ(obj.at(0), 5);
}

TEST(Vreserve, Test_1) {
  vector<int> obj;
  vector<int> obj_2;
  obj.reserve(50);
  obj_2.reserve(50);
  EXPECT_EQ(obj.capacity(), obj_2.capacity());
}

TEST(Vshrink_to_fit, Test_1) {
  vector<int> obj(7);
  std::vector<int> obj_2(7);
  for (int i = 0; i < 50; i++)
    obj_2.push_back(i);
  for (int i = 0; i < 50; i++)
    obj.push_back(i);
  obj_2.shrink_to_fit();
  obj.shrink_to_fit();
  EXPECT_EQ(obj.capacity(), obj_2.capacity());
}

TEST(Vend_it, Test_1) {
  vector<int> obj_2 = {1, 2, 3, 4, 5, 6};
  int *p = obj_2.end();
  EXPECT_EQ(*(p - 1), obj_2.at(5));
}

TEST(Vother, Test_1) {
  vector<int> obj_2 = {1, 2, 3, 4, 5, 6};
  vector<int> obj(std::move(obj_2));

  EXPECT_EQ(obj.front(), 1);
  EXPECT_EQ(obj.back(), 6);
  EXPECT_EQ(*obj.data(), 1);
}

TEST(Vector, Insert) {
  vector<int> obj_2{1, 3, 4, 5};
  auto it = obj_2.begin();
  it++;
  obj_2.insert(it, 2);
  EXPECT_EQ(*(obj_2.begin() + 1), 2);
}
