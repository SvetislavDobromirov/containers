#include "../multiset/s21_multiset.h"
#include <gtest/gtest.h>



TEST(Multiset, test1_base)
{
    s21::multiset<int>  my_test_multi;

    my_test_multi.insert(100);
    std::cout <<  ": -  " << std::endl;
}

TEST(Multiset_it, test2_init)
{
     s21::multiset<int> my_test_multi = {1,2,3};
    
    auto it_my = my_test_multi.begin();
    auto count = 1;
    while (it_my != my_test_multi.end())
    {
        std::cout << count << ": -  " << *it_my << std::endl;
        ++it_my;
        count++;
    }
}

TEST(Multiset_erase, test1)
{
    // s21::multiset<int> my_test_multi = {1,2,3};
    s21::multiset<int> my_test_multi = {1, 2, 3, 1, 2 ,3 ,3, 1, 2, 2, 2, 1, 1};
    std::multiset<int> orig_multi = {1, 2, 3, 1, 2, 3, 3, 1, 2, 2, 2, 1, 1};

    auto it_my = my_test_multi.begin();
    auto it_orig = orig_multi.begin();

    ++it_my;
    ++it_my;
    ++it_my;
    ++it_orig;
    ++it_orig;
    ++it_orig;
    my_test_multi.erase(it_my);
    orig_multi.erase(it_orig);

    auto it1_begin = my_test_multi.begin();
    auto it2_begin = orig_multi.begin();

    while (it1_begin != my_test_multi.end()) {
        std::cout << *it1_begin << " : " << *it2_begin << std::endl;
        
        ++it1_begin;
        ++it2_begin;
    }
}