// ������ �ڵ� �ǽ�

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	printf("�������� ����ϴ� ���α׷��Դϴ�.\n\n1~9 ������ ���ڸ� �ϳ� �Է��ϼ���. : ");
	int num;
	scanf("%d", &num);
	for (int n = 1; n < 10; n++)
	{
		if (num >= 1 && num < 10)
			printf("\n%d * %d = %d\n", num, n, num * n);
		else
		{
			printf("\n�߸��� ���ڸ� �Է��ϼ̽��ϴ�.\n\n'1~9' ������ ���ڸ� �ϳ� �Է��ϼ���. : ");
			scanf("%d", &num);
			n = 0;
		}
	}
	printf("\n");
}