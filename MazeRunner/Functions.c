#include "MazeRunner.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

void Fullscreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void SetConsoleColor() {
    system("color 3E"); // Set Console Color
}

void ClearConsole() {
    system("cls");
}

void go(int x, int y)
{
    COORD point = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void CursorView(int option) {
    CONSOLE_CURSOR_INFO cursorInfo = { 0, };
    cursorInfo.bVisible = option;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void DrawTitle() {
    int row = 50, col = 12;
    go(row, col++);  printf("бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");
    go(row, col);    printf("бс"); go(row + 122, col++); printf("бс");
    go(row, col);    printf("бс"); go(row + 122, col++); printf("бс");

    go(row, col);    printf("бс"); go(row + 12, col++);  printf("бсбсбсбс  бс  бс      бсбсбс    бс    бсбсбсбсбсбсбс        бсбсбсбс    бс    бс        бс бсбсбсбсбсбсбсбс   бс");
    go(row, col);    printf("бс"); go(row + 11, col++);  printf("бс    бс  бс  бс    бс      бс  бс          бс                    бс    бс    бс        бс                     бс");
    go(row, col);    printf("бс"); go(row + 10, col++);  printf("бс    бс  бс  бс    бс      бс  бс        бс  бс                  бс    бс    бс        бс бсбсбсбсбсбсбс       бс");
    go(row, col);    printf("бс"); go(row + 9, col++);   printf("бс    бсбсбс  бс    бс      бс  бс      бс      бс          бсбсбсбс  бсбс    бс    бсбсбс                       бс");
    go(row, col);    printf("бс"); go(row + 8, col++);   printf("бс    бс  бс  бс    бс      бс  бс    бс          бс        бс          бс    бс        бс бсбсбсбсбсбс           бс");
    go(row, col);    printf("бс"); go(row + 7, col++);   printf("бс    бс  бс  бс    бс      бс  бс                          бс          бс    бс        бс                         бс");
    go(row, col);    printf("бс"); go(row + 6, col++);   printf("бсбсбсбс  бс  бс      бсбсбс    бс    бсбсбсбсбсбсбс        бсбсбсбс    бс    бсбсбсбс  бс бсбсбсбсбс               бс");

    go(row, col);    printf("бс"); go(row + 122, col++); printf("бс");
    go(row, col);    printf("бс"); go(row + 122, col++); printf("бс");
    go(row, col);    printf("бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");
}

void DrawMenu() {
    // Menu
    int row = 90, col = 42;
    go(row, col++); printf("бсбсбсбс  бсбсбс    бсбс    бсбсбс    бсбсбс");
    go(row, col++); printf("бс          бс    бс    бс  бс    бс    бс");
    go(row, col++); printf("бсбсбсбс    бс    бсбсбсбс  бсбсбс      бс");
    go(row, col++); printf("      бс    бс    бс    бс  бс    бс    бс");
    go(row, col++); printf("бсбсбсбс    бс    бс    бс  бс    бс    бс");
    row += 8; col += 3;
    go(row, col++); printf("бсбсбсбс  бс  бс  бс  бсбсбс");
    go(row, col++); printf("бс         бсбс   бс    бс");
    go(row, col++); printf("бсбсбсбс    бс    бс    бс");
    go(row, col++); printf("бс         бсбс   бс    бс");
    go(row, col++); printf("бсбсбсбс  бс  бс  бс    бс");
}

void PrintCopyright() {
    go(88, 64); printf("Copyright 2020. Youngin Choi All right reserved.");
}

void SelectMenu() {
    char key;
    int menu = 0;
    int level = 0;
    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ENTER) {
                printf("0");
                break;
            }                
            else if (key == -32) {
                key = _getch();
                switch (key) {
                case UP:
                    menu = (menu + 1) % 2;
                    break;
                case DOWN:
                    menu--;
                    if (menu < 0) menu += 2;
                    break;
                case LEFT:
                    level--;
                    if (level < 0) level += 3;
                    break;
                case RIGHT:
                    level = (level + 1) % 3;
                    break;
                }
                switch (menu) {
                case 0:
                    printf("1");
                    break;
                case 1:
                    printf("2");
                    break;
                }
            }
        }
    }
}