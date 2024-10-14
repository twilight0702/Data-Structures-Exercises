#include <iostream>
using namespace std;
#include "Queue.h"
#include <algorithm>

Queue::Queue(int ca):capacity(ca)
{
	//if (queue != nullptr)delete[] queue;
	if (capacity > 0)
	{
		queue = new int[capacity];
		front = capacity - 1;
		rear = capacity - 1;
	}
}

Queue::Queue(const Queue& other)
{
	capacity = other.capacity;
	front = other.front;
	rear = other.rear;
	queue = new int[capacity];
	copy(other.queue, other.queue + capacity, queue);
}

Queue::~Queue()
{
	if (queue != nullptr)
	{
		delete[] queue;
		queue = nullptr;

	}
}

bool Queue::isEmpty()
{
	return(front == rear);
}

int Queue::top()
{
	if (!isEmpty())
	{
		int index = (front + 1) % capacity;
		return queue[index];
	}
}

int Queue::pop()
{
	if (!isEmpty())
	{
		int index = (front + 1) % capacity;
		int result = queue[index];
		front = index;

		return result;
	}
}

//当数组满了之后才会调用这个函数,让数组大小翻倍，重置front和rear
//注意这里各个值，copy的end是最后一个元素后面一个位置
//也可以使用pair返回两个Queue
void Queue::doubleSize()
{
	int* temp = new int[capacity*2];
	int start = (front + 1) % capacity;
	if (start<2)
	{
		copy(queue+start, queue+start+capacity+1, temp);
	}
	else 
	{
		copy(queue+start, queue+capacity, temp);
		copy(queue, queue+rear, temp + capacity - start);
	}

	front = capacity*2 - 1;
	rear = capacity - 2;
	capacity *= 2;
	delete[] queue;
	queue = temp;

}

void Queue::push(int item)
{
	if ((rear + 1) % capacity == front)
	{
		doubleSize();
	}
	rear=(rear+1)%capacity;
	queue[rear] = item;
}

//把一个队列拆成两个，其中返回的新队列中含有旧队列从第一个元素开始每间隔一个元素的所有元素
Queue Queue::divide()
{
	Queue temp1(capacity / 2 + 1);
	int index = (front + 1) % capacity;
	int end = rear;
	int i=0;
	while (index <= end)
	{
		int item = pop();
		if (i % 2 == 0)
		{
			temp1.push(item);
		}
		else
		{
			push(item);
		}
		i++;
		index = (index + 1) % capacity;
	}
	return temp1;

	
}

ostream& operator<< (ostream& cout, Queue& q)
{
	cout << "队列中所有元素为：";
	int index = (q.front + 1) % q.capacity;
	while (index <= q.rear)
	{
		cout << q.queue[index] << " ";
		index = (index + 1) % q.capacity;
	}
	cout << '\n';
	return cout;
}