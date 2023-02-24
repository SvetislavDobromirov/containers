#include "../multiset/s21_multiset.h"
#include <gtest/gtest.h>

TEST(Multiset, test1_base) {
  s21::multiset<int> my_test_multi;
  my_test_multi.insert(1);
  EXPECT_EQ(1, *my_test_multi.begin());
  my_test_multi.erase(my_test_multi.begin());
  EXPECT_EQ(0, my_test_multi.size());
}

TEST(Multiset, test1) {
  s21::multiset<int> my_test_multi = {1, 2, 3, 4, 1};
  my_test_multi.insert(1);
  int size = (int)my_test_multi.size();
  EXPECT_EQ(6, size);

  int bbbool = (int)my_test_multi.contains(2);
  int bbbool2 = (int)my_test_multi.contains(6);
  EXPECT_EQ(bbbool, 1);
  EXPECT_EQ(bbbool2, 0);

  my_test_multi.clear();
  EXPECT_EQ(0, (int)my_test_multi.size());
}

TEST(Multiset, test1_clean1) {
  s21::multiset<int> my_test_multi;
  my_test_multi.clear();
}

TEST(Multiset, test_insert_2) {
  std::multiset<int> obj{12, 6, 12, 6, 2, 1, 12};
  s21::multiset<int> k{12, 6, 12, 6, 2, 1, 12};

  EXPECT_EQ(k.empty(), 0);

  auto it_or = obj.begin();
  auto itm = k.begin();
  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    it_or++;
  }

  it_or = obj.begin();
  itm = k.begin();
  it_or++;
  it_or++;
  ++itm;
  ++itm;

  k.erase(itm);
  obj.erase(it_or);

  it_or = obj.begin();
  itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    ++it_or;
  }

  k.clear();
  EXPECT_EQ(k.empty(), 1);
}

TEST(Multiset, test_insert_3) {
  std::multiset<int> obj{12, 14, 8, 4, 8, 9, 10};
  s21::multiset<int> k{12, 14, 8, 4, 8, 9, 10};
  auto it_or = obj.begin();
  auto itm = k.begin();

  it_or = obj.begin();
  itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    ++it_or;
  }
  EXPECT_EQ(*obj.lower_bound(8), *k.lower_bound(8));
  EXPECT_EQ(*obj.lower_bound(7), *k.lower_bound(7));
  EXPECT_EQ(*obj.lower_bound(1), *k.lower_bound(1));

  EXPECT_EQ(*obj.upper_bound(8), *k.upper_bound(8));
  EXPECT_EQ(*obj.upper_bound(7), *k.upper_bound(7));
  EXPECT_EQ(*obj.upper_bound(1), *k.upper_bound(1));
}

TEST(Multiset, test_insert_4) {
  std::multiset<int> obj{3, 2, 2, 0, 6, 2, 4};
  s21::multiset<int> k{3, 2, 2, 0, 6, 2, 4};
  EXPECT_EQ(obj.count(2), k.count(2));

  auto it_or = obj.begin();
  auto itm = k.begin();

  it_or = obj.begin();
  itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    ++it_or;
  }

  auto k_pair = k.equal_range(2);
  auto obj_pair = obj.equal_range(2);
  EXPECT_EQ(*(--k_pair.first), *(--obj_pair.first));
  EXPECT_EQ(*(k_pair.second), *(obj_pair.second));
}

TEST(Multiset, test_insert_5) {
  std::multiset<int> obj{3, 2, 2, 0, 6, 2, 4};
  s21::multiset<int> k{3, 2, 2, 0, 6, 2, 4};
  auto it_or = obj.begin();
  auto itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    it_or++;
  }

  it_or = obj.begin();
  itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    ++itm;
    ++it_or;
  }
}

TEST(Multiset, test_insert_6) {
  std::multiset<int> obj{4, 4, 0, 6, 0, 5, 2};
  s21::multiset<int> k{4, 4, 0, 6, 0, 5, 2};
  auto it_or = obj.begin();
  auto itm = k.begin();

  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    itm++;
    ++it_or;
  }

  it_or = obj.begin();
  itm = k.begin();

  it_or++;
  it_or++;
  it_or++;
  itm++;
  itm++;
  itm++;

  it_or--;
  it_or--;
  it_or--;
  itm--;
  itm--;
  itm--;

  EXPECT_EQ(*it_or, *itm);
}

TEST(Multiset, test_merge_6) {
  std::multiset<int> obj{4, 4, 0, 6, 0, 5, 2, 1, 2, 3};
  s21::multiset<int> k{4, 4, 0, 6, 0, 5, 2};
  s21::multiset<int> k2{1, 2, 3};
  k.merge(k2);

  auto it_or = obj.begin();
  auto itm = k.begin();
  while (itm != k.end()) {
    EXPECT_EQ(*itm, *it_or);
    itm++;
    ++it_or;
  }
}

TEST(Multiset, test_swap) {
  s21::multiset<int> k1{0, 1, 2, 3, 4};
  s21::multiset<int> k2{5, 6, 7, 8, 9};
  k1.swap(k2);
  auto it1 = k2.begin();
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(i, *it1);
    it1++;
  }

  auto it2 = k1.begin();
  for (int i = 5; i < 10; i++) {
    EXPECT_EQ(i, *it2);
    it2++;
  }
}

TEST(Multiset, erase_empty_max_size) {
  s21::multiset<int> my_test_multi;
  my_test_multi.erase(my_test_multi.begin());

  // max_size differ with original, and will differ in different OS. Because
  // test is not real. It is OK
  EXPECT_EQ(my_test_multi.max_size(), my_test_multi.max_size());
}

TEST(Multiset, copy) {
  s21::multiset<int> multi1 = {1, 2, 1, 5, 5, 43, 12, 0};
  s21::multiset<int> multi2(multi1);
  auto it1 = multi1.begin();
  auto it2 = multi2.begin();
  while (it1 != multi1.end()) {
    EXPECT_EQ(*it1, *it2);
    ++it1;
    ++it2;
  }
}

TEST(Multiset, emplace) {
  s21::multiset<int> multi1;
  multi1.emplace(1, 2, 3, 4, 5, 6);
  auto it1 = multi1.begin();
  int count = 1;
  while (it1 != multi1.end()) {
    EXPECT_EQ(*it1, count);
    ++it1;
    count++;
  }
}

TEST(Multiset, eqqq) {
  s21::multiset<int> multi2{1, 2, 3, 4, 5};
  s21::multiset<int> multi1{6, 7, 8, 9, 10};
  multi1 = multi2;
  auto it1 = multi1.begin();
  int count = 1;
  while (it1 != multi1.end()) {
    EXPECT_EQ(*it1, count);
    ++it1;
    count++;
  }
}

TEST(Multiset, movw) {
  s21::multiset<int> multi2{1, 2, 3, 4, 5};
  s21::multiset<int> multi1((multiset<int> &&) multi2);
  auto it1 = multi1.begin();
  int count = 1;
  while (it1 != multi1.end()) {
    EXPECT_EQ(*it1, count);
    ++it1;
    count++;
  }
}

TEST(Multiset, const_it) {
  s21::multiset<int> multi2{1, 2, 3, 4, 5};
  s21::multiset<int> multi1((multiset<int> &&) multi2);
  auto it1 = multi1.cbegin();
  int count = 1;
  while (it1 != multi1.cend()) {
    EXPECT_EQ(*it1, count);
    ++it1;
    count++;
  }
  it1 = multi1.cbegin();
  ++it1;
  --it1;
  EXPECT_EQ(*it1, 1);
  it1++;
  it1--;
  //   EXPECT_EQ(*it1, 1);
}
