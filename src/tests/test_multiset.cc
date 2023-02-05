#include "../multiset/s21_multiset.h"
#include <gtest/gtest.h>



TEST(Multiset, test1_base)
{
    s21::multiset<int>  my_test_multi;
    my_test_multi.insert(1);
    EXPECT_EQ(1, *my_test_multi.begin());
    my_test_multi.erase(my_test_multi.begin());
    EXPECT_EQ(0, my_test_multi.size());
}


TEST(Multiset, test1)
{
    s21::multiset<int>  my_test_multi = {1, 2,3,4,1};
    my_test_multi.insert(1);
    int size = (int)my_test_multi.size();
    EXPECT_EQ(6, size);

    int bbbool = (int)my_test_multi.contains(2);
    int bbbool2 = (int)my_test_multi.contains(6);
    EXPECT_EQ(bbbool, 1);
    EXPECT_EQ(bbbool2, 0);


    my_test_multi.clear();
    EXPECT_EQ(0, my_test_multi.size());
   


}

TEST(Multiset, test1_clean1)
{
    s21::multiset<int>  my_test_multi;
    my_test_multi.clear();
}


//ITERATORS!!!!

TEST(Multiset, test_insert_1)
{
    std::multiset<int> obj;
    s21::multiset<int> k;
      
    srand(time(NULL));
    for (int i = 0; i < 7; i++) {
        auto value_rand = rand() %20;
        k.insert(value_rand);
        obj.insert(value_rand);
    }
    std::cout << std::endl;
    auto it_or = obj.begin();
        auto itm = k.begin();
    while(itm != k.end()) {
        EXPECT_EQ(*itm, *it_or);
        ++itm; it_or++;
    }

    it_or = obj.begin();
    itm = k.begin();
    it_or++; it_or++;
    ++itm; ++itm;

    k.erase(itm);
    obj.erase(it_or);

    it_or = obj.begin();
    itm = k.begin();
  
    while(itm != k.end()) {
        EXPECT_EQ(*itm, *it_or);
        ++itm; ++it_or;
    }

}

TEST(Multiset, erase_empty)
{
    s21::multiset<int>  my_test_multi;
   my_test_multi.erase(my_test_multi.begin());
}



// TEST(Multiset, find)
// {
//     s21::multiset<int>  my_test_multi;
//    my_test_multi.erase(my_test_multi.begin());
// }
