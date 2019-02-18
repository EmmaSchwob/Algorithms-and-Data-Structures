#pragma once
class RedBlackTree
{
private:
	enum COLOR { RED, BLACK };
	struct node {
		int key;
		COLOR color;
		node* left;
		node* right;
		node* parent;
	};
	node* root;
	node* sentinel;

	void leftRotate(node* tree);
	void rightRotate(node* tree);
	void insertionFix(node* tree);
	void transplant(node* u, node* v);
	node* findMinimumInSubtree(node* tree);
	void deleteFix(node* tree);
	void deleteSubTree(node* tree);
	void inOrderTraversal(node* tree);

public:
	RedBlackTree();
	~RedBlackTree();
	bool isEmpty();
	bool findData(int key);
	int findMaximum();
	int findMinimum();
	void insertion(int key);
	void deletion(int key);
	void display();
};

#pragma once
