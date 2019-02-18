#pragma once
class Stack
{
private:
	int size;
	//a linked list
	struct node {
		int key;
		struct node *next;
	};
	struct node *top;
public:
	Stack();
	~Stack();
	int getSize();
	bool isEmpty();
	void push(int key);
	int pop();
	void display();
};


#pragma once
