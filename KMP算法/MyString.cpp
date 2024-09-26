#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "MyString.h"

MyString::MyString(string a)
{
	f = new int[a.length()];
	s = a;
	FailureFunction();
}

MyString::~MyString()
{
	delete[] f;
	f = nullptr;
}

int MyString::Length()
{
	return s.length();
}

void MyString::FailureFunction()
{
//	f = new int[Length()];
	f[0] = -1;
	for (int i = 1;i < Length();i++)
	{
		int j = f[i - 1];
		while ((s[i] != s[j + 1]) && (j >= 0))
		{
			j = f[j];
		}
		if (s[i] == s[j + 1])
		{
			f[i] = j + 1;
		}
		else
		{
			f[i] = -1;
		}
	}
}

int MyString::fastFind(MyString& pat)
{
	int indexS = 0;
	int indexP = 0;
	while (indexS < Length() && indexP < pat.Length())
	{
		if (s[indexS] == pat.s[indexP])
		{
			indexS++;
			indexP++;
		}
		else if(indexP!=0)
		{
			indexP = pat.f[indexP - 1] + 1;
		}
		else
		{
			indexS++;
		}
	}

	if (indexP == pat.Length())
	{
		return indexS-pat.Length();
	}
	else
	{
		return -1;
	}
	
}