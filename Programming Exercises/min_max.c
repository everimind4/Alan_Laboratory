#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int largest(int ar[], int n);
int largest_idx(int* start, int* end);

void main()
{
	int marbles[SIZE] = { 20,10,5,39,4,16,19,26,31,20 };
	int answer_1 = largest(marbles, SIZE);
	printf("The largest number of marbles is %d.\n\n", answer_1);
	int answer_2 = largest_idx(marbles, marbles + SIZE);
	printf("The largest number of marbles is %d.\n\n", marbles[answer_2]);

	system("pause");
}

int largest(int ar[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
		if (*(ar + i) > max)
			max = *(ar + i);
	return max;
}

int largest_idx(int* start, int* end)
{
	int max = 0;
	int idx = 0;
	int* temp = start;
	while (temp < end)
	{
		if (*temp > max)
		{
			max = *temp;
			idx = temp - start;
		}
		temp++;
	}
	return idx;
}