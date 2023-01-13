#include "../map/s21_map.h"
#include <gtest/gtest.h>

TEST(Map, 0_base)
{
    s21::map<int, std::string> a;
}

TEST(Map, 1_at_insert)
{
    s21::map<int, std::string> a;
    a.insert({0, "aboba"});
    a.insert({1, "flex"});

    auto res = a.at(1);
    ASSERT_EQ(res, "flex");
}

TEST(Map, 2_at_insert)
{
    s21::map<int, std::string> a;
    a.insert({0, "aboba"});
    a.insert({1, "flex"});
    ASSERT_THROW(a.at(3), std::out_of_range);
}

TEST(Map, 3_operator_square)
{
    s21::map<int, std::string> a{{1, "aboba1"}, {2, "aboba 2"}};

    ASSERT_EQ(a[2], "aboba 2");
}

TEST(Map, 4_operator_square)
{
    s21::map<int, std::string> a{{1, "aboba1"}, {2, "aboba 2"}};

    ASSERT_EQ(a[5], "");
}

TEST(Map, 5_begin_iterator)
{
    s21::map<int, std::string> a{{1, "aboba1"}, {2, "aboba 2"}, {4, "aboba 4"}, {0, "aboba 0"}, {3, "aboba 3"}};

    auto it = a.begin();

    ASSERT_EQ((*it).second, "aboba 0");
    it++;
    ASSERT_EQ((*it).second, "aboba1");
    ASSERT_EQ((*it).first, 1);
}

TEST(Map, 6_empty)
{
    s21::map<int, int> a;

    ASSERT_EQ(a.empty(), true);
    a.insert({1, 1});
    ASSERT_EQ(a.empty(), false);
}

TEST(Map, 7_size_erase)
{
    s21::map<std::string, std::string> a{{"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};
    ASSERT_EQ(a.size(), 3);
    auto it = a.begin();
    a.erase(it);
    ASSERT_EQ(a.size(), 2);
    a.insert("cat", "meow");
    ASSERT_EQ(a.size(), 3);
}

TEST(Map, 8_clear)
{
    s21::map<std::string, std::string> a{{"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};
    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST(Map, 9_contains)
{
    s21::map<std::string, std::string> a{{"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};

    ASSERT_EQ(a.contains("aboba"), true);
    ASSERT_EQ(a.contains("abobik"), false);
}

TEST(Map, 10_copy)
{
    s21::map<std::string, std::string> a{{"aboba", "flex"}, {"s21", "s42"}, {"Doctor Who", "Who?"}};

    s21::map<std::string, std::string> b(a);

    ASSERT_EQ(*a.begin(), *b.begin());
}

TEST(Map, 11_move)
{
    s21::map<std::string, std::string> a{{"aboba", "flex"}};

    s21::map<std::string, std::string> b(std::move(a));

    ASSERT_EQ("aboba", (*b.begin()).first);
    ASSERT_THROW(*a.begin(), std::runtime_error);
}