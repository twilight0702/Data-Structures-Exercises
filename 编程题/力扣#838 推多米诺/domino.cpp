#include <iostream>
#include <string>
#include <vector>
using namespace std;

string pushDomino(string card)
{
	//自己加上虚拟的头和尾
	card = 'L' + card + 'R';
	int l = 0;

	string res = "";
	for (int r = 1;r < card.size();r++)
	{
		if (card[r] == '.')
		{
			continue;
		}
		//如果碰到了“异常牌"，将[l,r)放入结果
		//先把头放入（自己加的虚拟牌不放进去）
		if (l != 0)
		{
			res += card[l];
		}
		//判断放置中间位置
		int length = r - l - 1;

		if (card[l] == card[r])
		{
			res += string(length, card[l]);
		}
		else if (card[l] == 'L' && card[r] == 'R')
		{
			res += string(length, '.');
		}
		else if (card[l] == 'R' && card[r] == 'L')
		{
			res += string(length / 2, 'R');
			if (length % 2 != 0)
			{
				res += '.';
			}
			res += string(length / 2, 'L');
		}
		//重置左端点
		l = r;

	}

	return res;
}

int main1()
{
	string card;
	cin >> card;

	cout << pushDomino(card);

	return 0;
}