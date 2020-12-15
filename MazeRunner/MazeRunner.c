#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define ALIGN "                                                   "

void go(int, int);

int main()
{
    system("cls | color 3E"); // Set Console Color
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); // Set Fullscreen Mode
    int row = 54, col = 10;

    // Title :: 메이즈러너
    go(row, col++);  printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); puts("");
    go(row, col);    printf("■"); go(row + 118, col++); printf("■"); puts("");
    go(row, col);    printf("■"); go(row + 118, col++); printf("■"); puts("");

    go(row, col);    printf("■"); go(row + 12, col++);  printf("■■■■  ■  ■      ■■■    ■    ■■■■■■■    ■■■■    ■    ■        ■ ■■■■■■■■   ■"); puts("");
    go(row, col);    printf("■"); go(row + 11, col++);  printf("■    ■  ■  ■    ■      ■  ■          ■                ■    ■    ■        ■                     ■"); puts("");
    go(row, col);    printf("■"); go(row + 10, col++);  printf("■    ■  ■  ■    ■      ■  ■        ■  ■              ■    ■    ■        ■ ■■■■■■■       ■"); puts("");
    go(row, col);    printf("■"); go(row + 9, col++);   printf("■    ■■■  ■    ■      ■  ■      ■      ■      ■■■■  ■■    ■    ■■■                       ■"); puts("");
    go(row, col);    printf("■"); go(row + 8, col++);   printf("■    ■  ■  ■    ■      ■  ■    ■          ■    ■          ■    ■        ■ ■■■■■■           ■"); puts("");
    go(row, col);    printf("■"); go(row + 7, col++);   printf("■    ■  ■  ■    ■      ■  ■                      ■          ■    ■        ■                         ■"); puts("");
    go(row, col);    printf("■"); go(row + 6, col++);   printf("■■■■  ■  ■      ■■■    ■    ■■■■■■■    ■■■■    ■    ■■■■  ■ ■■■■■               ■"); puts("");
    
    go(row, col);    printf("■"); go(row + 118, col++); printf("■"); puts("");
    go(row, col);    printf("■"); go(row + 118, col++); printf("■"); puts("");
    go(row, col);    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■"); puts("");

    // Menu
    col = 35;
    go(row + 30, col);

    printf("test");


}

void go(int x, int y)
{
    COORD point = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
