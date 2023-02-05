#include <initializer_list>
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

#include <ctime>

int main() {
 {   
    // s21::multiset<int> k  = { 2, 7, 5, 5, 5, 18, 0 };
     //s21::multiset<int> k  = { 2, 7, 5, 5, 5, 18};//, 0 };
      s21::multiset<int> k  = { 4, 3, 2, 2, 2, 1};
     //  s21::multiset<int> k  = { 3,2,1 };
      
    // s21::multiset<int> k;
     //k.insert(3);
        std::cout << "Del : " << std::endl;
        std::cout.flush();
k.dump2(k.get_head());
         auto it_my  = k.begin();
         while( it_my != k.end()) {
              std::cout  << *it_my << std::endl;
              ++it_my;
         }
        std::cout << "Find: " << *k.find(4) << std::endl;
        std::cout << "Count: " << k.count(2) << std::endl;
        std::cout << "Contains? : " << k.contains(10) << std::endl;

    //     std::cout << "Del : " << *it_my << std::endl;
    //     k.dump2(k.get_head());   
    //     std::cout << std::endl << std::endl;   
    //     k.erase(it_my);
        
    //   for (int x = 0; x<4; x++) {
    //     it_my  = k.begin();
    //     std::cout << "Del : " << *it_my << std::endl;
        
    //     k.dump2(k.get_head());  
    //     std::cout << std::endl << std::endl;   
    //     k.erase(it_my);
    //   }


 }

return 0;
}