
#include <iostream>
#include <list>
#include "../list/s21_list.h"
#include <gtest/gtest.h>

using namespace s21;

TEST(memory_test, Test_1) {

  list<int> obj;

  list<int>::ListIterator it_my = obj.begin();
  for(int i = 0; i < 4; i++)
    obj.insert(it_my, i);

 
  for (auto i = obj.begin(); i != obj.end(); i++) {

  }
}

TEST(insert_element, Test_1) {
 std::list<int> orig;
  list<int> obj;

 std::list<int>::iterator it_original = orig.begin();
  list<int>::ListIterator it_my = obj.begin();

  for(int i = 0; i < 5; i++)
    orig.insert(it_original,  i);
 
  for(int i = 0; i < 5; i++)
    obj.insert(it_my, i);

  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++) {
    EXPECT_EQ(*i, *i2);
    i2++;
  }
}


TEST(push_front, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 0; i < 5; i++)
    orig.push_front(i);
 
  for(int i = 0; i < 5; i++)
    obj.push_front(i);
    

  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++) {
    EXPECT_EQ(*i, *i2);
    i2++;
  }
}

TEST(push_back, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 2; i < 7; i++)
    orig.push_back(i);
 
  for(int i = 2; i < 7; i++)
    obj.push_back(i);

  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++) {
    EXPECT_EQ(*i, *i2);
    i2++;
  }
}


TEST(push_back2, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 2; i < 7; i++)
    orig.push_back(i);
 
  for(int i = 2; i < 7; i++)
    obj.push_back(i);

  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++) {
    EXPECT_EQ(*i, *i2);
    i2++;
  }
}


TEST(pop_front2, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 2; i < 4; i++)
    orig.push_back(i);
  orig.pop_back();

  for(int i = 2; i < 5; i++)
    obj.push_back(i);
  obj.pop_front();
}

TEST(sort, Test_1) {
 std::list<int> orig;
  list<int> obj;
 
  for(int i = 0; i < 15; i++)
    orig.push_front(i);
  
  for(int i = 0; i < 15; i++)
    obj.push_front(i);
  

  orig.sort();
  obj.sort();
  
  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++) {
    EXPECT_EQ(*i, *i2);
    i2++;
  }

}

TEST(reverse, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 1; i < 5; i++)
    orig.push_front(i);
  
  for(int i = 1; i < 5; i++)
    obj.push_front(i);
  
  
  obj.reverse();
 
 
}


TEST(clear_and_company, Test_1) {
  list<int> obj;

list<int>::ListIterator it_my = obj.begin();

  for(int i = 0; i < 5; i++)
    obj.insert(it_my, i);
  obj.clear();
}


TEST(pop_back, Test_1) {
 std::list<int> orig;
  list<int> obj;

  for(int i = 2; i < 4; i++)
    orig.push_back(i);
  orig.pop_back();

  for(int i = 2; i < 4; i++)
    obj.push_back(i);
 obj.pop_back();
  
  auto i2 = orig.begin();
  for (auto i = obj.begin(); i != obj.end(); i++)
    EXPECT_EQ(*i, *(i2++));
}


TEST(unique, Test_1) {
  list<int> obj = {1,1,2,3,3,3,4,5,6,6,6};
  obj.unique();
  int current = 0;
  for (auto i = obj.begin(); i != obj.end(); i++)
    EXPECT_EQ(*i, ++current);

}


TEST(merge, Test_1) {
  list<int> list1 = {1,2,3};
  list<int> list2 = {4,5,6};

  list1.merge(list2);

  int current = 0;
  for (auto i = list1.begin(); i != list1.end(); i++)
    EXPECT_EQ(*i, ++current);
}

TEST(swap, Test_1) {
    list<int> list1 = {5,6,3};
    list<int> list2 = {1,2,3,4,5,6};
    list1.swap(list2);  
    int current = 0;
    for (auto i = list1.begin(); i != list1.end(); i++)
      EXPECT_EQ(*i, ++current);
}

TEST(copy, Test_1) {
  list<int> list2 =  {1,2,3,4,5,6}; 
  list<int> list1(list2);
  int current = 0;
  for (auto i = list1.begin(); i != list1.end(); i++)
      EXPECT_EQ(*i, ++current);
  EXPECT_EQ(6, current);
}

TEST(move, Test_1) {
  list<int> list2 =  {1,2,3,4,5,6}; 
  list<int> list1((list<int> &&)list2);
  int current = 0;
  for (auto i = list1.begin(); i != list1.end(); i++)
      EXPECT_EQ(*i, ++current);
}


TEST(sim, Test_5) {
  list<int> list2;
  list<int > list1(list2);
  auto i2 = list1.begin();
  for (auto i = list2.begin(); i != list2.end(); i++) {
      EXPECT_EQ(*i, *i2);
      i2++;
   }
}

TEST(list_terrible_case1, Test_22)
{
  list<std::string> list2 = {"one", "two", "three"};
  list<std::string> list1 = {"4", "5", "6"};
   list1.swap(list2);

   std::string one = "one";
   EXPECT_EQ(*(list1.begin()), one);
   std::string two = "two";
   EXPECT_EQ(*(++list1.begin()), two);
}

TEST(list_terrible_case_2, Test_5)
{
   std::list<std::string> orig = {"one", "two", "three"};
   list<std::string> obj = {"one", "two", "three"};
   orig.sort();
   obj.sort();


   auto i2 = orig.begin();
   for (auto i = obj.begin(); i != obj.end(); i++)
   {
      EXPECT_EQ(*i, *i2);
      i2++;
   }
}

TEST(list_front_back, Test_1)
{
   std::list<std::string> orig = {"one", "two", "three"};
   list<std::string> obj = {"one", "two", "three"};
   EXPECT_EQ(orig.front(), obj.front());
   EXPECT_EQ(orig.back(), obj.back());
}

TEST(list_par_con, Test_1)
{
   list<int> obj(5) ;
   EXPECT_EQ(5, obj.size());
}

TEST(list_splice, Test_1)
{
   list<int> obj = {1, 2, 6};
   list<int> obj2 = {3, 4, 5};
   auto it = obj.begin();
   it++;
   obj.splice(it, obj2);
   int count = 1;
   for (auto i = obj.begin(); i != obj.end(); i++)
      EXPECT_EQ(count++, *i);
}

TEST(emplaces, Test_1)
{
  list<int> obj;
  obj.emplace_front(1,2,3);
  obj.emplace_back(7, 8, 9);
  auto cit = obj.begin();
  cit++; cit++; cit++;
  obj.emplace(cit, 4, 5, 6);

  unsigned long count = 1;
  auto it = obj.begin();
  for (it; it != obj.end(); it++) {
    EXPECT_EQ(*it, count);
    count++;
  }
    EXPECT_EQ(obj.max_size(), obj.max_size());
}


TEST(const_it, Test_1)
{
  list<int> obj {1,2,3,4,5,6};

  auto cit = obj.begin();
  ++cit; --cit;


}