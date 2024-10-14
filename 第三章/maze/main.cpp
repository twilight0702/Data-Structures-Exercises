#include <iostream>
using namespace std;
#include <stack>
#include <vector>

struct offsets
{
	int a, b;
};

enum directions { N, NE, E, SE, S, EW, W, NW };



struct Items
{
	int x, y,dir;
	Items(int a, int b, directions d)
	{
		x = a;
		y = b;
		dir = d;
	}
	Items(int a, int b, int d)
	{
		x = a;
		y = b;
		dir = d;
	}
};


ostream& operator<<(ostream& cout, Items& item)
{
	cout << "(" << item.x << "," << item.y << "," << item.dir << ")" << " ";
	return cout;
}


// 输出栈中所有元素的 (x, y)
void outputStack(stack<Items>& stack) {
	vector<Items> path;  // 用来存储栈中的元素

	// 将栈中元素全部存储到 vector 中
	while (!stack.empty()) {
		path.push_back(stack.top());
		stack.pop();
	}

	// 从 vector 中正序输出
	for (int i = path.size() - 1; i >= 0; --i) {
		cout << "(" << path[i].x << ", " << path[i].y << ")" << endl;
	}
}

void path(const int m, const int p)
{
	offsets Move[8] = {
		{-1, 0},  // Move[0]
		{-1, 1},  // Move[1]
		{0, 1},   // Move[2]
		{1, 1},   // Move[3]
		{1, 0},   // Move[4]
		{1, -1},  // Move[5]
		{0, -1},  // Move[6]
		{-1, -1}  // Move[7]
	};


	int maze[4][10] = { {1,1,1,1,1,1,1,1,1,1},
					    {1,0,0,0,1,0,0,0,0,1},
					    {1,0,0,0,0,0,0,0,0,1},
					    {1,1,1,1,1,1,1,1,1,1} };

	int mark[4][10] = { 0 };



	mark[1][1] = 1;
	stack<Items>  stack;
	Items temp(1, 1, E);
	stack.push(temp);

	while (!stack.empty())
	{
		Items temp = stack.top();
		stack.pop();
		int i = temp.x;
		int j = temp.y;
		int d = temp.dir;

		while (d < 8)
		{
			int g = i + Move[d].a;
			int h = j + Move[d].b;
			if (g == m && h == p)
			{
				Items temp(i, j, d + 1);
				stack.push(temp);
				temp.x = m;
				temp.y = p;
				temp.dir = N;
				stack.push(temp);
				outputStack(stack);
				return;
			}
			else if (!maze[g][h] && !mark[g][h])
			{
				mark[g][h] = 1;
				Items temp(i, j, d+1);
				stack.push(temp);
				i = g;
				j = h;
				d = N;
			}
			else
			{
				d++;
			}
		}
	}
	cout << "没有路径" << '\n';
}



int main()
{
	path(2, 8);

	return 0;
}
