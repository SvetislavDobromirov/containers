#include <iostream>
#include <list>
#include "s21_list.h"

int main(){
    
   
    list<int> obj = {1, 2, 3};
    list<int> obj2 = {10, 20, 30};
    auto it = obj.begin();
   // std::advance(it, 2);
    //it++;
    it++;
    obj.splice(it, obj2);

  
        return 0;
}


