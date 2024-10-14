#ifndef QUEUE_H
#define QUEUE_H


#include <iostream>
using namespace std;

class Queue
{
public:
	Queue(int ca);
	Queue(const Queue& other);
	~Queue();

	int top();
	bool isEmpty();
	int pop();
	void push(int item);

	void doubleSize();

	Queue divide();

	friend ostream& operator<< (ostream & cout, Queue & q);

private:
	int* queue;
	int capacity;
	int front;
	int rear;

};


#endif // !QUEUE_H

