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

   
      s21::multiset<int> my_test_multi = {1, 2, 3, 1, 2, 3};
   //   std::multiset<int> orig_multi = {1, 2, 3, 1, 2, 3, 3};

      auto it_my = my_test_multi.begin();
   //  auto it_orig = orig_multi.begin();

   //   my_test_multi.dump2(my_test_multi.get_head());


      ++it_my;
      ++it_my;
    //  ++it_my;
      std::cout << "it_my: " << *it_my << std::endl;
      // ++it_orig;
      // ++it_orig;
      // ++it_orig;
      my_test_multi.erase(it_my);
     // orig_multi.erase(it_orig);

      auto it1_begin = my_test_multi.begin();
     
      while (it1_begin != my_test_multi.end())
      {
            std::cout << *it1_begin << " : ";// << *it2_begin << std::endl;

            ++it1_begin;
         //   ++it2_begin;
      }
    // k.dump2(k.get_head());

    return 0;
}