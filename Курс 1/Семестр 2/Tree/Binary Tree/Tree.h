#pragma once
#include <iostream>
using namespace std;

template <class T>
class Tree {
public:
	Tree(T);
	~Tree();
	
	void insertLeft(T);
	void insertRight(T);
	Tree<T>* getLeft();
	Tree<T>* getRight();
	T getData() {
		return data;
	}

	void preOrder(Tree<T>*);
	void inOrder(Tree<T>*);
	void postOrder(Tree<T>*);

private:
	T data;
	Tree* left;
	Tree* right;
	Tree* parent;
};