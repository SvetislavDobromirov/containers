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
      //s21::multiset<int> k  = { 6, 3, 2, 2, 2, 1};
   //   s21::multiset<int> k  = { 1,2,3,4,5};
      // s21::multiset<int> k  = { 5,4,3,2,1};

      s21::multiset<int> k  = { 2,3 };
      printf("____%p", k.begin().ptr_);
  //  exit(1);
    // s21::multiset<int> k;
     //k.insert(3);
//         std::cout << "Del : " << std::endl;
//         std::cout.flush();
// k.dump2(k.get_head());
//          auto it_my  = k.begin();
//          while( it_my != k.end()) {
//               std::cout  << *it_my << std::endl;
//               ++it_my;
        
//          }
        
      //   std::cout << "Find: " << *k.find(6) << std::endl;
      //   std::cout << "Count: " << k.count(2) << std::endl;
      //   std::cout << "Contains? : " << k.contains(10) << std::endl;

      //   typedef s21::multiset<int>::iterator It;
      //   std::pair<It, It> pair = k.equal_range(10);
      //   std::cout << "Pair: " << *pair.first << " : " << *pair.second << std::endl;

      // std::cout << *k.lower_bound(2) << std::endl;
      
      // std::cout << *k.upper_bound(5) << std::endl;

   //    std::cout << "Empty? : " << k.empty()  << std::endl;
   //    std::cout << "Size : " << k.size() << std::endl;

   //    k.erase(k.find(3));
   //        //  k.erase(k.find(6));

  
   
      s21::multiset<int> y = {1, 2, 3};
   
       std::cout << std::endl << "DUMP" << std::endl;
       k.dump2(k.get_head());
      std::cout << std::endl << "DUMP" << std::endl;
      y.dump2(y.get_head());

      k.merge(y);
      std::cout << std::endl << "DUMP" << std::endl;
      k.dump2(k.get_head());

 }

return 0;
}