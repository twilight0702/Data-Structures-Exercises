#include <iostream>
#include <vector>
using namespace std;

int fibo(int i)
{
	if (i == 0)
	{
		return 0;
	}
	else if (i == 1)
	{
		return 1;
	}
	else
	{
		return fibo(i - 1) + fibo(i - 2);
	}
}

int main7()
{
	int i;
	cout << "需要知道斐波那契数列的第几位呢：" ;
	cin >> i;
	
	cout << "是：" << fibo(i);

	return 0;
}