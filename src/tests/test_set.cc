#include "../set/s21_set.h"
#include <gtest/gtest.h>

TEST(Set, 1) {
  s21::set<int> a{-120, 55, 5};
  a.insert(5);
  a.insert(5);
  a.insert(3);
  a.insert(8);
  a.insert(5);
  a.insert(10);
  a.insert(1);
  a.insert(2);
  a.insert(52);
  a.insert(13);
  a.insert(-5);
  a.insert(0);
  a.insert(22);
  a.insert(-21);
  a.insert(99);
  a.insert(6);

  int ca = 105;
  a.insert(ca);
}

TEST(Set, 2_test_size) {
  s21::set<int> a{-120, 55, 5};

  ASSERT_EQ(3, a.size());
}

TEST(Set, 3_test_empty) {
  s21::set<int> a;

  ASSERT_EQ(true, a.empty());
  ASSERT_EQ(0, a.size());
}

TEST(Set, 3_test_not_empty) {
  s21::set<int> a{1};

  ASSERT_EQ(false, a.empty());
}

TEST(Set, 4_iterator) {
  s21::set<int> a{1, 2, 3, -2, 0};
  s21::set<int>::iterator it = a.begin();
  ASSERT_EQ(*it, -2);
}

TEST(Set, 5_increment) {
  s21::set<int> a{1, 2, 3, -2, 0};
  s21::set<int>::iterator it = a.begin();
  ASSERT_EQ(*it, -2);
  it++;
  ASSERT_EQ(*it, 0);
  it++;
  ASSERT_EQ(*it, 1);
  it++;
  ASSERT_EQ(*it, 2);
  it++;
  ASSERT_EQ(*it, 3);
}

TEST(Set, 6_float) {
  s21::set<float> a;
  a.insert(4.5);
  auto it = a.begin();
  ASSERT_EQ(*it, 4.5);
}

TEST(Set, 7_string) {
#include <string>
  s21::set<std::string> a;
  a.insert("aboba");
  s21::set<std::string>::iterator it = a.begin();
  ASSERT_EQ(*it, "aboba");
}
TEST(Set, 8_for) {
  s21::set<int> a{1, 2, 3, 4, 5};

  int b = 1;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, b);
    b++;
  }
}

TEST(Set, 9_insert_pair) {
  s21::set<int> a;
  std::pair b = a.insert(5);
  std::pair c = a.insert(5);
  auto it = a.begin();
  ASSERT_EQ(b.second, true);
  ASSERT_EQ(c.second, false);

  ASSERT_EQ(*b.first, *it);
}

TEST(Set, 10_nullptr) {
  s21::set<int> a;
  auto it = a.begin();

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 11_find) {
  s21::set<std::string> a {"aboba", "flex"};
  auto it = a.find("flex");

  ASSERT_EQ(*it, "flex");
}

TEST(Set, 12_find) {
  s21::set<std::string> a {"aboba", "flex"};
  auto it = a.find("cringe");

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 13_contains) {
  s21::set<std::string> a;
  a.insert("meow");

  bool res = a.contains("meow");
  ASSERT_EQ(res, true);
}

TEST(Set, 14_contains) {
  s21::set<std::string> a;
  a.insert("meow\n");

  bool res = a.contains("meow");
  ASSERT_EQ(res, false);
  res = a.contains("meow\n");
  ASSERT_EQ(res, true);
}

TEST(Set, 15_erase) {
  s21::set<int> a {5, 2, 3, 10, 9, 12, 8};

  auto it = a.find(9);
  a.erase(it);
  int tmp[6] = {2, 3, 5, 8, 10, 12};

  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, tmp[i]);
    i++;
  }

  it = a.find(3);
  a.erase(it);
  int tmp2[5] = {2, 5, 8, 10, 12};
  i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, tmp2[i]);
    i++;
  }
}

TEST(Set, 16_erase_root) {
  s21::set<int> a {5, 2, 3};

  
  a.erase(a.find(5));

  int tmp[2] = {2, 3};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, tmp[i]);
    i++;
  }
}

TEST(Set, 17_erase) {
  s21::set<int> a {5, 2, 3};

  a.erase(a.find(3));

  int tmp[2] = {2, 5};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, tmp[i]);
    i++;
  }
}

TEST(Set, 18_clear) {
  s21::set<int> a {1, 2};

  a.clear();
  auto it = a.begin();

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 19_clear) {
  s21::set<int> a {1, 2};

  a.clear();
  auto it = a.begin();

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 20_clear_empty) {
  s21::set<int> a;

  a.clear();
  auto it = a.begin();

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 21_swap) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b {4, 5, 6};

  a.swap(b);
  auto it = a.begin();

  ASSERT_EQ(*it, 4);
  it++;
  ASSERT_EQ(*it, 5);
  it++;
  ASSERT_EQ(*it, 6);
}

TEST(Set, 22_swap) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b {4, 5, 6};

  a.swap(b);
  auto it = b.begin();

  ASSERT_EQ(*it, 1);
  it++;
  ASSERT_EQ(*it, 2);
  it++;
  ASSERT_EQ(*it, 3);
}

TEST(Set, 23_merge) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b {4, 5, 6};

  a.merge(b);

  int i = 1;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 24_merge_empty) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b;

  a.merge(b);

  int i = 1;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 25_merge_empty_2) {
  s21::set<int> a;
  s21::set<int> b {1, 2, 3};

  a.merge(b);

  int i = 1;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 26_size) {
  s21::set<int> a {1, 2, 3};
  a.erase(a.find(2));
  ASSERT_EQ(a.size(), 2);
  a.clear();
  ASSERT_EQ(a.size(), 0);
}

TEST(Set, 27_copy) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b(a);
  int i = 1;
  for (auto it = b.begin(); it != b.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 28_copy_empty) {
  s21::set<int> a;
  s21::set<int> b(a);
  
  auto it = b.begin();

  ASSERT_THROW(*it, std::runtime_error);
}

TEST(Set, 28_move) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b(std::move(a));

  int i = 1;  
  for (auto it = b.begin(); it != b.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 29_equal) {
  s21::set<int> a {1, 2, 3};
  s21::set<int> b;
  b = std::move(a);

  int i = 1;  
  for (auto it = b.begin(); it != b.end(); it++) {
    ASSERT_EQ(*it, i);
    i++;
  }
}

TEST(Set, 30_iterators) {
  s21::set<int> a {5, 10, 3, 4, 0, 1, -2, 12, -1, 0, 10};
  s21::set<int>::const_iterator it_1 = a.begin();
  s21::set<int>::iterator it_2 = a.begin();
  ASSERT_EQ(*it_1, -2);
  ASSERT_EQ(*it_2, -2);
  it_1++;
  it_2++;
  ASSERT_EQ(*it_1, -1);
  ASSERT_EQ(*it_2, -1);
}

TEST(Set, 31_increments) {
  s21::set<int> a {1, 0, -1};

  auto it = a.begin();
  it++;
  ASSERT_EQ(*it, 0);
  ++it;
  ASSERT_EQ(*it, 1);
  --it;
  ASSERT_EQ(*it, 0);
  it--;
  ASSERT_EQ(*it, -1);
}

TEST(Set, 32_emplace) {
  s21::set<int> a;
  int b = 10, c = 15, d = 5, e = -10;
  a.emplace(b);
  a.emplace(c);
  a.emplace(d);
  a.emplace(e);
  int ar[4] = {-10, 5, 10, 15};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, ar[i]);
    i++;
  }
}

TEST(Set, 33_emplace) {
  s21::set<int> a;
  int b = 10, c = 15, d = 5, e = -10;
  a.emplace(b, c, d, e);
  int ar[4] = {-10, 5, 10, 15};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, ar[i]);
    i++;
  }
}

TEST(Set, 34_emplace) {
  s21::set<int> a;
  a.emplace(10, 15, 5, -10);
  int ar[4] = {-10, 5, 10, 15};
  int i = 0;
  for (auto it = a.begin(); it != a.end(); it++) {
    ASSERT_EQ(*it, ar[i]);
    i++;
  }
}

TEST(Set, 35_insert) {
  s21::set<int> aboba;
  auto pr = aboba.insert(5);
  ASSERT_EQ(pr.second, true);
  auto pr1 = aboba.insert(5);
  ASSERT_EQ(pr1.second, false);
}