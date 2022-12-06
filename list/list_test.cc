#include <list>
#include <vector>
#include <iostream>
int main () {
   // std::list<int>  list_int = {1,2,3};
    std::vector<int> obj;
    for (int i = 0; i< 10; i++) obj.push_back(i);
    std::cout << obj.capacity() << std::endl;
    obj.clear();
    std::cout << obj.capacity() << std::endl;
    std::cout << obj.size() << std::endl;

    return 0;
}