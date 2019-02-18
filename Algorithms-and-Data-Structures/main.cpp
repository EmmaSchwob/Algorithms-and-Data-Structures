#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Stack.h"
#include "Queue.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

int main() {
	Stack s;
	int key;
	s.display();
	printf("%d\n", s.getSize());
	printf("building the stack\n");
	for (int i = 0; i <= 10; i++) {
		s.push(i);
		s.display();
	}
	printf("%d\n", s.getSize());
	while (getchar() != '\n');
	printf("destroying the stack\n");
	while (s.getSize() > 0) {
		key = s.pop();
		printf("%d : ", key);
		s.display();
	}
	printf("%d\n", s.getSize());

	while (getchar() != '\n');
	printf("----------\n");


	Queue q;
	q.display();
	printf("%d\n", q.getSize());
	printf("building the queue\n");
	for (int i = 0; i <= 10; i++) {
		q.enqueue(i);
		q.display();
	}
	printf("%d\n", q.getSize());
	while (getchar() != '\n');
	printf("destroying the queue\n");
	while (q.getSize() > 0) {
		key = q.dequeue();
		printf("%d : ", key);
		q.display();
	}
	printf("%d\n", q.getSize());

	while (getchar() != '\n');
	printf("----------\n");


	BinarySearchTree bt;
	bt.insertion(4);
	bt.insertion(1);
	bt.insertion(0);
	bt.insertion(3);
	bt.insertion(2);
	bt.insertion(7);
	bt.insertion(5);
	bt.insertion(6);
	bt.insertion(9);
	bt.insertion(8);
	bt.insertion(10);
	bt.display();

	if (bt.findData(6)) {
		printf("we could find 6\n");
	}
	bt.display();
	if (bt.findData(42) == false) {
		printf("we couldnt find 42\n");
	}

	printf("maximum is : %d\n", bt.findMaximum());
	printf("minimum is : %d\n", bt.findMinimum());
	bt.display();

	//childless
	bt.deletion(2);
	bt.display();

	//1 left child
	bt.deletion(3);
	bt.display();

	//1 right child
	bt.deletion(5);
	bt.display();

	//2 children
	bt.deletion(9);
	bt.display();

	//not part of the tree
	bt.deletion(42);
	bt.display();

	while (getchar() != '\n');
	printf("----------\n");


	RedBlackTree rbt;
	printf("building the red-black tree\n");
	for (int i = 0; i < 10; i++) {
		rbt.insertion(i);
	}
	rbt.display();

	if (rbt.findData(6)) {
		printf("we could find 6\n");
	}
	if (rbt.findData(42) == false) {
		printf("we couldnt find 42\n");
	}

	printf("maximum is : %d\n", rbt.findMaximum());
	printf("minimum is : %d\n", rbt.findMinimum());

	//not part of the tree
	rbt.deletion(42);

	printf("destroying the red-black tree\n");
	for (int i = 0; i < 10; i++) {
		rbt.deletion(i);
	}
	rbt.display();

	while (getchar() != '\n');

	return 0;
}