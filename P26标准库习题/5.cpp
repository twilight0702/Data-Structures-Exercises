#include <iostream>
#include <algorithm>
#include <numeric> 
#include <vector>
using namespace std;

int main()
{
	int a[5] = { 5,3,1,2,5 };
	fill(a, a + 5, 0);
	copy(a, a + 5, ostream_iterator<int>(cout , " "));

	return 0;
}