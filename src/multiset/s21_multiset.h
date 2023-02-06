#include "s21_binary_tree.h"
#include <initializer_list>
#include <limits>

namespace s21 {
    template <class Key>
    class multiset : public BinaryTree<Key> {
        public:
            using key_type = Key;
            using value_type = key_type;
        
            using const_reference = const Key &;
            using iterator = typename BinaryTree<Key>::iterator;
            using node_m = typename BinaryTree<Key>::node;
            using size_type = size_t;
            // using const_iterator = typename BinaryTree<Key>::const_iterator;
            iterator insert(const value_type& value);
            void erase(iterator pos) ;
            iterator find(const Key& key);
            size_type count(const Key& key);
            bool contains(const Key& key);
            std::pair<iterator,iterator> equal_range(const Key& key);
            iterator lower_bound(const Key& key);
            iterator upper_bound(const Key& key);
            bool empty();	
            size_type size();
            size_type max_size();
            void clear();
            void swap(multiset& other);
            void merge(multiset& other);


            multiset();
            multiset(std::initializer_list<value_type> const &items);
             multiset(const multiset &ms);
             multiset(multiset &&ms);
             ~multiset();
        //     operator=(multiset &&ms);
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
            
            void counter(node_m* current, size_t* size, const Key& key);
            void delete_tree(node_m *n);
            void copyrec(node_m* node);

        protected:
            size_type size_of_elements;

            // typename s21::BinaryTree<Key>::node *head;
    };

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::begin() {
    iterator it;
    if (this->head_element == nullptr) {
        it.ptr_ = nullptr;
        return it;
    }

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
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator multiset<Key>::end() {
    iterator it;

    if (this->head_element == nullptr) {
        it.ptr_ = nullptr;
        return it;
    }

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
    if (goal->right == nullptr) goal = nullptr;
    it.ptr_ = goal;
    return it;
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::insert(const value_type& value) {
    iterator it;

    this->insert_to_tree(value);
   //TODO: Сделать возврат итератора через find
    it.ptr_ = this->head_element;
    size_of_elements++;

    return it;
}

template <class Key>
size_t multiset<Key>::max_size(){
    return std::numeric_limits<std::ptrdiff_t>().max() /
        sizeof(node_m);
}

template <class Key>
typename BinaryTree<Key>::iterator  multiset<Key>::find(const Key& key) {
    node_m *current = this->head_element;
    while (1) {
        if (current == nullptr) break;
        if (current->data == key) break;
        if (key >= current->data) current = current->right;
        else current = current->left; 
    }
    iterator it;
    it.ptr_ = current;
    return it;
}
template <class Key>
void multiset<Key>::swap(multiset& other)	{
// копируем: головв, разммер
    auto temp_head = this->head_element;
    auto temp_size = this->size_of_elements;

    this->head_element = other->head_element;
    this->size_of_elements = other->size_of_elements;

    other->head_element = temp_head;
    other->size_of_elements = temp_size;
}

template <class Key>
void multiset<Key>::clear()	 {

    if (this->head_element) delete_tree(this->head_element);
    size_of_elements = 0;
    this->head_element = nullptr;
}

template <class Key>
void multiset<Key>::delete_tree(node_m* n) {
  if (n == nullptr) return;
  node_m *right = n->right;
  node_m *left = n->left;
  delete n;
  if (!right && !left) return;
  if(left != nullptr) delete_tree(left);
  if(right != nullptr) delete_tree(right);
}

template <class Key>
void multiset<Key>::merge(multiset<Key>& other) {
    auto it_other = other.begin();
   
         // TODO: Проверить если this или other пустые

    std::cout << "BEGIN ELEMENT: "  << *it_other << std::endl;
    while  (it_other != other.end()){
    
        this->head_element =  this->insert_avl(this->head_element, *it_other, it_other.ptr_, &other.head_element);  
        this->head_element->parent = nullptr;
        size_of_elements++;
        it_other =  other.begin();

    }
    // TODO: очистить other
}



template <class Key>
typename multiset<Key>::size_type  multiset<Key>::count(const Key& key) {
    size_t size = 0;
    counter(this->head_element, &size, key);
    return size;
}

template <class Key>
bool multiset<Key>::contains(const Key& key) {
    size_t size = 0;
    counter(this->head_element, &size, key);
    return size == 0 ? 0 : 1;
}


template <class Key>
void  multiset<Key>::counter(node_m* current, size_t* size, const Key& key) {
    if (!current)
        return ;
    if (current->right)
        counter(current->right, size, key);
    if (current->left)
        counter(current->left, size, key);
    if (current->data == key) (*size)++;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key) {
    auto it = begin();
    while(*it <= key)
        ++it;
    return it;
}

template <class Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key) {
    auto it = begin();
    while(*it<key ) 
        ++it;
    return it;
}


template <class Key>
std::pair<typename multiset<Key>::iterator, 
    typename multiset<Key>::iterator> multiset<Key>::equal_range(const Key& key) {
    typedef multiset<Key>::iterator It;
    std::pair<It, It> pair;
    auto it1 = find(key); // Можем получить nullptr,  в таком случае дальше не ищем
    auto it2 = it1;
    if (it1.ptr_ != nullptr) {
        while (*it1 == *it2)
            ++it2;
    } else {
        it2 = it1 = begin();
    }
    return std::make_pair(it1, it2);
}

template <class Key>
void multiset<Key>::erase(iterator pos) {
    
    if (pos.ptr_ == nullptr) return;
    this->head_element = this->remove(this->head_element, *pos, 0);
    size_of_elements--;
    //it.ptr_ = this->head_element;
    //TODO: Что если удаляем голову?

}


template <class Key>
bool multiset<Key>::empty() {
    return this->head_element?1:0;
}


template <class Key>
size_t multiset<Key>::size() {
    return size_of_elements;
}

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
        while (ptr_->left != nullptr)
            ptr_ = ptr_->left;
        
        return *this;
    }
    
    iterator operator++(int i) {
        i = 0;
        i++;
        ++(*this);
        return *this;
    }

    iterator operator--(int i) {
        i = 0;
        i++;
        --(*this);
        return *this;;
    }
    node *ptr_;
};


}


#include "s21_m_constructor.tpp"