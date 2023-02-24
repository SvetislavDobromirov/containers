using namespace s21;
template <class T> void list<T>::sort() {
  element_list *current = head_of_list_;
  int flag = 0;
  while (1) {
    while (1) {
      if (current->data_ > current->next_->data_) {
        swap_elements(current, current->next_);
        flag = 1;
      } else {
        current = current->next_;
      }
      if (current->next_ == end_of_list_)
        break;
    }
    if (flag == 0)
      break;
    flag = 0;
    current = head_of_list_;
  }
}

template <class T>
void list<T>::swap_elements(element_list *a, element_list *b) {

  if (a == b)
    throw std::out_of_range(
        "В функцию swap_element поступило два одинаковых элемента\n");
  if (a->before_ != nullptr) {
    a->before_->next_ = b;
  } else {
    b->before_ = nullptr;
    head_of_list_ = b;
  }
  a->next_ = b->next_;
  b->next_ = a;
  a->before_ = b;
  if (a->next_ != nullptr)
    a->next_->before_ = a;
}
