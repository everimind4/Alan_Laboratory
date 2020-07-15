#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void input(int);
void prime(int);
void main(void)
{
	puts("Please enter a positive integer.\n");
	long num = 0;
	scanf("%d", &num);
	input(num);
}
void input(int n)
{
	if (n >= 2)
		prime(n);
	else
	{
		puts("\nProgram error!\n\nPlease enter a positive integer (>=2).\n");
		scanf("%d", &n);
		input(n);
	}
}

void prime(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n % i != 0)
			continue;
		else
		{
			printf("\n%ld is not a prime.\n", n);
			return;
		}
	}
	printf("\n%ld is a prime!\n", n);
}