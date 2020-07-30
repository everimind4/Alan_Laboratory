#include "myclass01.h"

int main()
{
	myclass01 test;
	test.setMatrix(ROWS, COLS);
	test.displayTable();
	test.displayMatrix();

	getchar();
	return 0;
}