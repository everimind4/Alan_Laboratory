#include <stdio.h>
// 3 for loop
void main(void)
{
	for (int i = 1; i < 10; i += 3)
	{
		for (int j = 1; j < 10; j++)
		{
			for (int k = i; k < i + 3; k++)
			{
				printf("%d * %d = %2d", k, j, k * j);
				if (k != i + 2)
					printf("  ");
			}
			puts("");
		}
		puts("");
	}
}

/* 2 for loop
void main(void)
{
	for (int i = 1; i < 10; i+=3)
	{
		for (int j = 1; j < 10; j++)
			printf("%d * %d = %2d  %d * %d = %2d  %d * %d = %2d\n", i, j, i * j, i + 1, j, (i + 1) * j, i + 2, j, (i + 2) * j);
		puts("");
	}
	puts("");
}
*/