#include "../map/s21_map.h"
#include <gtest/gtest.h>

TEST(Map, 0_base) { s21::map<int, std::string> a; }

TEST(Map, 1_at_insert) {
  s21::map<int, std::string> a;
  a.insert({0, "aboba"});
  a.insert({1, "flex"});

  auto res = a.at(1);
  ASSERT_EQ(res, "flex");
}

TEST(Map, 2_at_insert) {
  s21::map<int, std::string> a;
  a.insert({0, "aboba"});
  a.insert({1, "flex"});
  ASSERT_THROW(a.at(3), std::out_of_range);
}

TEST(Map, 3_operator_square) {
  s21::map<int, std::string> a{{1, "aboba1"}, {2, "aboba 2"}};

  ASSERT_EQ(a[2], "aboba 2");
}

TEST(Map, 4_operator_square) {
  s21::map<int, std::string> a{{1, "aboba1"}, {2, "aboba 2"}};

  ASSERT_EQ(a[5], "");
}

TEST(Map, 5_begin_iterator) {
  s21::map<int, std::string> a{{1, "aboba1"},
                               {2, "aboba 2"},
                               {4, "aboba 4"},
                               {0, "aboba 0"},
                               {3, "aboba 3"}};

  auto it = a.begin();

  ASSERT_EQ((*it).second, "aboba 0");
  it++;
  ASSERT_EQ((*it).second, "aboba1");
  ASSERT_EQ((*it).first, 1);
}

TEST(Map, 6_empty) {
  s21::map<int, int> a;

  ASSERT_EQ(a.empty(), true);
  a.insert({1, 1});
  ASSERT_EQ(a.empty(), false);
}

TEST(Map, 7_size_erase) {
  s21::map<std::string, std::string> a{
      {"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};
  ASSERT_EQ(a.size(), 3);
  auto it = a.begin();
  a.erase(it);
  ASSERT_EQ(a.size(), 2);
  a.insert("cat", "meow");
  ASSERT_EQ(a.size(), 3);
}

TEST(Map, 8_clear) {
  s21::map<std::string, std::string> a{
      {"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};
  a.clear();
  ASSERT_EQ(a.size(), 0);
}

TEST(Map, 9_contains) {
  s21::map<std::string, std::string> a{
      {"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};

  ASSERT_EQ(a.contains("aboba"), true);
  ASSERT_EQ(a.contains("abobik"), false);
}

TEST(Map, 10_copy) {
  s21::map<std::string, std::string> a{
      {"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};

  s21::map<std::string, std::string> b(a);

  ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(Map, 11_move) {
  s21::map<std::string, std::string> a{{"aboba", "flex"}};

  s21::map<std::string, std::string> b(std::move(a));

  ASSERT_EQ("aboba", (*b.begin()).first);
  ASSERT_THROW(*a.begin(), std::runtime_error);
}

TEST(Map, 12_insert) {
  s21::map<int, int> square;
  square.insert(1, 1);
  square.insert(2, 4);
  square.insert(3, 9);
  auto pr = square.insert(2, 44);

  ASSERT_EQ(square.at(2), 4);
  ASSERT_EQ(pr.second, false);
}

TEST(Map, 13_insert_or_assign) {
  s21::map<int, std::string> aboba;
  aboba.insert_or_assign(1, "one");
  aboba.insert_or_assign(2, "two");
  aboba.insert_or_assign(1, "new_one");

  ASSERT_EQ(aboba[1], "new_one");
  ASSERT_EQ(aboba[2], "two");
}

TEST(Map, 14_swap_merge_size_erase) {
  s21::map<int, std::string> aboba{{1, "aboba1"}, {2, "aboba2"}, {3, "aboba3"}};
  s21::map<int, std::string> aboba2{
      {-1, "-aboba1"}, {-2, "-aboba2"}, {-3, "-aboba3"}};

  aboba2.merge(aboba);
  aboba.swap(aboba2);

  ASSERT_EQ(aboba.size(), 6);
  ASSERT_EQ(aboba2.size(), 3);

  auto it = aboba.begin();
  ASSERT_EQ((*it).first, -3);
  it++;
  it++;
  ASSERT_EQ((*it).first, -1);
  it++;
  it++;
  it++;
  ASSERT_EQ((*it).first, 3);
  it = aboba2.begin();
  ASSERT_EQ((*it).first, 1);
  it++;
  aboba2.erase(it);
  ASSERT_EQ(aboba2.size(), 2);
  it = aboba2.begin();
  ASSERT_EQ((*it).first, 1);
  it++;
  ASSERT_EQ((*it).first, 3);
}

TEST(Map, 15_emplace) {
  s21::map<int, int> a;
  a.emplace(std::make_pair(69, 5));
  a.emplace(std::make_pair(120, 5));
  auto it = a.begin();
  ASSERT_EQ((*it).first, 69);
  a.emplace(std::make_pair(-55, 5), std::make_pair(-200, 1));
  it = a.begin();
  ASSERT_EQ((*it).first, -200);
}

TEST(Map, 16_emplace) {
  s21::map<int, std::string> a;
  std::pair<int, std::string> bibka = {1, "bobka"};
  std::pair<int, std::string> bibka2 = {2, "balabolka"};
  a.emplace(bibka, bibka2);
  auto it = a.begin();
  ASSERT_EQ((*it).second, "bobka");
  it++;
  ASSERT_EQ((*it).second, "balabolka");
}
