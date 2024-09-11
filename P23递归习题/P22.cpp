#include <iostream>
using namespace std;

void change(int& a, int& b);

//index标明现在排到第几位（从0开始），n是数字位数，count计数器，计算有多少种情况
void sort_and_print(int* a,int index,int n,int& count)
{
	//排到最后一位的时候
	if (index == n-1)
	{
		for (int i = 0;i < n;i++)
		{
			cout << a[i] << " ";
		}
		count++;
		cout << endl;
	}
	else
	{
		//原数组也不能省略，k=index
		for (int k = index ;k < n;k++)
		{
			change(a[index], a[k]);
			sort_and_print(a, index + 1, n, count);
			change(a[index], a[k]);
		}
	}
}

void change(int& a,int&b)
{
	int c = a;
	a = b;
	b = c;
	
}

int main()
{
	cout << "请输入数字个数：";
	int n;
	cin >> n;
	cout << "请输入数字：";
	int* a = new int[n];
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
	}

	int count = 0;
	sort_and_print(a, 0, n, count);
	cout << "一共有：" << count << "种\n";

	delete[] a;
	return 0;
}
