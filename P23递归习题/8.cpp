#include <iostream>
using namespace std;

int number(int n, int m)
{
	if (m == 0)
	{
		return 1;
	}
	else if (m == n)
	{
		return 1;
	}
	else
	{
		return number(n - 1, m) + number(n - 1, m - 1);
	}
}

int main8()
{
	cout << "请输入要计算的二项式系数，n,m：";
	int n, m;
	cin >> n >> m;
	cout << "二项式系数是：" << number(n, m);
	return 0;
}