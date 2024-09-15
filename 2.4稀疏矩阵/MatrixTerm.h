#ifndef MATRIXTERM_H
#define MATRIXTERM_H

#include <iostream>
using namespace std;

//class SparseMatrix;

class MatrixTerm
{
public:	
	MatrixTerm(int r, int c, int v);
	MatrixTerm();


	friend class SparseMatrix;

	int row, col, value;
};

#endif 