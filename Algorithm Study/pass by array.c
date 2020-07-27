#include <stdio.h>

#define ROWS 3
#define COLS 4

void sum_rows(int ar[][COLS], int rows);
void sum_cols(int[][COLS], int);
int sum2d(int(*ar)[COLS], int rows);

void main()
{
	int junk[ROWS][COLS] = {
		{2,4,6,8},
		{3,5,7,9},
		{12,10,8,6}
	};

	sum_rows(junk, ROWS);
	sum_cols(junk, ROWS);
	printf("Sum of all elements = %d\n", sum2d(junk, ROWS));
}

void sum_rows(int ar[][COLS], int rows)
{
	int r, c;
	int total;

	for (r = 0; r < rows; r++)
	{
		total = 0;
		for (c = 0; c < COLS; c++)
			total += ar[r][c];
		printf("row %d : sum = %d\n", r, total);
	}
}

void sum_cols(int ar[][COLS], int rows)
{
	int r, c;
	int total;

	for (c = 0; c < COLS; c++)
	{
		total = 0;
		for (r = 0; r < rows; r++)
			total += ar[r][c];
		printf("col %d : sum = %d\n", c, total);
	}
}

int sum2d(int ar[][COLS], int rows) // no syntax error
{
	int r, c;
	int total = 0;

	for (r = 0; r < rows; r++)
		for (c = 0; c < COLS; c++)
			total += ar[r][c];

	return total;
}