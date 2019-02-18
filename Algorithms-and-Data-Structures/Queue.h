#pragma once
class Queue
{
private:
	int size;
	//a doubly linked list
	struct node {
		int key;
		struct node *next;
		struct node *previous;
	};
	struct node *head;
	struct node *tail;
public:
	Queue();
	~Queue();
	int getSize();
	bool isEmpty();
	void enqueue(int data);
	int dequeue();
	void display();
};

