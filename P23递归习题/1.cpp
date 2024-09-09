#include<iostream>
using namespace std;

//n为数组长度，不是下标
int number(int* a, int n, int x)
{
	//终止条件，只有一个数
	if (n == 1)
	{
		return a[0];
	}
	else
	{
		return (a[0] + x * (number(&a[1], n - 1, x)));
	}
}


int main1()
{
	int n;
	cout << "输入数组长度（n+1）："<<endl;
	cin >> n;
	cout << "请输入系数：" << endl;
	int* a = new int[n];

	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	cout << number(a, n, 2);

	delete[] a;
	return 0;
}