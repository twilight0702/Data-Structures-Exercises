#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
using namespace std;

int main4()
{
	cout << "一共有几个元素：";
	int n;
	cin >> n;
	cout << "输入元素：";
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	cout << "第一个元素一共出现了：" << count(a, a + n, a[0]) << "次" << endl;


	delete[] a;
	return 0;
}