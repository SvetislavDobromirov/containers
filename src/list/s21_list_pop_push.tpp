
using namespace s21;
template <class T> void list<T>::push_front(const T &value) {
  list::ListIterator it = begin();
  insert(it, value);
}

template <class T> void list<T>::push_back(const T &value) {
  list::ListIterator it = end();
  insert(it, value);
}

template <class T> void list<T>::pop_back() {
  list::ListIterator it = end();
  it--;
  erase(it);
}

template <class T> void list<T>::pop_front() {
  list::ListIterator it = begin();
  erase(it);
}
