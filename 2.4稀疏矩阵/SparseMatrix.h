#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H



#include <iostream>
#include <vector>
#include "MatrixTerm.h"
using namespace std;

class SparseMatrix
{
public:
	SparseMatrix(int r, int c, int t=0);
	void sortItems();
	void addItem(int row,int col,int value);
	SparseMatrix Transpose();
	SparseMatrix Add(SparseMatrix b);
	SparseMatrix Multiply(SparseMatrix b);


	friend ostream& operator<<(ostream& cout, SparseMatrix sparseMatrix);
	friend istream& operator>>(istream& cin, SparseMatrix& sparseMatrix);


	int rows, cols, terms;
	vector<MatrixTerm> smArray;
};

ostream& operator<<(ostream& cout, SparseMatrix sparseMatrix);
istream& operator>>(istream& cin, SparseMatrix& sparseMatrix);


#endif // !SPARSEMATRIX_H