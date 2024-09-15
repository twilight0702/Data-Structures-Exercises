#include <iostream>
#include "MatrixTerm.h"
#include "SparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix s1(3, 3);
	s1.addItem(0, 0, 5);
	s1.addItem(2, 1, 6);
	cout << s1;

	int row;
	int col;
	cout << "请输入这个矩阵的行数和列数";
	cin >> row >> col;
	cout << "请输入一整个矩阵" << endl;
	SparseMatrix s2(row, col);
	cin >> s2;
	cout << endl;
	cout << s2;

	cout << endl;
	SparseMatrix s3 = s2.Add(s1);
	cout << s3;

	cout << "s1中元素数量:" << s1.terms << "\n";
	SparseMatrix s4 = s1.Multiply(s2);
	cout << s4;
	return 0;
}