

template <class Key>
unsigned char BinaryTree<Key>::height(node* p)
{
	return p?p->height:0;
}

template <class Key>
int BinaryTree<Key>::bfactor(node* p)
{
	return height(p->right)-height(p->left);
}

template <class Key>
void BinaryTree<Key>::fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::rotateright(node* p) {
	
	node* q = p->left;
	q->parent = p->parent;
	p->parent = q; 
    if (p->left->right) p->left->right->parent = p;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}


template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::rotateleft(node* q)
{
	node* p = q->right;
	q->parent = p;
	p->parent = q->parent;
	q->right = p->left;
	if (p->left) p->left->parent = q;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::balance(node* p) 
{
	fixheight(p);
	if( bfactor(p)==2 )
	{
		if( bfactor(p->right) < 0 )
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if( bfactor(p)==-2 )
	{
		if( bfactor(p->left) > 0  )
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::insert_avl(node* p, Key k, 
			node* merge_node, node **head_other, node** current) {
	if ( !p ) {
		if (merge_node == nullptr){
			*current = new node(k);
		} else {
			*head_other = remove(*head_other, merge_node->data, 1);
			merge_node->left = nullptr;
			merge_node->right = nullptr;
			merge_node->height = 1;
			*current  = merge_node;
		}
		return *current;
	}
	if( k<p->data ) {
		node* temp = p;
		p->left = insert_avl(p->left,k, merge_node, head_other, current);
		if (p->left) p->left->parent = temp;
	} else {
		node* temp = p;
		p->right = insert_avl(p->right,k, merge_node, head_other, current);
		if (p->right) p->right->parent = temp;
	}
	return balance(p);
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::findmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left?findmin(p->left):p;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{

	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);

	return balance(p);
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::remove(node* p, const Key& k, bool del) // удаление ключа k из дерева p
{
	if( !p ) return 0;
	if( k < p->data ) 
		p->left = remove(p->left,k, del);
	else if( k > p->data )
		p->right = remove(p->right,k, del);	
	else 
	{
		
		node* q = p->left;
		node* r = p->right;
	
		node * p_parent = p->parent;
			
		if (del == 0) delete p;
		if( !r ) return q;
		node* min = findmin(r);
	
		min->parent = p_parent;

		min->right = removemin(r);
		
		min->left = q;
		if(min->left) min->left->parent  = min;
		if (min->right) min->right->parent = min;

		return balance(min);
	}
	return balance(p);
}
