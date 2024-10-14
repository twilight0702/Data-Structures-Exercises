#ifndef STACK_H
#define STACK_H
template<class T>
class Stack
{
public:
	Stack(int stackCapacity=10);
	~Stack();
	bool isEmpty()const;
	T& Top()const;
	void push(const T& item);
	void pop();

	int getTop();
	int getCapacity();
	T* getStack();

	Stack devide();
	Stack& merge(Stack& another);
	void changeCapacity(T*& stack,int oldCapacity,int newCapacity);

	void output();
private:
	T* stack;
	int top;
	int capacity;
};

#endif // !STACK_H