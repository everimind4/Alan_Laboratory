// 구구단 코드 실습

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	printf("구구단을 출력하는 프로그램입니다.\n\n1~9 사이의 숫자를 하나 입력하세요. : ");
	int num;
	scanf("%d", &num);
	for (int n = 1; n < 10; n++)
	{
		if (num >= 1 && num < 10)
			printf("\n%d * %d = %d\n", num, n, num * n);
		else
		{
			printf("\n잘못된 숫자를 입력하셨습니다.\n\n'1~9' 사이의 숫자를 하나 입력하세요. : ");
			scanf("%d", &num);
			n = 0;
		}
	}
	printf("\n");
}