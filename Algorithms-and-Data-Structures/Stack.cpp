#include "Stack.h"
#include "LinkedList.h"
#include <iostream>

Stack::Stack()
{
	size = 0;
	top = NULL;
}

Stack::~Stack()
{
	Stack::node *current = top;
	Stack::node *next;
	while (current != NULL) {
		next = current->next;
		delete(current);
		current = next;
	}
}

int Stack::getSize() {
	return size;
}

bool Stack::isEmpty() {
	return (top == NULL);
}

//create a new node at the top of the stack
void Stack::push(int key) {
	Stack::node *top = new struct node;
	top->key = key;
	top->next = this->top;
	this->top = top;
	size++;
}

//remove the top of the stack and return its key
int Stack::pop() {
	if (isEmpty()) {
		throw "The stack is empty!";
	}
	int key = top->key;
	node* temp = top;
	top = top->next;
	delete(temp);
	size--;
	return key;
}

void Stack::display() {
	Stack::node *current = top;
	printf("[");
	while (current != NULL) {
		printf("%d ", current->key);
		current = current->next;
	}
	printf("]\n");
}