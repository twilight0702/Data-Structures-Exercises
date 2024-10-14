#include <iostream>
using namespace std;
#include "Queue.h"

int main()
{
	Queue a(10);
	for (int i = 1;i <= 10;i++)
	{
		a.push(i);
	}
	cout << a << '\n';

	Queue x= a.divide();
	cout << "a=" << a << '\n' << "x=" << x << '\n' ;

	return 0;
}