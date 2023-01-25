
template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::grandparent(node *n)
{
    if ((n != nullptr) && (n->parent != nullptr))
        return n->parent->parent;
    else
        return nullptr;
}

template <class Key>
typename BinaryTree<Key>::node *BinaryTree<Key>::uncle(node *n)
{
    node *g = grandparent(n);
    if (g == nullptr)
        return nullptr; // No grandparent means no uncle
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

template <class Key>
void BinaryTree<Key>::rotate_left(node *n)
{
    std::cout << "Left Rotate" << std::endl;
    node *pivot = n->right;
    // меняемся родителями
    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    
    // если не корень
    if (n->parent != nullptr) {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    } else {
        head_element = pivot;
    }

    n->right = pivot->left;
    if (pivot->left != nullptr)
        pivot->left->parent = n;

    n->parent = pivot;
    pivot->left = n;
   // head_element = pivot;
}


template <class Key>
void BinaryTree<Key>::rotate_right(node *n)
{
    std::cout << "Right  Rotate" << std::endl;

    node *pivot = n->left;
    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    }

    n->left = pivot->right;
    if (pivot->right != nullptr)
        pivot->right->parent = n;

    n->parent = pivot;
    pivot->right = n;
}

template <class Key>
void BinaryTree<Key>::insert_case1(node *n) {
    if (n->parent == nullptr)
        n->color = BLACK;
    else
        insert_case2(n);
}
template <class Key>
void BinaryTree<Key>::insert_case2(node *n)
{
    if (n->parent->color == BLACK)
        return; /* Tree is still valid */
    else
        insert_case3(n);
}

template <class Key>
void BinaryTree<Key>::insert_case3(node *n)
{
    node *u = uncle(n), *g;
    if ((u != nullptr ) && (u->color == RED)) {
        // && (n->parent->color == RED) Второе условие проверяется в insert_case2, то есть родитель уже является красным.
        n->parent->color = BLACK;
        u->color = BLACK;
        g = grandparent(n);
        g->color = RED;
        insert_case1(g);
    } else {
        insert_case4(n);
    }
}

template <class Key>
void BinaryTree<Key>::insert_case4(node *n)
{
     node *g = grandparent(n);

    if ((n == n->parent->right) && (n->parent == g->left)) {
        rotate_left(n->parent);
        n = n->left;

    } else if ((n == n->parent->left) && (n->parent == g->right)) {
        rotate_right(n->parent);
        n = n->right;
    }
    insert_case5(n);
}

template <class Key>
void BinaryTree<Key>::insert_case5(node *n) {
    node *g = grandparent(n);
    n->parent->color = BLACK;
    g->color = RED;
    if ((n == n->parent->left) && (n->parent == g->left)) {
        rotate_right(g);
    } else {
        rotate_left(g);
    }
}