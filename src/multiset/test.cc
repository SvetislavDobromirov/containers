#include "s21_multiset.h"
#include <set>
#include <iostream>

int main(){
    std::multiset<int> multi = {1,5,-1,4,5,656};
    auto it = multi.begin();
    it++;
    std::cout << *it;
    s21::multiset<int> my_multiset;
    my_multiset.insert(4);

    return 0;
}