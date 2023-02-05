

using namespace s21;


template <class Key>
multiset<Key>::multiset() : BinaryTree<Key>()
{
      size_of_elements = 0;
      

}

template <class Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items) : BinaryTree<Key>()
{
   for (auto p = items.begin(); p != items.end(); p++) {
         insert(*p);
   }
}
template <class Key>
multiset<Key>::~multiset() {
    this->clear();
}