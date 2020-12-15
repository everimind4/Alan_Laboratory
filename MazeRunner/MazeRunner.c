#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void go(int, int);
void DrawTitle();
void DrawMenu();

int main()
{
    system("cls | color 3E"); // Set Console Color
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0); // Set Fullscreen Mode

    DrawTitle();
    DrawMenu();

}

void go(int x, int y)
{
    COORD point = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void DrawTitle() {
    int row = 50, col = 10;
    go(row, col++);  printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
    go(row, col);    printf("■"); go(row + 122, col++); printf("■");
    go(row, col);    printf("■"); go(row + 122, col++); printf("■");

    go(row, col);    printf("■"); go(row + 12, col++);  printf("■■■■  ■  ■      ■■■    ■    ■■■■■■■        ■■■■    ■    ■        ■ ■■■■■■■■   ■");
    go(row, col);    printf("■"); go(row + 11, col++);  printf("■    ■  ■  ■    ■      ■  ■          ■                    ■    ■    ■        ■                     ■");
    go(row, col);    printf("■"); go(row + 10, col++);  printf("■    ■  ■  ■    ■      ■  ■        ■  ■                  ■    ■    ■        ■ ■■■■■■■       ■");
    go(row, col);    printf("■"); go(row + 9, col++);   printf("■    ■■■  ■    ■      ■  ■      ■      ■          ■■■■  ■■    ■    ■■■                       ■");
    go(row, col);    printf("■"); go(row + 8, col++);   printf("■    ■  ■  ■    ■      ■  ■    ■          ■        ■          ■    ■        ■ ■■■■■■           ■");
    go(row, col);    printf("■"); go(row + 7, col++);   printf("■    ■  ■  ■    ■      ■  ■                          ■          ■    ■        ■                         ■");
    go(row, col);    printf("■"); go(row + 6, col++);   printf("■■■■  ■  ■      ■■■    ■    ■■■■■■■        ■■■■    ■    ■■■■  ■ ■■■■■               ■");

    go(row, col);    printf("■"); go(row + 122, col++); printf("■");
    go(row, col);    printf("■"); go(row + 122, col++); printf("■");
    go(row, col);    printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
}

void DrawMenu() {
    // Menu
    int row = 90, col = 40;
    go(row, col++); printf("■■■■  ■■■    ■■    ■■■    ■■■");
    go(row, col++); printf("■          ■    ■    ■  ■    ■    ■");
    go(row, col++); printf("■■■■    ■    ■■■■  ■■■      ■");
    go(row, col++); printf("      ■    ■    ■    ■  ■    ■    ■");
    go(row, col++); printf("■■■■    ■    ■    ■  ■    ■    ■");
    row += 8; col += 3;
    go(row, col++); printf("■■■■  ■  ■  ■  ■■■");
    go(row, col++); printf("■         ■■   ■    ■");
    go(row, col++); printf("■■■■    ■    ■    ■");
    go(row, col++); printf("■         ■■   ■    ■");
    go(row, col++); printf("■■■■  ■  ■  ■    ■");
}
