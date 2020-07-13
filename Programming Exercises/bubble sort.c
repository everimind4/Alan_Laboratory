#include <stdio.h>
#include <limits.h>

int main()
{
	int temp;
	int array[10] = { 6, 30, 17, 28, 3, 46, 10, 13, 34, 20 };

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < (9 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
	for (int k = 0; k < 10; k++)
		printf("%d ", array[k]);
	return 0;
}