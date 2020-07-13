#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int num = 0;
	int pb_1 = 0, pb_2 = 1, n = 0, fact = 1;
	while (1)
	{
		printf("Please enter a integer ( 5 <= int <= 20 ) : ");
		if (scanf("%d", &num) == 0)
		{
			printf("\nProgram Error! Try again.\n\n");
			getchar();
			continue;
		}
		if (num < 5 || num > 20)
		{
			printf("\nWrong Number! Try again.\n\n");
			getchar();
			continue;
		}
		printf("\n* Fibonacci sequence of as many as entered.\n\n");
		for (int i = 0; i < num; i++)
		{
			printf("%d", pb_1);
			if (i != num - 1)
				printf(" ");
			else
				break;
			n = pb_1 + pb_2;
			pb_1 = pb_2;
			pb_2 = n;
		}
		printf("\n\n* Factorial calculation of entered number.\n\n");
		for (int i = 0; i < num; i++)
		{
			printf("%d", num - i);
			if (i != num - 1)
				printf(" * ");
			else
				printf(" = ");
			fact *= num - i;
		}
		printf("%d\n\n", fact);
		num = 0, pb_1 = 0, pb_2 = 1, n = 1, fact = 1;
	}
}