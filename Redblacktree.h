#pragma once

#include "Employees.h"

template<class T>
class Elem
{
public:
	T info;
	Elem<T>* left;
	Elem<T>* right;
	bool color;//black=0,red=1;
	Elem<T>* parent;
	Elem();
	Elem(T& d);
	~Elem();
	Elem<T>* sibling();//returns the sibling of the node	
};

template<class T>
class RedBlackTree
{
private:
	Elem<T>* root;
	Elem<T>* nil;
	void leftRotate(Elem<T>* x);
	void rightRotate(Elem<T>* x);
	void insertFixup(Elem<T>* z);
	void deleteFixup(Elem<T>* x);
	Elem<T>* treeMinimum(Elem<T>* x);
	Elem<T>* treeMaximum(Elem<T>* x);
	void transplant(Elem<T>* u, Elem<T>* v);
	void deleteNode(Elem<T>* z);
	void printTree(Elem<T>* x, int level);
	Elem<T>* searchNode(Elem<T>* x, T d);
	void clearTree(Elem<T>* x);
	void helpinorder(Elem<T>* x);
	void helpinorder(Elem<T>* x, int show);
	void helpinorder(Elem<T>* x, int show,vector<bool>&ff);
	vector<Elem<T>*> filterhelp(Elem<T>*x,int show, Elem<T>e);
public:
	Elem<T>* getnil();//returns the nil node
	RedBlackTree();
	~RedBlackTree();
	void insertN(T d);
	void deleteN(T d);
	void printT();
	Elem<T>* searchN(T d);
	void inorder();
	void inorder(int show);
	void inorder(int show, vector<bool>&ff);
	vector<Elem<T>*> filter(int show, Elem<T> e);
};
