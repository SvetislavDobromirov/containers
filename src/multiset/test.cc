#include "s21_multiset.h"
//#include <set>
#include <iostream>
#include <set>
//#include <vector>
//#include "../vector/s21_vector.h"

int main(){
    s21::multiset<int> multi;
  //  std::vector<int> obj;
//    std::vector<int>::iterator it;
    // multi.insert(1);
    // multi.insert(2);
    // multi.insert(3);
    multi.insert(3);
   multi.insert(2);
   multi.insert(1);
//     multi.insert(7);
//     multi.insert(8);
    
    // multi.insert(5);
     //multi.insert(10);
    // multi.insert(0);
    auto it = multi.begin();
    // static std::string  ch_hor = "-", ch_ver = "|", ch_ddia = "/", ch_rddia = "\\",
    //                     ch_udia = "\\", ch_ver_hor = "|-", ch_udia_hor = "\\-", 
    //                     ch_ddia_hor = "/-", ch_ver_spa = "| ";
    multi.dump2(multi.get_head());
    // std::cout << *it << std::endl;
    // std::cout << *multi.end() << std::endl;
    // printf("Element: %d : %p\n\t Parent: %p \n\t Left: %p \n\t Right %p \n\n",  it.ptr_->data, it.ptr_ , it.ptr_->parent, it.ptr_->left, it.ptr_->right);

    // auto it_end = multi.end();
    // while(it != it_end){
    //     std::cout << *it << std::endl;
    //     printf("Element: %d : %p\n\t Parent: %p \n\t Left: %p \n\t Right %p \n\n",  it.ptr_->data, it.ptr_ , it.ptr_->parent, it.ptr_->left, it.ptr_->right);
    //     ++it;
    // }

    // for (int i = 0; i < 10;  i ++){
    //          std::cout << *it << std::endl;
    //     printf("Element: %d : %p\n\t Parent: %p \n\t Left: %p \n\t Right %p \n\n",  it.ptr_->data, it.ptr_ , it.ptr_->parent, it.ptr_->left, it.ptr_->right);
    //     ++it;
    // }

//  ++it;
//     std::cout << *it << std::endl;
//     printf("Element: %d : %p \n\tParent: %p \n\t Left: %p \n\t Right %p \n\n",  it.ptr_->data, it.ptr_, it.ptr_->parent, it.ptr_->left, it.ptr_->right);


//  ++it;
//     std::cout << *it << std::endl;
//     printf("Element: %d : %p \n\tParent: %p \n\t Left: %p \n\t Right %p \n\n",  it.ptr_->data, it.ptr_, it.ptr_->parent, it.ptr_->left, it.ptr_->right);


   // printf("%d", *it);
    // multi.insert(2);
    // multi.insert(4);
    // multi.insert(3);
/*
{
    std::multiset<int>  my_set  = {4,2,4,5,1};
    auto it = my_set.begin();
    std::cout << std::endl << *it << std::endl;
    it++; 
    std::cout << std::endl << *it << std::endl;
    it++; 
    std::cout << std::endl << *it << std::endl;
    it++; 
    std::cout << std::endl << *it << std::endl;
    it++; 
    std::cout << std::endl << *it << std::endl;
    it++; 



}
*/
    return 0;
}