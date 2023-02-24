#include "s21_array.h"
#include "stdio.h"
#include <array>
#include <iostream>

int main() {

  std::array<int, 6> origin;
  s21::array<int, 6> my({1, 2, 3, 4, 5, 6});

  std::cout << origin.back();
  //    t = my.end();
  // printf("__%p__\n", t);
  // printf("__%d__\n", *t);
  // std::cout << *my.end() << " " << *origin.end() << " " << std::endl;

  return 0;
}