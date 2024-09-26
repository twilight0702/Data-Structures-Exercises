#include <iostream>
#include <string>
#include "MyString.h"
using namespace std;

int main()
{
	string string1, string2;
	cout << "string1:";
	cin >> string1;
	cout << "string2:";
	cin >> string2;

	cout << string1.length() << " " << string2.length() << "\n";

	MyString m1(string1);
	MyString m2(string2);
	cout << m1.Length() << "\n";
	cout << m2.Length() << "\n";

	cout << m1.s << "\n";
	cout << m2.s << "\n";

	for (int i = 0;i < m1.Length();i++)
	{
		cout << m1.f[i] << " ";
	}
	cout << "\n";

	for (int i = 0;i < m2.Length();i++)
	{
		cout << m2.f[i] << " ";
	}
	cout << "\n";


	cout << m1.fastFind(m2);

	return 0;
}