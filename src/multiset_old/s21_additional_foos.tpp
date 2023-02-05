
using namespace s21;




template <class Key>
void BinaryTree<Key>::print_element(node* El) {
    //printf("Print\n");
    if (El == nullptr) {
         printf("Нулевой элемент \n");
         return;
    }
    printf("Element:  %17p Parent: %17p  Left: %17p  Right: %17p Value: %3d Color: ",
           El, El->parent, El->left, El->right, El->data);
    
        
    if (El == head_element){
        printf("Head\n");
    }
    else
    {
        printf("\n");
    }
}
template <class Key>
void BinaryTree<Key>::dump2(node *node_) {
   

    if (!node_)
        return;
    if (node_->right)
        dump2(node_->right);
    print_element(node_);
    //std::cout << node_->data << std::endl;
    if (node_->left)
        dump2(node_->left);
}