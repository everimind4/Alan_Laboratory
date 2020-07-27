#include <stdio.h>

void change(int* num);

void main()
{
	const int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < 10; i++)
		printf("%d ", num[i]);
	
	/* It can't be run.
	for (int i = 0; i < 10; i++)
		*(num + i) = 5;
	*/
	change(num);
	puts("");
	for (int i = 0; i < 10; i++)
		printf("%d ", num[i]);
}

void change(int* num) // How do this 'pointer to constant' change constant value? (VS2019 C Compiler)
{
	for (int i = 0; i < 10; i++)
		*(num + i) = 5;
}