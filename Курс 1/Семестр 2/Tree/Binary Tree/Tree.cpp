#include "Tree.h"

template <class T>
Tree<T>::Tree(T data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}
template <class T>
Tree<T>::~Tree() {
	if (left)
		delete left;
	if (right)
		delete right;
}

template <class T>
void Tree<T>::insertLeft(T data) {
	Tree<T>* node = new Tree(data);
	if (left) {
		left->parent = node;
		node->left = this->left;
		this->left = node;
		node->parent = this;
	} else {
		left = node;
		node->parent = this;
	}
}
template <class T>
void Tree<T>::insertRight(T data) {
	Tree<T>* node = new Tree(data);
	if (right) {
		right->parent = node;
		node->right = this->right;
		this->right = node;
		node->parent = this;
	} else {
		right = node;
		node->parent = this;
	}
}