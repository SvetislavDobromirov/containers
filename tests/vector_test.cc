#include <vector>
#include "../s21_vector.h"

TEST(reload_sq_breaks, Test_1) {
    vector<int> obj = {1,2,3,4,5};
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
    vector<int> obj;
    Vector<int> obj_V;
    obj.push_back(4);
    obj_V.push_back(4);
    EXPECT_EQ(obj[4], obj_V[4]);
    for (int i = 0; i < 129; i++) obj.push_back(i);
    for (int i = 0; i < 129; i++) obj.push_back(i);
    EXPECT_EQ(obj[129], obj_V[129]);
}