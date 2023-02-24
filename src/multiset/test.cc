#include "s21_multiset.h"
#include <initializer_list>
//#include <set>
#include <iostream>
#include <set>
//#include <vector>
//#include "../vector/s21_vector.h"

#include <stdlib.h>
//#include <iostream>
#include <chrono>
#include <time.h>

#include <ctime>

int main() {

  //  s21::multiset<int> multi;

  std::multiset<int> obj;
  s21::multiset<int> k;
  std::cout << k.max_size() << std::endl;
  std::cout << obj.max_size() << std::endl;
  //  auto it = obj.begin();
  // std::cout << *it << std::endl;

  return 0;
}