#include "STree.h"

template <class T>
STree<T>::STree(T data) {
	this->data = data;
	left = nullptr;
	right = nullptr;
	parent = nullptr;
}
template <class T>
STree<T>::~STree() {
	if (left)
		delete left;
	if (right)
		delete right;
}

template <class T>
STree<T>* STree<T>::findElement(T data) {
	if (this || (data == this->data))
		return this;
	if (data < this->data)
		return left->findElement(data);
	else
		return right->findElement(data);
}
template <class T>
STree<T>* STree<T>::findMin() {
	if (!left)
		return this;
	return left->findMin();
}
template <class T>
STree<T>* STree<T>::findMax() {
	if (!right)
		return this;
	return right->findMax();
}

template <class T>
void STree<T>::insertNode(T data) {
	STree<T>* tree = this;
	while (tree) {
		if (data >= tree->data) {
			if (tree->right)
				tree = tree->right;
			else {
				STree<T>* node = new STree<T>(data);
				node->parent = tree;
				tree->right = node;
				break;
			}
		}
		else if (data <= tree->data) {
			if (tree->left)
				tree = tree->left;
			else {
				STree<T>* node = new STree<T>(data);
				node->parent = tree;
				tree->left = node;
				break;
			}
		}
	}
}