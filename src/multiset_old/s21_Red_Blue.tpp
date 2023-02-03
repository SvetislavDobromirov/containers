
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
    std::cout << "Left Rotate END" << std::endl;
    fflush(stdout);
   // dump2(head_element);
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
bool BinaryTree<Key>::is_both_children_black(node *n) {
        bool condition = true;
    // Если существует элементы левый или правый, то смотрим цвет
    //// если черные оба, то ок
    // Если элементов не существует, то условно цвет черный и ок
    if (n->left && n->right) {  // Если существуют
        // и если один из них красный, тогда
        if (n->left->color == RED || n->right->color == RED)
            condition = false;
    } // в остальный случаях элемент либо нулевой либо мнимый, а значит обв черный

   //if (n->color == DELETE) condition = false;
    return condition;
}


template <class Key>
typename  BinaryTree<Key>::node * BinaryTree<Key>::sibling(node *n)
{
                std::cout << "SIBLING!" << std::endl;
                std::cout.flush();

    if (n->parent) { 
        if (n->parent->left) {
            if (n == n->parent->left)
                return n->parent->right;
        } else if  (n->parent->right) {
            return n->parent->left;
        } else {
            std::cout << "ERROR in SIBLING!" << std::endl;
            exit(0);
            
        }
    }
}


template <class Key>
void  BinaryTree<Key>::replace_node(node* n, node* child) {
    node * end = nullptr;
    // 0 - left
    // 1 - right
    bool side = 0;
    // при замещении необходимо учитывать еще где именно может быть нулевой элемент
    if (n->left == this->end_element ||  n->right == this->end_element){
            end = this->end_element; 
        n->left == this->end_element ? side = 0 : side = 1;
    }

    child->parent = n->parent;
 std::cout << "replace_node ";
 std::cout.flush();
 //print_element(n);
    // учитываются ли конечные элементы?
    if (n->parent){
        if (n == n->parent->left) {
            n->parent->left = child;
        } else {
            n->parent->right = child;
        }
    }

    side == 0 ? child->left = end : child->right = end;
}

template <class Key>
void BinaryTree<Key>::delete_one_child(node *n)
{
	/*
	 * Условие: n имеет не более одного ненулевого потомка.
	 */

    // Определяем предка, учитывая конечные элементы
    // Можно перейти на листок, только есть есть действительный элемент

	//node *child = n->right ? n->right : n->left;
    
    node *child = nullptr;
    //   std::cout << "delete_one_child_1:: " << std::endl;
        std::cout << "Delete one child run" << std::endl;
std::cout.flush();
// TODO:первые два условия определяют на какой ветке есть элемент 
    if (n->right && n->right != end_element)  child = n->right;
    else if (n->left && n->left != end_element) child = n->left;
    else { 
        std::cout << "Error delete one child конечный элемент" << std::endl;

        node *to_delete = n;

        node * end = nullptr;
        if (n->left == this->end_element || n->right == this->end_element)
        end = this->end_element;      

        std::cout << "200:" << std::endl;
       // this->print_element(n);
        std::cout.flush();

      //  n->color = DELETE;

        delete_case1(n);

        std::cout.flush();
        std::cout << "203:" << std::endl;
        // TODO: скрепляет end 
        if (to_delete->parent->left == to_delete) to_delete->parent->left =  end;
        else to_delete->parent->left =  end;


        return;
    }
    
       //  std::cout << "delete_one_child_2:: " << std::endl;

	replace_node(n, child);

	if (n->color == BLACK) {
		if (child->color == RED)
			child->color = BLACK;
		else
			delete_case1(child);
	}

	delete n;
}

template <class Key>
void BinaryTree<Key>::delete_case1( node *n)
{
     std::cout << "d_case_1 ";
      std::cout.flush();
	if (n->parent != nullptr)
		delete_case2(n);
}


template <class Key>
void BinaryTree<Key>::delete_case2( node *n)
{
    
    std::cout << "d_case_2 ";
    std::cout.flush();
	
    node *s = sibling(n);
    
    std::cout << "d_case_2 1 ";
    std::cout.flush();
	
    if (s->color == RED) {
		n->parent->color = RED;
		s->color = BLACK;
		if (n == n->parent->left){
            std::cout << "d_case_2 1 " << std::endl;
            //print_element(n->parent);
			rotate_left(n->parent);
            std::cout << "d_case_2 2 " << std::endl;
        } else {
			rotate_right(n->parent);
        }
	} 

    std::cout << "d_case_2 END ";
    std::cout.flush();

	delete_case3(n);
}


template <class Key>
void BinaryTree<Key>::delete_case3( node *n)
{
         std::cout << "d_case_3 ";
         std::cout.flush();

	node *s = sibling(n);

    std::cout << "d_case_3_1 " << std::endl;
    std::cout.flush();
//print_element(s);

    bool condition = true;
    // Если существует элементы левый или правый, то смотрим цвет
    //// если черные оба, то ок
    // Если элементов не существует, то условно цвет черный и ок
  print_element(s);
  print_element(n);

	if (
            (n->parent->color == BLACK) &&
	        (s->color == BLACK) && 
            is_both_children_black(s) 
            //&& n->color != DELETE
	        //(s->left->color == BLACK) &&
	        //(s->right->color == BLACK)
        )
    {
            std::cout << "d_case_3_2 " << std::endl;
     std::cout << (n->parent->color == BLACK) << " " << (s->color == BLACK) << " " << is_both_children_black(s) << std::endl;
    std::cout.flush();
        print_element(s);
        dump2(head_element);
		s->color = RED;
        
        delete_one_child(n->parent);
		//delete_case2(n->parent);
	} else
		delete_case4(n);
}


template <class Key>
void BinaryTree<Key>::delete_case4( node *n)
{
         std::cout << "d_case_4 ";
         std::cout.flush();

	 node *s = sibling(n);

	if (
            (n->parent->color == RED) &&
	        (s->color == BLACK) &&
             is_both_children_black(s)
            //   && n->color != DELETE
	        // (s->left->color == BLACK) &&
	        // (s->right->color == BLACK)
        )
    {
		s->color = RED;
		n->parent->color = BLACK;
	} else {
          std::cout << "d_case_4_to_5 ";
         std::cout.flush();
		delete_case5(n);
    }
}


template <class Key>
void BinaryTree<Key>::delete_case5( node *n)
{
         std::cout << "d_case_5 ";
         std::cout.flush();

	 node *s = sibling(n);

     std::cout << "d_case_5_1 " << std::endl;
         std::cout.flush();
//print_element(s);
	if  (s->color == BLACK) { /* this if statement is trivial, 
due to case 2 (even though case 2 changed the sibling to a sibling's child, 
the sibling's child can't be red, since no red parent can have a red child). */
/* the following statements just force the red to be on the left of the left of the parent, 
   or right of the right, so case six will rotate correctly. */

         std::cout << "d_case_5_2 ";
         std::cout.flush();
         print_element(n);
		if (
                (n == n->parent->left) &&
                 is_both_children_black(s) 
		        // (s->right->color == BLACK) &&
		        // (s->left->color == RED)
           )
        {
            /* this last test is trivial too due to cases 2-4. */
			s->color = RED;
			s->left->color = BLACK;
			rotate_right(s);
		} else if (
                (n == n->parent->right) &&
                 is_both_children_black(s)
		        // (s->left->color == BLACK) &&
		        // (s->right->color == RED)
            ) 
        {
            /* this last test is trivial too due to cases 2-4. */
			s->color = RED;
			s->right->color = BLACK;
			rotate_left(s);
		}
	}

         std::cout << "d_case_5_to_6";
         std::cout.flush();
	delete_case6(n);
}


template <class Key>
void BinaryTree<Key>::delete_case6(node *n)
{
    std::cout << "d_case_6 ";

	 node *s = sibling(n);

	s->color = n->parent->color;
    n->parent->color = BLACK;

	if (n == n->parent->left) {
        s->right->color = BLACK;
		rotate_left(n->parent);
	} else {
		s->left->color = BLACK;
		rotate_right(n->parent);
	}
}