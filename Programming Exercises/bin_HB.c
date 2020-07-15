#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void binary(long);

void main()
{
	long num;
	while (1)
	{
		printf("0���� ū ������ �ϳ� �Է��ϼ��� : ");
		if (scanf("%ld", &num) == 0 )
		{
			printf("\n���ڸ� �Է��ϼ���.\n\n");
			getchar();
			continue;
		}
		if (num == 0)
		{
			printf("\n���� �� �� ����\n\n");
			continue;
		}
		if (num < 0)
		{
			printf("\n������ �Է��ϼ̽��ϴ�.\n\n");
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
	printf("\n���� �� ");
	for (i = i - 1; i >= 0; i--)
	{
		if (*(bin + i) == 1)
			printf("ȫ");
		else
			printf("��");
	}
	printf(" ����\n\n");
	free(bin);
}