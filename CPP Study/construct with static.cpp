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
	static int idx;
	static int* array;
	int start;

public:

	Matrix() : rows(0), cols(0), start(0) {}
	Matrix(int, int);
	~Matrix();
	void GetData();
	void ShowData();
	void Add(Matrix&);
	void Multiply(Matrix&, Matrix&, int, int);
};

int Matrix::idx = 0;
int* Matrix::array = new int[100];

Matrix::Matrix(int a, int b)
{
	rows = a;
	cols = b;
	start = idx;
	idx += rows * cols;
}

Matrix::~Matrix()
{
	delete(array);
}

void Matrix::GetData()
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(array + start + cols * i + j) = rand() % 10;
}

void Matrix::ShowData()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%4d", *(array + start + cols * i + j));
		cout << endl;
	}
	cout << endl;
}

void Matrix::Add(Matrix& a)
{
	for (int i = 0; i < rows * cols; i++)
		*(array + start + i) += *(a.array + a.start + i);
	ShowData();
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
					sum += *(array + start + cols * i + k) * *(b.array + b.start + b.cols * k + j);
				*(c.array + c.start + c.cols * i + j) = sum;
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
	Matrix A1(AROWS, ACOLS);
	Matrix B(BROWS, BCOLS);
	Matrix C(CROWS, CCOLS);

	A.GetData();
	A1.GetData();
	B.GetData();
	cout << "Matrix A" << endl << endl;
	A.ShowData();
	cout << "Matrix A1" << endl << endl;
	A1.ShowData();
	cout << "Matrix B" << endl << endl;
	B.ShowData();
	cout << "Matrix A = A + A1" << endl << endl;
	A.Add(A1);
	cout << "Matrix C = A * B" << endl << endl;
	A.Multiply(B, C, ACOLS, BROWS);

	getchar();
	return 0;
}