#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 3

void multi(int[][N], int[][N], int[][N]);
void printm(int[][N]);

void main()
{
	int M1[N][N] = { 0, };
	int M2[N][N] = { 0, };
	int Result[N][N] = { 0, };
	srand((unsigned int)time(NULL));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			M1[i][j] = rand() % 5;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			M2[i][j] = rand() % 5;
	printf("Matrix 1\n");
	printm(M1);
	printf("Matrix 2\n");
	printm(M2);
	multi(M1, M2, Result);
	printf("Multiplication of M1 and M2\n");
	printm(Result);

	int I[N][N] = { 0, }; // Identity Matrix
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (i == j)
				I[i][j] = 1;
			else
				I[i][j] = 0;
		}
}

void printm(int M[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			printf("%2d ", M[i][j]);
		puts("");
	}
}

void multi(int M1[][N], int M2[][N], int result[][N])
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			*(*(result + i) + j) = M1[i][0] * M2[0][j] + M1[i][1] * M2[1][j] + M1[i][2] * M2[2][j];
}