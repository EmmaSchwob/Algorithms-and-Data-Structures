#include "BinarySearchTree.h"
#include <iostream>

//display an inOrderTraversal of the (sub)tree passed in parameter
void BinarySearchTree::inOrderTraversal(node* tree) {
	if (tree != NULL) {
		inOrderTraversal(tree->left);
		printf("%d ", tree->key);
		inOrderTraversal(tree->right);
	}
}

void BinarySearchTree::transplant(node* u, node* v) {
	if (u->parent == NULL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	if (v != NULL)
		v->parent = u->parent;
}

BinarySearchTree::node* BinarySearchTree::findMinimumInSubtree(node* tree) {
	if (tree == NULL) throw "The tree is empty!";
	else {
		node* current = tree;
		node* min = current;
		while (current != NULL) {
			if (current->key < min->key) min = current;
			current = current->left;
		}
		return min;
	}
}

void BinarySearchTree::deleteSubTree(node* tree) {
	if (tree != NULL) {
		deleteSubTree(tree->left);
		deleteSubTree(tree->right);
		delete(tree);
	}
}

BinarySearchTree::BinarySearchTree() {
	root = NULL;
}

BinarySearchTree::~BinarySearchTree() {
	deleteSubTree(root);
}

bool BinarySearchTree::isEmpty() {
	return (root == NULL);
}

//return true if there is a node with the key passed in parameter in the tree
bool BinarySearchTree::findData(int key) {
	if (isEmpty()) throw "The tree is empty!";
	node* current = root;
	while (current != NULL) {
		if (current->key == key) return true;
		else if (current->key > key) current = current->left;
		else current = current->right;
	}
	return false;
}

int BinarySearchTree::findMaximum() {
	if (isEmpty()) throw "The tree is empty!";
	else {
		node* current = root;
		int max = current->key;
		while (current != NULL) {
			if (current->key > max) max = current->key;
			current = current->right;
		}
		return max;
	}
}

int BinarySearchTree::findMinimum() {
	return(findMinimumInSubtree(root)->key);
}

void BinarySearchTree::insertion(int key) {
	node* tree = new node;
	tree->key = key;
	tree->left = tree->right = NULL;

	if (isEmpty()) {
		tree->parent = NULL;
		root = tree;
		return;
	}
	node* current = root;
	while (current != NULL) {
		if (key < current->key) {
			if (current->left == NULL) {
				tree->parent = current;
				current->left = tree;
				return;
			}
			else {
				current = current->left;
			}
		}
		else if (key > current->key) {
			if (current->right == NULL) {
				tree->parent = current;
				current->right = tree;
				return;
			}
			else {
				current = current->right;
			}
		}
		else {
			throw "There is already a node with that key in the tree!";
		}
	}
}

void BinarySearchTree::deletion(int key) {
	node* tree = root;
	//we find the node to delete
	while ((tree != NULL) && (tree->key != key)) {
		if (key < tree->key) tree = tree->left;
		else if (key > tree->key) tree = tree->right;
	}
	if (tree == NULL) return; //no node with the key passed in parameter exist in the tree
	else {
		if (tree->left == NULL)
			transplant(tree, tree->right);
		else if (tree->right == NULL)
			transplant(tree, tree->left);
		else {
			node* temp = findMinimumInSubtree(tree->right);
			if (temp->parent != tree) {
				transplant(temp, temp->right);
				temp->right = tree->right;
				temp->right->parent = temp;
			}
			transplant(tree, temp);
			temp->left = tree->left;
			temp->left->parent = temp;
		}
	}
}

void BinarySearchTree::display() {
	printf("Displaying the tree : ");
	inOrderTraversal(root);
	printf("\n");
}