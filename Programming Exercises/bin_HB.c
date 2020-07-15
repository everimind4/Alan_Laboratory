#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void binary(long);

void main()
{
	long num;
	while (1)
	{
		printf("0보다 큰 정수를 하나 입력하세요 : ");
		if (scanf("%ld", &num) == 0 )
		{
			printf("\n숫자를 입력하세요.\n\n");
			getchar();
			continue;
		}
		if (num == 0)
		{
			printf("\n웰컴 투 봉 월드\n\n");
			continue;
		}
		if (num < 0)
		{
			printf("\n음수를 입력하셨습니다.\n\n");
			continue;				
		}
		binary(num);
	}
}

void binary(long num)
{
	int idx = 0;
	int i = 0;
	for (int i = num; i > 0; i /= 2)
		idx++;
	long* bin = malloc(sizeof(long*) * idx);
	for (i = 0; i < idx; i++)
	{
		*(bin + i) = num % 2;
		num /= 2;
	}
	printf("\n웰컴 투 ");
	for (i = i - 1; i >= 0; i--)
	{
		if (*(bin + i) == 1)
			printf("홍");
		else
			printf("봉");
	}
	printf(" 월드\n\n");
	free(bin);
}