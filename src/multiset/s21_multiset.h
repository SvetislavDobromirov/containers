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

            /// Methods
            iterator insert(const value_type& value);
            void clear();
            void erase(iterator pos);
            void swap(multiset &other);
            void merge(multiset &other);

            ///

            void erase_with_value(Key value);

            multiset();
            multiset(std::initializer_list<value_type> const &items);
            //     multiset(const multiset &ms);
            //     multiset(multiset &&ms);
            //     ~multiset();
            //     operator=(multiset &&ms);
            iterator begin();
            iterator end();

        private:
            node_m *go_to_left(node_m *cur)
            {
                while (cur->left != nullptr && cur->left != this->end_element)
                    cur = cur->left;
                return cur;
                }
                node_m *go_to_right(node_m * cur)
                {

                    while (cur->right != nullptr)
                        cur = cur->right;
                    return cur;
                }

            protected:
                // typename s21::BinaryTree<Key>::node *head;
            };

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::begin() {
    iterator it;
    if (this->head_element != this->end_element) {
        node_m *goal = this->head_element;
        goal = go_to_left(goal);
        // Проверяем есть и повторные элемент
        if (goal->right) {
            if (goal->right->data == goal->data) {
                Key check_value = goal->data;
                while (goal->right != nullptr)
                {
                    if (goal->right->data != check_value)
                        break;
                    goal = goal->right;
                }
            }
            else if (goal->right->left) {
                if (goal->data == goal->right->left->data)
                {
                    goal = goal->right->left;
                }
                goal = go_to_left(goal);
            }
        }
        it.ptr_ = goal;
    } else {
        it.ptr_ = this->end_element;
    }
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::end() {
    iterator it;
    if (this->head_element != this->end_element)
    {
        node_m *goal = this->head_element;
        goal = go_to_right(goal);
        if (goal->right) {
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
        it.ptr_ = goal;
       
    } else {
        it.ptr_ = this->end_element;
    }

   // it.ptr_ = this->end_element;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    iterator it;
    it.ptr_ =  this->insert_to_tree(value);
    return it;
}

template <class Key>
void multiset<Key>::clear() {

}




template <class Key>
void multiset<Key>::erase(iterator pos){

    printf("Pos pointer: %p\n", pos.ptr_);
   // this->delete_case1(pos.ptr_);


     this->delete_one_child(pos.ptr_);
     //this->dump2(this->get_head());
     //  erase_with_value()
}
/*
template <class Key>
void multiset<Key>::erase_with_value(Key value) {
    Key value = *pos;

    if (root->data == data)
    {
        if (!root->left->right && !root->left->left && !root->right->left &&
            !root->right->right)
        {
            std::cout << "if with 3 deletes \n";
            delete root->right;
            delete root->left;
            delete root;
            root = nullptr;
            return;
        }
        else if (!root->left->right && !root->left->left)
        {
            std::cout << "if with delete left \n";
            Node *right = root->right;
            delete root->left;
            delete root;
            root = right;
            return;
        }
        else if (root->right->left && !root->right->right)
        {
            std::cout << "if with delete right \n";
            Node *left = root->left;
            delete root->right;
            delete root;
            root = left;
            return;
        }
    }
}

*/
template <class Key>
    class BinaryTree<Key>::iterator
{
    friend BinaryTree;

public:
    reference operator*() {
        return ptr_->data;
    }

    iterator operator++()
    {
        // Сначала надо определить на какой ветке находится текущий поинтер
        //// первый случай если текущий элемент == мнимому элементу
        //// второй случай когда текущий элемент равен голове
        //// третий и четвертый случай это сравнения
        if (!this->ptr_) {
            this->ptr_ = nullptr; //
            while (this->ptr_->right) this->ptr_ = this->ptr_->right;
            } else if ((!this->ptr_->parent ||
                        this->ptr_ == this->ptr_->parent->right) &&
                    !this->ptr_->right) {
            while (this->ptr_->parent && this->ptr_->parent->right == this->ptr_)
                this->ptr_ = this->ptr_->parent;
            if (!this->ptr_->parent)
                this->ptr_ = nullptr;
            else
                this->ptr_ = this->ptr_->parent;
            } else {
            if (this->ptr_->right) {
                this->ptr_ = this->ptr_->right;
                while (this->ptr_->left) this->ptr_ = this->ptr_->left;
            } else {
                if (this->ptr_ == this->ptr_->parent->left)
                this->ptr_ = this->ptr_->parent;
                else
                this->ptr_ = this->ptr_->parent->parent;
            }
        }
        return *this;
    }

    bool operator!=(iterator in)
    {
        return in.ptr_ != this->ptr_;
    }

    iterator operator--()
    {
            if (!this->ptr_)
            {
                ++(*this);
            }
            else if (this->ptr_->left)
            {
                this->ptr_ = this->ptr_->left;
                while (this->ptr_->right)
                    this->ptr_ = this->ptr_->right;
            }
            else if (this->ptr_->parent &&
                     this->ptr_->parent->right == this->ptr_)
            {
                this->ptr_ = this->ptr_->parent;
            }
            else
            {
                while (this->ptr_->parent && this->ptr_->parent->right != this->ptr_)
                    this->ptr_ = this->ptr_->parent;
                if (this->ptr_->parent)
                    this->ptr_ = this->ptr_->parent;
                else
                    this->ptr_ = nullptr;
            }    
        return *this;
    }
   
    node *ptr_;
};


}

#include "s21_m_constructor.tpp"