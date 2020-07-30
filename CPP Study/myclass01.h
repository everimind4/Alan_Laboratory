#include <iostream>
#include <time.h>

using namespace std;

#define ROWS 5
#define COLS 5

class myclass01 {
	int table[ROWS][COLS] = { 0, };
	int** pMatrix;
	int rows, cols;
public:
	myclass01();
	void setMatrix(int, int);
	void displayTable();
	void displayMatrix();
	~myclass01();
};

myclass01::myclass01()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			table[i][j] = rand() % 51 + 50;
	pMatrix = NULL;
}

void myclass01::setMatrix(int row, int col)
{
	rows = row;
	cols = col;
	pMatrix = new int*[rows];			// (int**)pMatrix = (int**)malloc(sizeof(int*) * row);
	for (int i = 0; i < cols; ++i)
		*(pMatrix + i) = new int[cols];	// pMatrix = (int*)malloc(sizeof(int) * col);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(*(pMatrix + i) + j) = rand() % 51;
}

void myclass01::displayTable()
{
	cout << "Class Member - Table (by Constructor)" << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << table[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
}

void myclass01::displayMatrix()
{
	cout << "Class Member - Matrix (by Method)" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%2d ", *(*(pMatrix + i) + j));
		cout << endl;
	}
}

myclass01::~myclass01()
{
	for (int i = 0; i < rows; i++)
		delete* (pMatrix + i);	// free(*(pMatrix + i)); = free(pMatrix[i]);
	delete pMatrix;				// free(pMatrix);
}