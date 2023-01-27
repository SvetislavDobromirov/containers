#include "s21_multiset.h"
//#include <set>
#include <iostream>
#include <set>
//#include <vector>
//#include "../vector/s21_vector.h"

#include <stdlib.h>
//#include <iostream>
#include <time.h>
#include <chrono>



int main() {

      //  s21::multiset<int> multi;
  
        std::multiset<int> obj;
        auto it = obj.begin();
        std::cout << *it << std::endl;
        s21::multiset<int> k;
        auto it2 = k.insert(10);        
        k.insert(11);
        k.insert(12);
        k.insert(13);
        k.insert(14);

        k.dump2(k.get_head());

        std::cout << *it2 << std::endl;

        return 0;
}