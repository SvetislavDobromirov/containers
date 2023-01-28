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
        //auto it = obj.begin();
       // std::cout << *it << std::endl;
        s21::multiset<int> k;


        
      
        srand(time(NULL));
        for (int i = 0; i < 100; i++){
          auto value_rand = rand() %20;
          k.insert(value_rand);
          obj.insert(value_rand);
          std::cout << value_rand << "v ";
        }
    std::cout<< std::endl;
    auto it_my  = k.begin();
    auto it_or = obj.begin();
    std::cout << *it_or << " " << *it_my << std::endl;

 // k.dump2(k.get_head());

    for (int i = 0; i < 100; i++){
      std::cout << *it_or << " - " << *it_my;
      printf("  %p\n", it_my.ptr_);
      ++it_or; ++it_my;
    }


     // k.dump2(k.get_head());

      
        return 0;
}