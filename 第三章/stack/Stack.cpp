#include "Stack.h"
#include <iostream>
using namespace std;

//���캯����������
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

//����ջ����Ԫ��
template<class T>
inline T& Stack<T>::Top()const
{
	if (isEmpty())
	{
		throw"stack is empty";
	}
	return stack[top];
}

//��������ĩβ���һ��Ԫ�أ�����������������
template<class T>
void Stack<T>::push(const T& item)
{
	if (top == capacity - 1)
	{
		changeCapacity(stack, capacity, capacity * 2);
	}
	//��ʶtop��1
	stack[++top] = item;
}

//����ջ����Ԫ��
template<class T>
void Stack<T>::pop()
{
	if (isEmpty())
	{
		throw"Stack id empty.Cannot delete";
	}
	stack[top--].~T();
}

//�ı�������ͬʱ�ı�capacity�����������С���ж��Ƿ�Ӧ����Сtop
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

//��ֳ�����ջ�������ǰ�ԭջ��СΪջ�׵���һ��Ԫ�أ�������ջ������һ��Ԫ��
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

//�ϲ�����ջ�����ǰ������ջ�е�Ԫ��ѹ���Լ�
template <class T>
Stack<T>& Stack<T>::merge(Stack& other)
{
	for (int i = 0;i < other.top + 1;i++)
	{
		push(other.stack[i]);
	}
	return *this;
}

//�����ʽ�Ǵ�ջ����ջ��
template<class T>
void Stack<T>::output()
{
	for (int i = top;i >= 0;i--)
	{
		cout << stack[i] << " ";
	}
	cout << endl;
}

