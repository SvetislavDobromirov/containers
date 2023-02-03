#include <iostream>
#include <set>
//#include <vector>
//#include "../vector/s21_vector.h"

#include <stdlib.h>
//#include <iostream>
#include <time.h>
#include <chrono>

#include <ctime>


struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	struct node* left;
	struct node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

template <class Key>
unsigned char BinaryTree<Key>::dheight(node* p)
{
	return p?p->height:0;
}

template <class Key>
int BinaryTree<Key>::dbfactor(node* p)
{
	return height(p->right)-height(p->left);
}

template <class Key>
void BinaryTree<Key>::dfixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl>hr?hl:hr)+1;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::drotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}


template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::drotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::dbalance(node* p) // балансировка узла p
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
	return p; // балансировка не нужна
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::dinsert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if( !p ) return new node(k);
	if( k<p->key )
		p->left = insert(p->left,k);
	else
		p->right = insert(p->right,k);
	return balance(p);
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::dfindmin(node* p) // поиск узла с минимальным ключом в дереве p 
{
	return p->left?findmin(p->left):p;
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::dremovemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if( p->left==0 )
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

template <class Key>
typename BinaryTree<Key>::node* BinaryTree<Key>::dremove(node* p, int k) // удаление ключа k из дерева p
{
	if( !p ) return 0;
	if( k < p->key )
		p->left = remove(p->left,k);
	else if( k > p->key )
		p->right = remove(p->right,k);	
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if( !r ) return q;
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}
