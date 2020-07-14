#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void printTXT(int**, int);
void printBIN(int**, int);

void main()
{
	while (1)
	{
		printf("Please enter an integer of size of square 2D array want to make. (Size >= 2)\n\nSize : ");
		int natural = 1;
		int size;
		if (scanf("%d", &size) == 0)
		{
			printf("Program Error! Try again.\n\n");
			continue;
		}
		if (size < 2)
		{
			printf("Wrong number! Try again.\n\n");
			continue;
		}
		int** array;
		array = (int**)malloc(sizeof(int*) * size);
		for (int i = 0; i < size; i++)
			array[i] = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				*(*(array+i)+j) = natural;
				natural++;
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				printf("%2d ", *(*(array + i) + j));
			puts("");
		}
		// printTXT(array, size);
		// printBIN(array, size);
	}
}

void printTXT(int** array, int size)
{
	FILE* print = fopen("array.txt", "wt");

	if (!print)
	{
		printf("Error to create Text File!\n");
		return;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fprintf("%2d ", *(*(array + i) + j));
		puts("");
	}
	fclose(print);
}

//void printBIN(int** array, int size)
//{
//	FILE* print = fopen("array.dat", "wb");
//
//	if (!print)
//	{
//		printf("Error to create Binary File!\n");
//		return;
//	}
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < size; j++)
//			fprintf(*(*(array + i) + j), "%2d ");
//		puts("");
//	}
//	fclose(print);
//}