#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//12345678901234567890123456789012345678901
//o  o ooo oooo ooo ooo ooo o   o ooo ooo o
//o o  o o o  o o o o   o   oo  o o   o   o
//oo   o o oooo o o ooo ooo o o o ooo ooo o
//o o  o o o o  o o   o o   o  oo   o o   o
//o  o ooo o  o ooo ooo ooo o   o ooo ooo o
//
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooo   ooooooooooooooooooooo   ooooooo
//ooooooo   ooooooooooooooooooooo   ooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooo ooooooooooooooooooooooooooooooooo ooo
//ooo ooooooooooooooooooooooooooooooooo ooo
//ooo  ooooooooooooooooooooooooooooooo  ooo
//oooo  ooooooooooooooooooooooooooooo  oooo
//ooooo o   ooooooooooooooooooooo   o ooooo
//ooooooo   o    ooooooooooo    o   ooooooo
//ooooooooooo    o    o    o    ooooooooooo
//oooooooooooooooo    o    oooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo
//ooooooooooooooooooooooooooooooooooooooooo

void main()
{
	char ch = '\0';
	while (1)
	{
		printf("Enter a character : ");
		scanf("%c", &ch);
		getchar();
		puts("");
		printf("%c  %c %c%c%c %c%c%c%c %c%c%c %c%c%c %c%c%c %c   %c %c%c%c %c%c%c %c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
		printf("%c %c  %c %c %c  %c %c %c %c   %c   %c%c  %c %c   %c   %c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
		printf("%c%c   %c %c %c%c%c%c %c %c %c%c%c %c%c%c %c %c %c %c%c%c %c%c%c %c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
		printf("%c %c  %c %c %c %c  %c %c   %c %c   %c  %c%c   %c %c   %c\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
		printf("%c  %c %c%c%c %c  %c %c%c%c %c%c%c %c%c%c %c   %c %c%c%c %c%c%c %c\n\n", ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch, ch);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j <= 40; j++)	printf("%c", ch); puts("");
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 7; j++)		printf("%c", ch); printf("   ");
			for (int j = 0; j < 21; j++)	printf("%c", ch); printf("   ");
			for (int j = 0; j < 7; j++)		printf("%c", ch); puts("");
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j <= 40; j++)	printf("%c", ch); puts("");
		}
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)		printf("%c", ch); printf(" ");
			for (int j = 0; j < 33; j++)	printf("%c", ch); printf(" ");
			for (int j = 0; j < 3; j++)		printf("%c", ch); puts("");
		}
			for (int j = 0; j < 3; j++)		printf("%c", ch); printf("  ");
			for (int j = 0; j < 31; j++)	printf("%c", ch); printf("  ");
			for (int j = 0; j < 3; j++)		printf("%c", ch); puts("");
			for (int j = 0; j < 4; j++)		printf("%c", ch); printf("  ");
			for (int j = 0; j < 29; j++)	printf("%c", ch); printf("  ");
			for (int j = 0; j < 4; j++)		printf("%c", ch); puts("");
			for (int j = 0; j < 5; j++)		printf("%c", ch); printf(" "); printf("%c", ch); printf("   ");
			for (int j = 0; j < 21; j++)	printf("%c", ch); printf("   "); printf("%c", ch); printf(" ");
			for (int j = 0; j < 5; j++)		printf("%c", ch); puts("");
			for (int j = 0; j < 7; j++)		printf("%c", ch); printf("   "); printf("%c", ch); printf("    ");
			for (int j = 0; j < 11; j++)	printf("%c", ch); printf("    "); printf("%c", ch); printf("   ");
			for (int j = 0; j < 7; j++)		printf("%c", ch); puts("");
			for (int j = 0; j < 11; j++)	printf("%c", ch);
			for (int i = 0; i < 3; i++)
			{
				printf("    "); printf("%c", ch);
			}	printf("    ");
			for (int j = 0; j < 11; j++)	printf("%c", ch); puts("");
			for (int j = 0; j < 16; j++)	printf("%c", ch); printf("    "); printf("%c", ch); printf("    ");
			for (int j = 0; j < 16; j++)	printf("%c", ch); puts("");
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j <= 40; j++)	printf("%c", ch); puts("");
		}
		puts("");
	}
}