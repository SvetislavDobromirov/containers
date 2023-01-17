#include "s21_binary_tree.h"
#include <initializer_list>

namespace s21{
template <class Key>
class multiset : public BinaryTree<Key>{
    public:
        using key_type = Key;
        using value_type = key_type;
       
        using const_reference = const Key &;
        using iterator = typename BinaryTree<Key>::iterator;
       // using const_iterator = typename BinaryTree<Key>::const_iterator;
        iterator insert(const value_type& value);

        multiset();
        multiset(std::initializer_list<value_type> const &items);
        //multiset(const multiset &ms);
        //multiset(multiset &&ms);
        //~multiset();
        //operator=(multiset &&ms);


        iterator begin();
        iterator end();


    private:
        s21::BinaryTree<int> tree;

};

template <class Key>
typename multiset<Key>::iterator multiset<Key>::begin(){
   // return tree.
}

template <class Key>
multiset<Key>::multiset(){
    // При создании объекта вызовется конструктор дерева
}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items){
    // Здесь есть смысл использовать insert 
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    // Надо обратиться к дереву и вставить новый элемент по правилам
    // Переходим к дереву, и кидаем в него элемент. Магия происходит внутри дерева
    if (tree.head_element == nullptr) { // Если в дереве нет элементов, то помещаем в голову

    }
    return tree.;
}



}
