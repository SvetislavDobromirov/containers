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
    typedef std::multiset<int>::iterator It;  // aliasing the iterator type used

    std::multiset m_set = {1, 2, 2, 2, 3, 4};
    std::pair <It, It> pair = m_set.equal_range(5);
    std::cout << *pair.first << std::endl;
    std::cout << *pair.second << std::endl;


}