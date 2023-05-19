#pragma once
#include <iostream>
using namespace std;

template <class T>
class STree {
public:
	STree(T);
	~STree();

	STree<T>* findElement(T);
	STree<T>* findMin();
	STree<T>* fintMax();

	void insertNode(T);
	void deleteNode(T);
	void inOrder(STree<T>*);

private:
	T data;
	STree* left;
	STree* right;
	STree* parent;	
};