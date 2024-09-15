#include <iostream>
#include "SparseMatrix.h"
#include <algorithm>
#include <stdexcept>
using namespace std;

SparseMatrix::SparseMatrix(int r, int c, int t) :
	rows(r),cols(c),terms(t)
{
	//给vector初始化大小
	smArray.resize(terms);
}

//给数组中的元素排序，先行后列
void SparseMatrix::sortItems()
{
	sort(smArray.begin(), smArray.end(), [](const MatrixTerm& a, const MatrixTerm& b)
		{
			if (a.row != b.row)
				return a.row < b.row;
			else
				return a.col < b.col;
		}
	);
}

//给数组添加元素
void SparseMatrix::addItem(int row,int col,int t)
{
	MatrixTerm a(row, col, t);
	smArray.push_back(a);
	sortItems();
	terms++;
}

//数组转置
SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix t(rows, cols, terms);
	if (terms > 0)
	{
		//获取每一列的元素数量和每一行开头的下标,也就是对应到转置后的行
		int* colSize = new int[cols] {0};
		int* rowStart = new int[cols] ;
		for (int i = 0;i < terms;i++)
		{
			colSize[smArray[i].col]++;
		}
		rowStart[0] = 0;
		for (int i = 1;i < cols;i++)
		{
			rowStart[i] = rowStart[i - 1] + colSize[i - 1];
		}
		//遍历数组中的每一个元素，然后转置
		for (int i = 0;i < terms;i++)
		{
			//确认要放置转置后的元素的位置（下标）
			int j = rowStart[smArray[i].col];
			t.smArray[j].row = smArray[i].col;
			t.smArray[j].col = smArray[i].row;
			t.smArray[j].value = smArray[i].value;

			rowStart[smArray[i].col]++;
		}
		delete[] colSize;
		delete[] rowStart;
	}

	return t;
}

//乘法看不懂，这里没有写完
//用自己想的方法写一遍，不是教材里的那个
SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{
	if (cols != b.rows)
	{
		throw invalid_argument("两个矩阵无法相乘");
	}

	//存放结果的矩阵
	SparseMatrix result(rows, b.cols,0);
	//转置b
	SparseMatrix Tb = b.Transpose();
	
	//获取a,b开头编号
	vector<int> ArowSize(rows,0);
	vector<int> ArowStart(rows+1,0);

	for (int i = 0;i < terms;i++)
	{
		ArowSize[smArray[i].row]++;
	}
	ArowStart[0] = 0;
	for (int i = 1;i < rows;i++)
	{
		ArowStart[i] = ArowStart[i - 1] + ArowSize[i - 1];
	}
	ArowStart[rows] = terms;//添加不存在的一项，方便后面循环的条件判断
	
	vector<int> BcolSize(b.cols,0);
	vector<int> BrowStart(b.cols+1,0);

	for (int i = 0;i < b.terms;i++)
	{
		BcolSize[b.smArray[i].col]++;
	}
	BrowStart[0] = 0;
	for (int i = 1;i < b.cols;i++)
	{
		BrowStart[i] = BrowStart[i - 1] + BcolSize[i - 1];
	}
	BrowStart[b.cols] = b.terms;//添加不存在的一项，方便后面循环的条件判断
	
	int indexA = 0;
	int indexB = 0;

	for (int currentRow = 0;currentRow < rows;currentRow++)
	{
		for (int currentCol = 0;currentCol < b.cols;currentCol++)
		{
			int sum = 0;
			indexA = ArowStart[currentRow];
			indexB = BrowStart[currentCol];

			while ((indexA < ArowStart[currentRow + 1]) && (indexB < BrowStart[currentCol + 1]))
			{
				if (smArray[indexA].col < Tb.smArray[indexB].col)
				{
					indexA++;
				}
				else if (smArray[indexA].col > Tb.smArray[indexB].col)
				{
					indexB++;
				}
				else
				{
					sum += smArray[indexA].value * Tb.smArray[indexB].value;
					indexA++;
					indexB++;
				}
			}
			result.addItem(currentRow, currentCol, sum);

		}
	}

	return result;

}

//输出函数，时间复杂度一样，就是空间复杂度比较高，但是表达比较清晰
ostream& operator<<(ostream& cout,SparseMatrix s)
{
	vector<vector<int>> matrix(s.rows, vector<int>(s.cols,0));
	for (int i = 0;i < s.terms;i++)
	{
		matrix[s.smArray[i].row][s.smArray[i].col] = s.smArray[i].value;
	}

	for (int i = 0;i < s.rows;i++)
	{
		for (int j = 0;j < s.cols;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}

	return cout;
}

//输入函数，直接矩阵输入
istream& operator>>(istream& cin,SparseMatrix& s)
{
	for (int i = 0;i < s.rows;i++)
	{
		for (int j = 0;j < s.cols;j++)
		{
			int a;
			cin >> a;
			if (a != 0)
			{
				s.addItem(i, j, a);
			}
		}
	}

	return cin;
}

SparseMatrix SparseMatrix::Add(SparseMatrix b)
{
	if (rows != b.rows || cols != b.cols)
	{
		throw invalid_argument("这两个矩阵不能相加");
	}

	SparseMatrix result(rows, cols);
	int indexA = 0;
	int indexB = 0;
	while (indexA < terms && indexB < b.terms)
	{
		if (smArray[indexA].row < b.smArray[indexB].row)
		{
			result.addItem(smArray[indexA].row, smArray[indexA].col, smArray[indexA].value);
			indexA++;
		}
		else if (smArray[indexA].row > b.smArray[indexB].row)
		{
			result.addItem(b.smArray[indexB].row, b.smArray[indexB].col, b.smArray[indexB].value);
			indexB++;
		}
		else
		{
			if (smArray[indexA].col < b.smArray[indexB].col)
			{
				result.addItem(smArray[indexA].row, smArray[indexA].col, smArray[indexA].value);
				indexA++;
			}
			if (smArray[indexA].col > b.smArray[indexB].col)
			{
				result.addItem(b.smArray[indexB].row, b.smArray[indexB].col, b.smArray[indexB].value);
				indexB++;
			}
			else
			{
				result.addItem(smArray[indexA].row, smArray[indexA].col, smArray[indexA].value + b.smArray[indexB].value);
				indexA++;
				indexB++;
			}
		}
	}

	for (;indexA < terms;indexA++)
	{
		result.addItem(smArray[indexA].row, smArray[indexA].col, smArray[indexA].value);
		indexA++;
	}

	for (;indexB < b.terms;indexB++)
	{
		result.addItem(b.smArray[indexB].row, b.smArray[indexB].col, b.smArray[indexB].value);
		indexB++;
	}

	return result;
}