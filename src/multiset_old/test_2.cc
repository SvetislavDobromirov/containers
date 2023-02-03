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
     s21::multiset<int> k  = { 2, 7, 5, 5, 5, 18, 0 };

        auto it_my  = k.begin();
        std::cout << "Del : " << *it_my << std::endl;
        k.dump2(k.get_head());   
        std::cout << std::endl << std::endl;   
        k.erase(it_my);
        
      for (int x = 0; x<4; x++) {
        it_my  = k.begin();
        std::cout << "Del : " << *it_my << std::endl;
        
        k.dump2(k.get_head());  
        std::cout << std::endl << std::endl;   
        k.erase(it_my);
      }


 }

return 0;
}