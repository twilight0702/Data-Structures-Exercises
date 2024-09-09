#include <iostream>
using namespace std;

void hannuo(int index,string start,string middle,string end)
{
	if (index == 1)
	{
		cout << "move 1 from " << start << " to " << end << endl;
	}
	else
	{
		hannuo(index - 1, start, end, middle);
		cout << "move " << index << " from " << start << " to " << end << endl;
		hannuo(index - 1, middle, start, end);
	}
}

int main15()
{
	string start = "start";
	string middle = "middle";
	string end = "end";
	hannuo(4, start, middle, end);

	return 0;
}