#include <stdio.h>
#include <limits.h>

void main()
{
	int temp;
	int array[10]= { 6, 30, 17, 28, 3, 46, 10, 13, 34, 20 };

	for (int i = 0; i < 9; i++)
	{
		int min = INT_MAX;
		int minidx = 0;
		for (int j = i; j < 10; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				minidx = j;
			}
		}
		temp = array[i];
		array[i] = min;
		array[minidx] = temp;
	}
	for (int k = 0; k < 10 ; k++)
		printf("%d ", array[k]);
}