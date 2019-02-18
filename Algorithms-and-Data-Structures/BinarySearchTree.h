#pragma once
class BinarySearchTree
{
private:
	struct node {
		int key;
		node* left;
		node* right;
		node* parent;
	};
	node* root;

	void inOrderTraversal(node* n);
	void transplant(node* u, node* v);
	node* findMinimumInSubtree(node* tree);
	void deleteSubTree(node* tree);

public:
	BinarySearchTree();
	~BinarySearchTree();
	bool isEmpty();
	bool findData(int key);
	int findMaximum();
	int findMinimum();
	void insertion(int key);
	void deletion(int key);
	void display();
};
