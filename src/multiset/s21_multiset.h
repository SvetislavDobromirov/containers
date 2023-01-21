#include "s21_binary_tree.h"
#include <initializer_list>

namespace s21 {
    template <class Key>
    class multiset : public BinaryTree<Key> {
        public:
            using key_type = Key;
            using value_type = key_type;
        
            using const_reference = const Key &;
            using iterator = typename BinaryTree<Key>::iterator;
            using node_m = typename BinaryTree<Key>::node;
        // using const_iterator = typename BinaryTree<Key>::const_iterator;
            iterator insert(const value_type& value);

            multiset();
           // multiset(std::initializer_list<value_type> const &items);
            //multiset(const multiset &ms);
            //multiset(multiset &&ms);
            //~multiset();
            //operator=(multiset &&ms);
            iterator begin();
            iterator end();

        
        private:
            node_m * go_to_left(node_m * cur) {
                while (cur->left != nullptr)
                    cur = cur->left;
                return cur;
            }
            node_m * go_to_right(node_m * cur) {
                while (cur->right != nullptr)
                    cur = cur->right;
                return cur;
            }

        // typename s21::BinaryTree<Key>::node *head;
    };

template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>() {
    if (this->head_element  == nullptr) {
        std::cout << "Голова нулевая. Все под контролем" << std::endl;
    }
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::begin() {
    node_m * goal = this->head_element;
    goal = go_to_left(goal);
    // Проверяем есть и повторные элемент 
    if (goal->right){
        if (goal->right->data == goal->data) {
            goal = go_to_left(goal);
        } 
        if (goal->right->left) {
            if (goal->data == goal->right->left->data) {
                goal = goal->right->left;
            }
            goal = go_to_left(goal);
        } 
    } 
    iterator it;
    it.ptr_ = goal;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::end(){
    node_m *goal = this->head_element;
    goal = go_to_right(goal);
    if (goal->right){
        if (goal->right->data == goal->data) {
            goal = go_to_right(goal);
        } 
        if (goal->right->left) {
            if (goal->data == goal->right->left->data) {
                goal = goal->right->left;
            }
            goal = go_to_right(goal);
        } 
    }
    iterator it;
    it.ptr_ = goal;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    this->insert_to_tree(value);
    iterator it;
    return it;
}


}
// template <class Key>
// multiset<Key>::multiset(std::initializer_list<value_type> const &items){
//     // Здесь есть смысл использовать insert 
// }



