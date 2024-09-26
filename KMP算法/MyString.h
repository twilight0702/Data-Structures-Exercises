#include <iostream>
using namespace std;
#include <string>
#include <vector>

class MyString
{
public:
	MyString(string a);
	~MyString();
	void FailureFunction();
	int Length();
	int fastFind(MyString& other);

	int* f;
	string s;
};