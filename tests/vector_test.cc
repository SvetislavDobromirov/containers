
#include "../s21_vector.h"
#include <vector>
#include <iostream>
 
TEST(reload_sq_breaks, Test_1) {
    Vector<int> obj = {1,2,3,4,5};
    Vector<int> obj_V = {1,2,3,4,5};
    EXPECT_EQ(obj[1], obj_V[1]);
    EXPECT_EQ(obj.at(2), obj_V.at(2));
    EXPECT_ANY_THROW(obj_V[9]);
    EXPECT_ANY_THROW(obj_V.at(9));
    EXPECT_EQ(obj[0], obj_V[0]);
    EXPECT_EQ(obj.at(0), obj_V.at(0));
    EXPECT_ANY_THROW(obj_V.at(-1));
    EXPECT_ANY_THROW(obj_V[-1]);
   //EXPECT_TRUE(b.EqMatrix(c));
}


TEST (push_back, Test_1) {
    Vector<int> obj;
    std::vector<int> obj_V;
   unsigned long value_capasity = 0;
   
    for (int i = 0; i < 130; i++) obj.push_back(i);
    for (int i = 0; i < 130; i++) obj_V.push_back(i);
    EXPECT_EQ(obj.at(127), obj_V.at(127));
    EXPECT_EQ(obj[127], obj_V[127]);
    EXPECT_EQ(obj.capacity(), obj_V.capacity());
    EXPECT_EQ(obj.size(), obj_V.size());
    EXPECT_EQ(*(obj.begin()), *(obj_V.begin()));
    obj.clear();
    obj_V.clear();
    EXPECT_EQ(obj.size(), obj_V.size());
}

TEST (pop_back, Test_1) {
    Vector<int> obj;
    std::vector<int> obj_V;
    
    obj.push_back(1);
    obj_V.push_back(1);
  
    std::cout << obj.empty() << " : " << obj_V.empty;
    //EXPECT_EQ(obj.empty(), obj_V.empty());
    obj.pop_back();
    obj_V.pop_back();
    std::cout << obj.empty() << " : " << obj_V.empty;
    //EXPECT_EQ(obj.empty(), obj_V.empty());

  
}