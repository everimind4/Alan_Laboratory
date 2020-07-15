#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int input, newline, num_1, num_2, row_add;
	printf("Please enter a integer (1~9) : ");
	while (scanf("%d", &input))
	{
		if (input > 0 && input < 10)
		{
			newline = 9 % input == 0 ? (int)(9 / input) : (int)(9 / input) + 1;
			row_add = 1;
			puts("");
			for (int n = 0; n < newline; n++)
			{
				for (num_2 = 1; num_2 < 10; num_2++)
				{
					for (num_1 = row_add; num_1 < row_add + input; num_1++)
					{
						printf("%d * %d = %2d", num_1, num_2, num_1 * num_2);
						if (num_1 == 9)
							break;
						if (num_1 != row_add + input - 1)
							printf("  ");
					}
					puts("");
				}
				row_add += input;
				puts("");
				if (num_1 == 9 && num_2 == 9)
					break;
			}
		}
		else
		{
			printf("\nWrong number! Try again.\n\nPlease enter a integer (1~9) : ");
			continue;
		}
		printf("Please enter a integer (1~9) : ");
	}
}