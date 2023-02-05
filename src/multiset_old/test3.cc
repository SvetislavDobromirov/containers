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
    typedef std::multiset<std::string>::iterator It;  // aliasing the iterator type used

    std::multiset<std::string> m_set;
    
    m_set.insert("one");
    m_set.insert("two");
    m_set.insert("one");

    std::pair <It, It> pair = m_set.equal_range("");
    std::cout << *pair.first << std::endl;
    std::cout << *pair.second << std::endl;


//    std::multiset<int> m_set2 = {1, 3, 6, 9};
     std::multiset<int> m_set2 = {1, 2, 3};
    std::cout << *m_set.lower_bound("z") << std::endl;
    


}