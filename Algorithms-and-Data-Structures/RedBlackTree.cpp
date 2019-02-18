#include "BinarySearchTree.h"
#include "RedBlackTree.h"
#include <iostream>

void RedBlackTree::leftRotate(node* tree) {
	if (tree == NULL) {
		printf("the tree is empty\n");
		return;
	}
	if (tree->right == sentinel) {
		printf("the tree does not have a right child\n");
		return;
	}

	node* temp = tree->right;
	tree->right = temp->left;
	if (temp->left != sentinel) temp->left->parent = tree;

	temp->parent = tree->parent;
	if (tree->parent == sentinel)
		root = temp;
	else if (tree == tree->parent->left)
		tree->parent->left = temp;
	else
		tree->parent->right = temp;

	temp->left = tree;
	tree->parent = temp;
}

void RedBlackTree::rightRotate(node* tree) {
	if (tree == NULL) {
		printf("the tree is empty\n");
		return;
	}
	if (tree->left == sentinel) {
		printf("the tree does not have a left child\n");
		return;
	}
	node* temp = tree->left;
	tree->left = temp->right;
	if (temp->right != sentinel) temp->right->parent = tree;

	temp->parent = tree->parent;
	if (tree->parent == sentinel)
		root = temp;
	else if (tree == tree->parent->left)
		tree->parent->left;
	else
		tree->parent->right = temp;

	temp->right = tree;
	tree->parent = temp;
}

//subroutine used in insertion
//restore the red-black properties of the (sub-)tree passed in parameters after an insertion
void RedBlackTree::insertionFix(node* tree) {
	node* current;
	while (tree->parent->color == RED) {
		if (tree->parent == tree->parent->parent->left) {
			current = tree->parent->parent->right;
			if (current->color == RED) {
				tree->parent->color = BLACK;
				current->color = BLACK;
				tree->parent->parent->color = RED;
				tree = tree->parent->parent;
			}
			else {
				if (tree == tree->parent->right) {
					tree = tree->parent;
					leftRotate(tree);
				}
				tree->parent->color = BLACK;
				tree->parent->parent->color = RED;
				rightRotate(tree->parent->parent);
			}
		}
		else {
			current = tree->parent->parent->left;
			if (current->color == RED) {
				tree->parent->color = BLACK;
				current->color = BLACK;
				tree->parent->parent->color = RED;
				tree = tree->parent->parent;
			}
			else {
				if (tree == tree->parent->left) {
					tree = tree->parent;
					rightRotate(tree);
				}
				tree->parent->color = BLACK;
				tree->parent->parent->color = RED;
				leftRotate(tree->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

void RedBlackTree::transplant(node* u, node* v) {
	if (u->parent == sentinel)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

RedBlackTree::node* RedBlackTree::findMinimumInSubtree(node* tree) {
	if ((tree == sentinel) || (tree == NULL)) throw "The tree is empty!";
	if (tree->left == sentinel) {
		return tree;
	}
	else {
		return findMinimumInSubtree(tree->left);
	}
}

//subroutine used in deletion 
//restore the red-black properties of the (sub-)tree passed in parameters after a deletion
void RedBlackTree::deleteFix(node* tree) {
	node* current;
	while ((tree != root) && (tree->color == BLACK)) {
		if (tree == tree->parent->left) {
			current = tree->parent->right;
			if (current->color == RED) {
				current->color = BLACK;
				tree->parent->color = RED;
				leftRotate(tree->parent);
				current = tree->parent->right;
			}
			if ((current->left->color == BLACK) && (current->right->color == BLACK)) {
				current->color = RED;
				tree = tree->parent;
			}
			else if (current->right->color == BLACK) {
				current->left->color = BLACK;
				current->color = RED;
				rightRotate(current);
				current = tree->parent->right;
			}
			current->color = tree->parent->color;
			tree->parent->color = BLACK;
			current->right->color = BLACK;
			tree = root;
		}
		else {
			current = tree->parent->left;
			if (current->color == RED) {
				current->color = BLACK;
				tree->parent->color = RED;
				rightRotate(tree->parent);
				current = tree->parent->left;
			}
			if ((current->right->color == BLACK) && (current->left->color == BLACK)) {
				current->color = RED;
				tree = tree->parent;
			}
			else if (current->left->color == BLACK) {
				current->right->color = BLACK;
				current->color = RED;
				leftRotate(current);
				current = tree->parent->left;
			}
			current->color = tree->parent->color;
			tree->parent->color = BLACK;
			current->left->color = BLACK;
			tree = root;
		}
	}
	tree->color = BLACK;
}

void RedBlackTree::deleteSubTree(node* tree) {
	if (tree != sentinel) {
		deleteSubTree(tree->left);
		deleteSubTree(tree->right);
		delete(tree);
	}
}

//display an inOrderTraversal of the (sub)tree passed in parameter
void RedBlackTree::inOrderTraversal(node* tree) {
	if ((tree != NULL) && (tree != sentinel)) {
		inOrderTraversal(tree->left);
		if (tree->color == RED) printf("%d(red), ", tree->key);
		else printf("%d(black), ", tree->key);
		inOrderTraversal(tree->right);
	}
}

RedBlackTree::RedBlackTree()
{
	sentinel = new node;
	sentinel->color = BLACK;
	sentinel->key = -1;
	sentinel->left = sentinel->right = sentinel->parent = NULL;
	root = NULL;
}


RedBlackTree::~RedBlackTree() {
	RedBlackTree::deleteSubTree(root);
	delete(sentinel);
}

bool RedBlackTree::isEmpty() {
	return root == NULL;
}

//return true if there is a node with the key passed in parameter in the tree
bool RedBlackTree::findData(int key) {
	if (isEmpty()) throw "The tree is empty!";
	node* current = root;
	while (current != sentinel) {
		if (current->key == key) return true;
		else if (current->key > key) current = current->left;
		else current = current->right;
	}
	return false;
}

int RedBlackTree::findMaximum() {
	if (isEmpty()) throw "The tree is empty!";
	else {
		node* current = root;
		int max = current->key;
		while (current != sentinel) {
			if (current->key > max) max = current->key;
			current = current->right;
		}
		return max;
	}
}

int RedBlackTree::findMinimum() {
	return(findMinimumInSubtree(root)->key);
}

void RedBlackTree::insertion(int key) {
	node* tree = new node;
	tree->key = key;
	tree->left = tree->right = tree->parent = sentinel;
	if (isEmpty()) {
		root = tree;
		tree->color = BLACK;
		return;
	}
	tree->color = RED;
	node* current = root;
	while (current != sentinel) {
		if (key < current->key) {
			if (current->left == sentinel) {
				tree->parent = current;
				current->left = tree;
				insertionFix(tree);
				return;
			}
			else {
				current = current->left;
			}
		}
		else if (key > current->key) {
			if (current->right == sentinel) {
				tree->parent = current;
				current->right = tree;
				insertionFix(tree);
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

void RedBlackTree::deletion(int key) {
	if (isEmpty()) return;
	node* tree = root;
	//we find the node to delete
	while ((tree != sentinel) && (tree->key != key)) {
		if (key < tree->key) tree = tree->left;
		else if (key > tree->key) tree = tree->right;
	}
	if (tree == sentinel) return; //no node with the key passed in parameter exist in the tree
	node* temp = tree;
	node* original_temp;
	COLOR temp_original_color = temp->color;
	if (tree->left == sentinel) {
		original_temp = tree->right;
		transplant(tree, tree->right);
	}
	else if (tree->right == sentinel) {
		original_temp = tree->left;
		transplant(tree, tree->left);
	}
	else {
		temp_original_color = temp->color;
		original_temp = temp->right;
		if (temp->parent == tree) {
			original_temp->parent = temp;
		}
		else {
			transplant(temp, temp->right);
			temp->right = tree->right;
			temp->right->parent = temp;
		}
		transplant(tree, temp);
		temp->left = tree->left;
		temp->left->parent = temp;
		temp->color = tree->color;
	}
	if (temp_original_color == BLACK) deleteFix(original_temp);
}

void RedBlackTree::display() {
	printf("Displaying the tree : ");
	inOrderTraversal(root);
	printf("\n");
}