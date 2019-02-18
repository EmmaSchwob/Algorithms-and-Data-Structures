#include "Queue.h"
#include <iostream>

Queue::Queue()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

Queue::~Queue()
{
	node* current = head;
	node* next;
	if (tail != NULL) {
		tail->next = NULL;
	}
	while (current != NULL) {
		next = current->next;
		delete(current);
		current = next;
	}
}

int Queue::getSize() {
	return size;
}

bool Queue::isEmpty() {
	return (head == NULL);
}

//create a new node at the tail of the queue
void Queue::enqueue(int key) {
	struct node *tail = new struct node;
	tail->key = key;
	if (isEmpty()) {
		tail->next = NULL;
		tail->previous = NULL;
		this->head = tail;
		this->tail = tail;
	}
	else {
		tail->next = this->head;
		tail->previous = this->tail;
		this->tail->next = tail;
		this->head->previous = tail;
		this->tail = tail;
	}
	size++;
}

//remove the head of the queue and return its key
int Queue::dequeue() {
	int key;
	if (isEmpty()) {
		throw "The queue is empty!";
	}
	else if (getSize() == 1) {
		key = head->key;
		delete(head);
		head = NULL;
		tail = NULL;
	}
	else {
		key = head->key;

		head->next->previous = tail;
		tail->next = head->next;
		delete(head);
		head = tail->next;
	}
	size--;
	return key;
}

void Queue::display() {
	Queue::node* current = head;
	printf("[");
	for (int i = 0; i < getSize(); i++) {
		printf("%d ", current->key);
		current = current->next;
	}
	printf("]\n");
}