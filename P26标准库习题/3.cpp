#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
using namespace std;

int main3()
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

	//调整为降序
	do {
			
	} while (next_permutation(a, a + n));

	//输出所有序列
	do {
		copy(a, a + n, ostream_iterator<int>(cout, " "));
		cout << endl;
	} while (next_permutation(a, a + n));

	delete[] a;

	return 0;
}