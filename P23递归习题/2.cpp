#include<iostream>
#include<vector>
using namespace std;

void print(const vector<bool> &a)
{
	for(bool value : a)
	{
		cout << (value ? "true" : "false") << " ";
	}
	cout << endl;
}

void generate(int n,vector<bool> &a,int& falseCount,int& trueCount,int index)
{
	if (index == n)
	{
		print(a);
		for (bool value : a)
		{
			if (value == true)
			{
				trueCount++;
			}
			else
			{
				falseCount++;
			}
		}
	}
	else
	{
		a[index] = true;
		generate(n, a, falseCount, trueCount, index + 1);
		a[index] = false;
		generate(n, a, falseCount, trueCount, index + 1);
	}
}




int main()
{
	int n;
	cout << "请输入数组的长度：" << endl;
	cin >> n;
	vector<bool> a(n);
	int falseCount = 0;
	int trueCount = 0;
	cout << "全部情况如下：" << endl;
	generate(n, a, falseCount, trueCount, 0);
	cout << "false出现的次数：" << falseCount << "\ntrue出现的次数" << trueCount << endl;

	return 0;
}