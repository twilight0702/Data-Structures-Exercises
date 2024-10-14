#include <iostream>
using namespace std;
#include "Stack.h"
#include "Stack.cpp"

int main()
{
	Stack<int> a(10);
	for (int i = 1;i <= 10;i++)
	{
		a.push(i);
	}
	cout << "a=";
	a.output();
	cout << "\n";
	Stack<int> b(10);
	for (int i = 11;i <= 20;i++)
	{
		b.push(i);
	}
	cout << "b=";
	b.output();
	cout << "\n";
	a.merge(b);
	cout << "a=";
	a.output();
	cout << "\n";

	Stack<int> c  = a.devide();
	cout << "a=";
	a.output();
	cout << "\n";
	cout << "devided=";
	c.output();
	cout << "\n";


	return 0;
}