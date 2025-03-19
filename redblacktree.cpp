#include "Redblacktree.h"

template<class T>
Elem<T>::Elem()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;

	color = 1;
	info = T();
}

template<class T>
Elem<T>::Elem(T& d)
{
	info = d;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
	color = 1;
}

template<class T>
Elem<T>::~Elem()
{
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}

template<class T>
Elem<T>* Elem<T>::sibling()
{
	if (parent == nullptr)
		return nullptr;
	if (this == parent->left)
		return parent->right;
	else
		return parent->left;
}



// ---- PUBLIC FUNCTIONS ---- //
template<class T>
RedBlackTree<T>::RedBlackTree()
{
	nil = new Elem<T>;
	nil->color = 0;
	root = nil;
}

template<class T>
RedBlackTree<T>::~RedBlackTree()
{
	clearTree(root);
	delete nil;
}

template<class T>
Elem<T>* RedBlackTree<T>::getnil()
{
	return nil;
}

template<class T>
void RedBlackTree<T>::insertN(T d)
{
	//x is where the new node is inserted
	//y is the parent of x
	//z is the new node
	Elem<T>* z = new Elem<T>(d);
	Elem<T>* y = nil;
	Elem<T>* x = root;
	while (x != nil)
	{
		y = x;
		if (z->info < x->info)
			x = x->left;
		else if (z->info > x->info)
			x = x->right;
		else
		{
			//throw "Element already exists";
			return;
		}
	}
	z->parent = y;
	if (y == nil)
	{
		root = z;
	}
	else if (z->info < y->info)
	{
		y->left = z;
	}
	else if (z->info > y->info)
	{
		y->right = z;
	}
	else
	{
		//throw "Element already exists";
		return;
	}
	z->left = nil;
	z->right = nil;
	z->color = 1;
	insertFixup(z);
}

template<class T>
void RedBlackTree<T>::deleteN(T d)
{
	Elem<T>* z = searchN(d);
	if (z == nil)
	{
		//throw "Element not found";
		return;
	}
	deleteNode(z);
}

template<class T>
void RedBlackTree<T>::printT()
{
	printTree(root, 0);
}

template<class T>
Elem<T>* RedBlackTree<T>::searchN(T d)
{
	return searchNode(root, d);
}

template <class T>
void RedBlackTree<T>::inorder()
{
	helpinorder(root);
}

template<class T>
void RedBlackTree<T>::inorder(int show)
{
	helpinorder(root,show);
}

template<class T>
void RedBlackTree<T>::inorder(int show, vector<bool>&ff)
{
	helpinorder(root, show, ff);
	cout<<"-----------------------------------"<<endl;
	cout<<"Press p to go back"<<endl;
	char s;
	cin>>s;
	while(s!='p')
	{
		cin>>s;
	}
}

template<class T>
vector<Elem<T>*> RedBlackTree<T>::filter(int show, const Elem<T> e)
{
	return filterhelp(root, show,e);
}

// ---- PRIVATE FUNCTIONS ---- //

template<class T>
void RedBlackTree<T>::helpinorder(Elem<T>* x)
{
	if (x != nullptr || x!=nil)
	{
		helpinorder(x->left);
		cout << x->info << endl;
		helpinorder(x->right);
	}
}

template<class T>
void RedBlackTree<T>::helpinorder(Elem<T>* x, int show)
{
	if (x != nil)
	{
		helpinorder(x->left,show);
		x->info.displaywhat(show);
		cout<<"-----------------------------------"<<endl;
		helpinorder(x->right,show);
	}
}

template<class T>
void RedBlackTree<T>::helpinorder(Elem<T>* x, int show, vector<bool>&ff)
{
	if (x != nil)
	{
		helpinorder(x->left,show,ff);
		x->info.displaywhatFilters(show,ff);
		cout<<"-----------------------------------"<<endl;
		helpinorder(x->right,show,ff);
	}
}

template<class T>
vector<Elem<T>*> RedBlackTree<T>::filterhelp(Elem<T>* x,int show, Elem<T> e)
{
	vector<Elem<T>*> v;
	if (x != nullptr || x!=nil)
	{
		filterhelp(x->left,show, e);
		if (x->info.matching(show,e.info))
		{
			v.push_back(x);
		}
		filterhelp(x->right,show, e);
	}
	return v;
}

template<class T>
void RedBlackTree<T>::leftRotate(Elem<T>* x)
{
	//y is the right child of x
	//z is the left child of y
	Elem<T>* y = x->right;
	x->right = y->left;//z
	if (y->left != nil)//z is not nil
	{
		y->left->parent = x;//z->parent = x
	}
	y->parent = x->parent;//y->parent = w
	if (x->parent == nil)//x is root
	{
		root = y;
	}
	else if (x == x->parent->left)//x is left child
	{
		x->parent->left = y;// w->left = y
	}
	else//x is right child
	{
		x->parent->right = y;// w->right = y
	}
	y->left = x;
	x->parent = y;
}

template<class T>
void RedBlackTree<T>::rightRotate(Elem<T>* x)
{
	//y is the left child of x
	//z is the right child of y
	Elem<T>* y = x->left;
	x->left = y->right;//z
	if (y->right != nil)//z is not nil
	{
		y->right->parent = x;//z->parent = x
	}
	y->parent = x->parent;//y->parent = w
	if (x->parent == nil)//x is root
	{
		root = y;
	}
	else if (x == x->parent->right)//x is right child
	{
		x->parent->right = y;
	}
	else//x is left child
	{
		x->parent->left = y;
	}
	y->right = x;
	x->parent = y;
}

template<class T>
void RedBlackTree<T>::insertFixup(Elem<T>* z)
{
	//y is the uncle of z
	//z is the new node
	//x is the parent of z
	//w is the grandparent of z
	Elem<T>* y;
	while (z->parent->color == 1)//x parent is red
	{
		if (z->parent == z->parent->parent->left)//x parent is left child
		{
			y = z->parent->parent->right;//y is the uncle
			if (y->color == 1)//case 1 y uncle is red
			{
				z->parent->color = 0;//x parent black
				y->color = 0;//y uncle black
				z->parent->parent->color = 1;//w grandparent red
				z = z->parent->parent;//z = w
			}
			else//case 2 & 3 y uncle is black
			{
				if (z == z->parent->right)//case 2 triangle z is right child
				{
					z = z->parent;//z = x
					leftRotate(z);
				}
				//case 3 line z is left child
				z->parent->color = 0; //x parent black
				z->parent->parent->color = 1;//w grandparent red
				rightRotate(z->parent->parent);//w grandparent
			}
		}
		else
		{
			y = z->parent->parent->left;
			if (y->color == 1)//case 1 y uncle is red
			{
				z->parent->color = 0;//x parent black
				y->color = 0;//y uncle black
				z->parent->parent->color = 1;//w grandparent red
				z = z->parent->parent;//z = w
			}
			else
			{
				if (z == z->parent->left)//case 2 triangle z is left child
				{
					z = z->parent;//z = x
					rightRotate(z);
				}
				//case 3 line z is right child
				z->parent->color = 0;//x parent black
				z->parent->parent->color = 1;//w grandparent red
				leftRotate(z->parent->parent);//w grandparent
			}
		}
	}
	root->color = 0;
}

template<class T>
void RedBlackTree<T>::deleteFixup(Elem<T>* x)
{
	//w is the sibling of x
	//y is the left child of w
	//z is the right child of w
	Elem<T>* w;
	while (x != root && x->color == 0)//x is not root and x is black
	{
		if (x == x->parent->left)//x is left child
		{
			w = x->parent->right;//w is the sibling
			if (w->color == 1)//case 1 w is red
			{
				w->color = 0;//w black
				x->parent->color = 1;//x parent red
				leftRotate(x->parent);//x parent
				w = x->parent->right;//w sibling
			}
			if (w->left->color == 0 && w->right->color == 0)//case 2 w is black and both children are black
			{
				w->color = 1;//w red
				x = x->parent;//x parent
			}
			else
			{
				if (w->right->color == 0)//case 3 w is black and right child is black
				{
					w->left->color = 0;//y left child black
					w->color = 1;//w red
					rightRotate(w);//w
					w = x->parent->right;//w sibling
				}
				//case 4 w is black and right child is red
				w->color = x->parent->color;//w color
				x->parent->color = 0;//x parent black
				w->right->color = 0;//z right child black
				leftRotate(x->parent);//x parent
				x = root;
			}
		}
		else//x is right child
		{
			w = x->parent->left;
			if (w->color == 1)//case 1 w is red
			{
				w->color = 0;//w black
				x->parent->color = 1;//x parent red
				rightRotate(x->parent);//x parent
				w = x->parent->left;
			}
			if (w->right->color == 0 && w->left->color == 0)//case 2 w is black and both children are black
			{
				w->color = 1;//w red
				x = x->parent;//x parent
			}
			else
			{
				if (w->left->color == 0)//case 3 w is black and left child is black
				{
					w->right->color = 0;//z right child black
					w->color = 1;//w red
					leftRotate(w);//w
					w = x->parent->left;
				}
				//case 4 w is black and left child is red
				w->color = x->parent->color;//w color
				x->parent->color = 0;//x parent black
				w->left->color = 0;//y left child black
				rightRotate(x->parent);//x parent
				x = root;
			}
		}
	}
	x->color = 0;
}

template<class T>
Elem<T>* RedBlackTree<T>::treeMinimum(Elem<T>* x)
{
	while (x->left != nil)
	{
		x = x->left;
	}
	return x;
}

template<class T>
Elem<T>* RedBlackTree<T>::treeMaximum(Elem<T>* x)
{
	while (x->right != nil)
	{
		x = x->right;
	}
	return x;
}

template<class T>
void RedBlackTree<T>::transplant(Elem<T>* u, Elem<T>* v)
{
	if (u->parent == nil)//u is root
	{
		root = v;
	}
	else if (u == u->parent->left)//u is left child
	{
		u->parent->left = v;
	}
	else//u is right child
	{
		u->parent->right = v;
	}
	v->parent = u->parent;
}

template<class T>
void RedBlackTree<T>::deleteNode(Elem<T>* z)
{
	//y is the node to be deleted
	//x is the child of y
	Elem<T>* y = z;
	Elem<T>* x;
	int yOriginalColor = y->color;
	if (z->left == nil)//z has no left child
	{
		x = z->right;
		transplant(z, z->right);
	}
	else if (z->right == nil)//z has no right child
	{
		x = z->left;
		transplant(z, z->left);
	}
	else//z has both children
	{
		y = treeMinimum(z->right);//y is the successor of z
		yOriginalColor = y->color;
		x = y->right;
		if (y->parent == z)//y is the child of z
		{
			x->parent = y;
		}
		else
		{
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	if (yOriginalColor == 0)
	{
		deleteFixup(x);
	}
	delete z;
}

template<class T>
void RedBlackTree<T>::printTree(Elem<T>* x, int level)
{
	if (x != nil)
	{
		printTree(x->right, level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << x->info << " ";
		if (x->color == 0)
		{
			cout << "B" << endl;
		}
		else
		{
			cout << "R" << endl;
		}
		printTree(x->left, level + 1);
	}
}

template<class T>
Elem<T>* RedBlackTree<T>::searchNode(Elem<T>* x, T d) 
{
	if (x == nil || x->info == d)
	{
		return x;
	}
	if (d < x->info)
	{
		return searchNode(x->left, d);
	}
	else
	{
		return searchNode(x->right, d);
	}
}

template<class T>
void RedBlackTree<T>::clearTree(Elem<T>* x)
{
	if (x != nil)
	{
		clearTree(x->left);
		clearTree(x->right);
		delete x;
	}
}

