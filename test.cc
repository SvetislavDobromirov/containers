#include <iostream>
#include <cmath>
#include <stdio.h>

int main(){
   unsigned long pppow = 2;
   for (int i = 0; i < 64-sizeof(int); i++){
        pppow = pppow*2;
   } 
   pppow -=1;
   std::cout << pppow;
   
return 0;
}