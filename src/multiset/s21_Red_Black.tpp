
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
    //std::cout << "Left Rotate" << std::endl;
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
 //   std::cout << "Right  Rotate" << std::endl;

    node *pivot = n->left;
    pivot->parent = n->parent; /* при этом, возможно, pivot становится корнем дерева */
    if (n->parent != nullptr) {
        if (n->parent->left == n)
            n->parent->left = pivot;
        else
            n->parent->right = pivot;
    } else {
        head_element = pivot;
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

///////////////////////////////REMOVE///////////////////////////////////////////////

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::find_sibling(node *n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

template <class Key>
void BinaryTree<Key>::replace_node(node *n, node *child)
{
    child->parent = n->parent;
    if (n == n->parent->left)
    {
        n->parent->left = child;
    }
    else
    {
        n->parent->right = child;
    }
}

template <class Key>
void BinaryTree<Key>::delete_one_child(node *n)
{
    std::cout << "delete_one_child \n";
    node *child = (!n->right->left && !n->right->right) ? n->left : n->right;
    replace_node(n, child);
    if (n->color == BLACK)
    {
        if (child->color == RED)
            child->color = BLACK;
        else
            delete_case1(child);
    }
    delete n;
}

template <class Key>
void BinaryTree<Key>::delete_case1(node *n)
{
    std::cout << "delete_case1 \n";
    if (n->parent)
        delete_case2(n);
}

template <class Key>
void BinaryTree<Key>::delete_case2(node *n)
{
    std::cout << "delete_case2 \n";
    node *s = find_sibling(n);
    if (s->color == RED)
    {
        n->parent->color = RED;
        s->color = BLACK;
        if (n == n->parent->left)
            rotate_left(n->parent);
        else
            rotate_right(n->parent);
    }
    delete_case3(n);
}

template <class Key>
void BinaryTree<Key>::delete_case3(node *n)
{
    std::cout << "delete_case3 \n";
    node *s = find_sibling(n);

    if ((n->parent->color == BLACK) && (s->color == BLACK) &&
        (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        delete_case1(n->parent);
    }
    else
        delete_case4(n);
}

template <class Key>
void BinaryTree<Key>::delete_case4(node *n)
{
    std::cout << "delete_case4 \n";
    node *s = find_sibling(n);

    if ((n->parent->color == RED) && (s->color == BLACK) &&
        (s->left->color == BLACK) && (s->right->color == BLACK))
    {
        s->color = RED;
        n->parent->color = BLACK;
    }
    else
        delete_case5(n);
}

template <class Key>
void BinaryTree<Key>::delete_case5(node *n)
{
    std::cout << "delete_case5 \n";
    node *s = find_sibling(n);

    if (s->color == BLACK)
    { /* this if statement is trivial,
due to case 2 (even though case 2 changed the sibling to a sibling's child,
the sibling's child can't be red, since no red parent can have a red
child).
*/
        /* the following statements just force the red to be on the left of the
        left
           of the parent, or right of the right, so case six will rotate
           correctly.
         */
        if ((n == n->parent->left) && (s->right->color == BLACK) &&
            (s->left->color == RED))
        {
            /* this last test is trivial too due to cases 2-4. */
            s->color = RED;
            s->left->color = BLACK;
            rotate_right(s);
        }
        else if ((n == n->parent->right) && (s->left->color == BLACK) &&
                 (s->right->color == RED))
        {
            /* this last test is trivial too due to cases 2-4. */
            s->color = RED;
            s->right->color = BLACK;
            rotate_left(s);
        }
    }
    delete_case6(n);
}

template <class Key>
void BinaryTree<Key>::delete_case6(node *n)
{
    std::cout << "delete_case6 \n";
    node *s = find_sibling(n);

    s->color = n->parent->color;
    n->parent->color = BLACK;

    if (n == n->parent->left)
    {
        s->right->color = BLACK;
        rotate_left(n->parent);
    }
    else
    {
        s->left->color = BLACK;
        rotate_right(n->parent);
    }
}
