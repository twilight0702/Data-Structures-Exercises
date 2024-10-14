#include "Stack.h"
#include <iostream>
using namespace std;

//构造函数创建数组
template<class T>
Stack<T>::Stack(int stackCapacity):capacity(stackCapacity)
{
	if (capacity < 1)throw"stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template<class T>
Stack<T>::~Stack()
{
	delete[] stack;
	stack = nullptr;
}

template<class T>
inline bool Stack<T>::isEmpty()const
{
	return top == -1;
}

//返回栈顶的元素
template<class T>
inline T& Stack<T>::Top()const
{
	if (isEmpty())
	{
		throw"stack is empty";
	}
	return stack[top];
}

//给数组最末尾添加一个元素，如果容量不足就扩容
template<class T>
void Stack<T>::push(const T& item)
{
	if (top == capacity - 1)
	{
		changeCapacity(stack, capacity, capacity * 2);
	}
	//标识top加1
	stack[++top] = item;
}

//弹出栈顶的元素
template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw"Stack id empty.Cannot delete";
	}
	stack[top--].~T();
}

//改变容量，同时改变capacity，如果容量变小，判断是否应该缩小top
template <class T>
void Stack<T>::changeCapacity(T*& stack, int oldCapacity, int newCapacity)
{
	if (newCapacity < 0)throw"capacity must be > 0";

	T* temp = new T[newCapacity];
	int minCapacity = oldCapacity < newCapacity ? oldCapacity : newCapacity;
	for (int i = 0;i < minCapacity;i++)
	{
		temp[i] = stack[i];
	}
	capacity = newCapacity;
	delete[] stack;
	stack = temp;

	if (top > newCapacity - 1)
	{
		top = newCapacity - 1;
	}
}

//拆分成两个栈，这里是把原栈缩小为栈底的那一半元素，返回了栈顶的那一半元素
template<class T>
Stack<T> Stack<T>::devide()
{
	Stack<T> newStack((top + 1 )/ 2);
	for (int i = 0;i < (top + 1) / 2;i++)
	{
		int j = top - (top + 1) / 2 + i;
		newStack.push(stack[j]);
	}
	changeCapacity(stack, capacity, capacity - capacity / 2);

	return newStack;
}

template <class T>
int Stack<T>::getTop() { return top; }

template <class T>
int Stack<T>::getCapacity() { return capacity; }

template <class T>
T* Stack<T>::getStack() { return stack; }

//合并两个栈，就是把输入的栈中的元素压入自己
template <class T>
Stack<T>& Stack<T>::merge(Stack& other)
{
	for (int i = 0;i < other.top + 1;i++)
	{
		push(other.stack[i]);
	}
	return *this;
}

//输出方式是从栈顶到栈底
template<class T>
void Stack<T>::output()
{
	for (int i = top;i >= 0;i--)
	{
		cout << stack[i] << " ";
	}
	cout << endl;
}

