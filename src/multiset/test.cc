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

      //  s21::multiset<int> multi;
  
      std::multiset<int> obj;
      s21::multiset<int> k;
      
        //  auto it = obj.begin();
        // std::cout << *it << std::endl;
       // s21::multiset<int> k  = {14, 16, 14, 16, 5, 10, 0};
        srand(time(NULL));
        for (int i = 0; i < 7; i++) {
          auto value_rand = rand() %20;
          k.insert(value_rand);
          obj.insert(value_rand);
          std::cout << value_rand << "v ";
        }
        auto it_my  = k.begin();
        auto it_or = obj.begin();
        std::cout << *it_or << " " << *it_my << std::endl;
        obj.erase(it_or);
        k.erase(it_my);
        
      for (int x = 0; x<4; x++) {
        it_my  = k.begin();
        it_or = obj.begin();
        std::cout << *it_or << " : " << *it_my << std::endl;
        obj.erase(it_or);
        k.erase(it_my);
      }
        // 14 17 9 17 0 17 14 
        //k.erase(it_my);
      //  obj.erase(it_or);
        std::cout << "43::" << std::endl;

        it_my  = k.begin();
  //  it_or = obj.begin()
       
    std::cout << "47::" << std::endl;

     it_my  = k.begin();
        it_or = obj.begin();
  while (it_my != k.end()) {
      // k.print_element(it_my.ptr_);
      std::cout << *it_or << " - " << *it_my;
      printf("  %p\n", it_my.ptr_);
      ++it_or; 
      ++it_my;
           
    }
      k.dump2(k.get_head());
 

  {

  }
        return 0;
}