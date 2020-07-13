#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 100
#define COL 3

void gradeTout(int grade[][3]);
void gradeBout(int grade[][3]);

void main()
{
	int grade[ROW][COL] = { 0, };			// Data 할당
	srand((unsigned int)time(0));			// 난수 발생 시드지정
	printf("       국어 영어 수학\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			grade[i][j] = rand() % 51 + 50;
			if (j == 0)
				printf("#%3d : ", i + 1);
			printf("%3d  ", grade[i][j]);
			if (j == 2)
				puts("");
		}
	}
	gradeTout(grade);
	gradeBout(grade);
}

void gradeTout(int data[ROW][COL])
{
	FILE* grade = fopen("grade.txt", "wt");

	fprintf(grade, "       국어 영어 수학\n");
	if (!grade)
	{
		printf("Error to create Text File!\n");
		return;
	}
	for (int i = 0; i < 100; i++)
		fprintf(grade, "#%3d : %3d  %3d  %3d\n", i + 1, data[i][0], data[i][1], data[i][2]);
	fclose(grade);

	/*for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			data[i][j] = rand() % 51 + 50;
			if (j == 0)
				fprintf(grade, "#%3d : ", i + 1);
			fprintf(grade, "%3d  ", data[i][j]);
			if (j == 2)
			{
				if (i == 99)
					break;
				fprintf(grade, "\n");
			}
		}
	}
	fclose(grade);*/
}

void gradeBout(int data[ROW][COL])
{
	FILE* grade = fopen("grade.dat", "wb");

	if (!grade)
	{
		printf("Error to create Binary File!\n");
		return;
	}
	for (int j = 0; j < 100; j++)
		fwrite(data[j], sizeof(int), 3, grade);
	fclose(grade);

	//fprintf(grade, "       국어 영어 수학\n");
	//for (int i = 0; i < 100; i++)
	//{
	//	for (int j = 0; j < 3; j++)
	//	{
	//		data[i][j] = rand() % 51 + 50;
	//		if (j == 0)
	//			fprintf(grade, "#%3d : ", i + 1);
	//		fprintf(grade, "%3d  ", data[i][j]);
	//		if (j == 2)
	//		{
	//			if (i == 99)
	//				break;
	//			fprintf(grade, "\n");
	//		}
	//	}
	//}
	//fclose(grade);
}