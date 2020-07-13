
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <conio.h>

void game_start(const char*);
void delay(clock_t n);

void main()
{
	char start;
	char ball[30][105] = { "", };
	const char* table = ball;


	// 	for (int i = 1; i < 105; i += 2);

		/*char bar[19] = "¡á¡á¡á¡á¡á¡á¡á¡á¡á";
		game_start();
		start = _getch();
		while (1)
		{
			if (start == 's' || start == 'S')
				break;
			printf("%c", start);
			start = _getch();
		}*/

}

/*while (true)
{
	printf(" ");
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 51; j++)
			printf("¡à");
		puts("");
	}

	delay(1000);
}
getchar();*/

void game_start(const char* table)
{
	const char STAR1[] = "****************************************";
	const char STAR2[] = "*                                      *";
	/**table[15]+32 = STAR1;
	puts(table[16][32]);*/
	puts(STAR2);
	puts("*   Press S to start Break out Game!   *");
	puts(STAR2);
	puts(STAR1);
}

void delay(clock_t n)
{
	clock_t start = clock();
	while (clock() - start < n);
}