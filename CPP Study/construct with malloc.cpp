#include <iostream>
#include <time.h>
using namespace std;

#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5

class Matrix {	
	int rows, cols;
	int* array;
	
public:
	
	Matrix() : rows(0), cols(0), array(new int) {}
	Matrix(int, int);
	~Matrix();
	void GetData();
	void ShowData();
	void Multiply(Matrix&, Matrix&, int, int);
};

Matrix::Matrix(int a, int b)
{
	rows = a;
	cols = b;
	array = new int[a * b];
}

Matrix::~Matrix()
{
	delete(array);
}

void Matrix::GetData()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(array + rows * i + j) = rand() % 10;
}

void Matrix::ShowData()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", *(array + rows * i + j));
		cout << endl;
	}
	cout << endl;
}

void Matrix::Multiply(Matrix& b, Matrix& c, int acol, int brow) // acol should be same with brow (The multiplication condition of matrix)	
{
	int sum = 0;
	if (acol == brow)
	{
		for (int i = 0; i < c.rows; i++)
			for (int j = 0; j < c.cols; j++)
			{
				for (int k = 0; k < acol; k++)
					sum+= *(array + rows * i + k)** (b.array + b.rows * k + j);
				*(c.array + c.rows * i + j) = sum;
				sum = 0;
			}
		c.ShowData();
	}
	else
	{
		cout << "Cannot multiply two matrices. The matrix multiplication condition must be satisfied." << endl;
		return;
	}
}

int main()
{
	srand((unsigned int)(time(NULL)));
	Matrix A(AROWS, ACOLS);
	Matrix B(BROWS, BCOLS);
	Matrix C(CROWS, CCOLS);
	
	A.GetData();
	B.GetData();
	cout << "Matrix A" << endl << endl;
	A.ShowData();
	cout << "Matrix B" << endl << endl;
	B.ShowData();
	cout << "Matrix C = A * B" << endl << endl;
	A.Multiply(B, C, ACOLS, BROWS);
	
	getchar();
	return 0;
}