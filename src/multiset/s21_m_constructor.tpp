

using namespace s21;


template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>()
{
      size_of_elements = 0;
}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) : BinaryTree<Key>()
{
   for (auto p = items.begin(); p != items.end(); p++)
         insert(*p);
}
template <class Key>
multiset<Key>::~multiset() {
    this->clear();
}

template <class Key>
multiset<Key>::multiset(const multiset<Key> &ms) : multiset() {
      node_m* now = ms.head_element;
      copyrec(now);
}

template <class Key>
void multiset<Key>::copyrec(node_m* node_){
   if (!node_)
        return;
    if (node_->right) {
      copyrec(node_->right);
    }
    insert(node_->data);
    
    if (node_->left)
      copyrec(node_->left);
}
template <class Key>
multiset<Key>::multiset(multiset &&ms) {
      this->head_element = ms.head_element;
      this->size_of_elements = ms.size();
      ms.head_element = nullptr;
      ms.clear();
}

template<class Key>
multiset<Key>& multiset<Key>::operator=(multiset &ms) {
if (this != &ms) {
    std::swap(this->head_element, ms.head_element);
  }
  return *this;
 }