#include "MazeRunner.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13

#define MENUINITROW 90
#define MENUINITCOL 35
#define MENUCOLDIST 8

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
    go(row, col++);  printf("���������������������������������������������������������������");
    go(row, col);    printf("��"); go(row + 122, col++); printf("��");
    go(row, col);    printf("��"); go(row + 122, col++); printf("��");

    go(row, col);    printf("��"); go(row + 12, col++);  printf("�����  ��  ��      ����    ��    ��������        �����    ��    ��        �� ���������   ��");
    go(row, col);    printf("��"); go(row + 11, col++);  printf("��    ��  ��  ��    ��      ��  ��          ��                    ��    ��    ��        ��                     ��");
    go(row, col);    printf("��"); go(row + 10, col++);  printf("��    ��  ��  ��    ��      ��  ��        ��  ��                  ��    ��    ��        �� ��������       ��");
    go(row, col);    printf("��"); go(row + 9, col++);   printf("��    ����  ��    ��      ��  ��      ��      ��          �����  ���    ��    ����                       ��");
    go(row, col);    printf("��"); go(row + 8, col++);   printf("��    ��  ��  ��    ��      ��  ��    ��          ��        ��          ��    ��        �� �������           ��");
    go(row, col);    printf("��"); go(row + 7, col++);   printf("��    ��  ��  ��    ��      ��  ��                          ��          ��    ��        ��                         ��");
    go(row, col);    printf("��"); go(row + 6, col++);   printf("�����  ��  ��      ����    ��    ��������        �����    ��    �����  �� ������               ��");

    go(row, col);    printf("��"); go(row + 122, col++); printf("��");
    go(row, col);    printf("��"); go(row + 122, col++); printf("��");
    go(row, col);    printf("���������������������������������������������������������������");
}

void DrawMenu() {
    // Menu
    int row = MENUINITROW, col = MENUINITCOL;
    col += MENUCOLDIST;
    go(row, col);       printf("�����  ����    ���    ����    ����");
    go(row, col + 1);   printf("��          ��    ��    ��  ��    ��    ��");
    go(row, col + 2);   printf("�����    ��    �����  ����      ��");
    go(row, col + 3);   printf("      ��    ��    ��    ��  ��    ��    ��");
    go(row, col + 4);   printf("�����    ��    ��    ��  ��    ��    ��");
    row += 6; col += MENUCOLDIST;
    go(row, col);       printf("�����  ��  ��  ����  ����");
    go(row, col + 1);   printf("��         ���     ��      ��");
    go(row, col + 2);   printf("�����    ��      ��      ��");
    go(row, col + 3);   printf("��         ���     ��      ��");
    go(row, col + 4);   printf("�����  ��  ��  ����    ��");
}

void PrintCopyright() {
    go(88, 64); printf("Copyright 2020. Youngin Choi All right reserved.");
}

int SelectMenu() {
    char key;
    int menu = 0;
    int level = 2;
    ShowSelected(menu);
    ShowLevel(level);
    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ENTER) {
                if (menu == 1)
                    switch (level)
                    default: return level;
                else if (menu == 2)
                    return -1;
            }
            else if (key == -32) {
                key = _getch();
                switch (key) {
                case UP:
                    menu--;
                    if (menu < 0) menu += 3; 
                    break;
                case DOWN:
                    menu = (menu + 1) % 3;
                    break;
                case LEFT:
                    if (menu == 0) {
                        level--;
                        if (level < 0) level += 5;
                        ShowLevel(level);
                    }
                    break;
                case RIGHT:
                    if (menu == 0) {
                        level++;
                        if (level >= 5) level %= 5;
                        ShowLevel(level);
                    }
                    break;
                }
                ShowSelected(menu);
            }
        }
    }
}

void ShowSelected(int menu) {
    int row = MENUINITROW - 10, col = MENUINITCOL + menu * MENUCOLDIST;
    const int levelarrowdist = 58;
    const int levelarrowwidth = 10;
    for (int i = 0; i < 3; i++) {
        if (i != 0) {
            go(row,     MENUINITCOL + i * MENUCOLDIST);     printf("��");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 1); printf("��");
            go(row + 4, MENUINITCOL + i * MENUCOLDIST + 2); printf("��");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 3); printf("��");
            go(row,     MENUINITCOL + i * MENUCOLDIST + 4); printf("��");
        }
        else
        {
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST);     printf("��");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1); printf("��");
            go(row - levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST + 2); printf("��");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3); printf("��");
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 4); printf("��");
            row += levelarrowdist;
            go(row + levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST);     printf("��");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1); printf("��");
            go(row + 4 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 2); printf("��");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3); printf("��");
            go(row + levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST + 4); printf("��");
            row -= levelarrowdist;
        }
    }
    if (menu != 0) {
        go(row, col);           printf("��");
        go(row + 2, col + 1);   printf("��");
        go(row + 4, col + 2);   printf("��");
        go(row + 2, col + 3);   printf("��");
        go(row, col + 4);       printf("��");
    }
    else {
        go(row + 4 - levelarrowwidth, col);       printf("��");
        go(row + 2 - levelarrowwidth, col + 1);   printf("��");
        go(row - levelarrowwidth,     col + 2);   printf("��");
        go(row + 2 - levelarrowwidth, col + 3);   printf("��");
        go(row + 4 - levelarrowwidth, col + 4);   printf("��");
        row += levelarrowdist;
        go(row + levelarrowwidth,     col);       printf("��");
        go(row + 2 + levelarrowwidth, col + 1);   printf("��");
        go(row + 4 + levelarrowwidth, col + 2);   printf("��");
        go(row + 2 + levelarrowwidth, col + 3);   printf("��");
        go(row + levelarrowwidth,     col + 4);   printf("��");
    }
}

void ShowLevel(int level) {
    ClearLevelInfo(MENUINITROW, MENUINITCOL);
    switch (level) {
    case 0:
        NEWBIE(MENUINITROW, MENUINITCOL);
        break;
    case 1:
        EASY(MENUINITROW, MENUINITCOL);
        break;
    case 2:
        NORMAL(MENUINITROW, MENUINITCOL);
        break;
    case 3:
        HARD(MENUINITROW, MENUINITCOL);
        break;
    case 4:
        KOREAN(MENUINITROW, MENUINITCOL);
        break;
    }
}

void ClearLevelInfo(int row, int col) {
    row -= 8;
    go(row, col);       printf("                                                            ");
    go(row, col + 1);   printf("                                                            ");
    go(row, col + 2);   printf("                                                            ");
    go(row, col + 3);   printf("                                                            ");
    go(row, col + 4);   printf("                                                            ");
}

void NEWBIE(int row, int col) {
    row -= 8;
    go(row, col);       printf("��      ��  �����  ��  ��  ��  ����    ����  �����");
    go(row, col + 1);   printf("���    ��  ��        ��  ��  ��  ��    ��    ��    ��");
    go(row, col + 2);   printf("��  ��  ��  �����  ��  ��  ��  ����      ��    �����");
    go(row, col + 3);   printf("��    ���  ��         �����   ��    ��    ��    ��");
    go(row, col + 4);   printf("��      ��  �����    ��  ��    ����    ����  �����");
}

void EASY(int row, int col) {
    row += 3;
    go(row, col);       printf("�����    ���    �����  ��    ��");
    go(row, col + 1);   printf("��        ��    ��  ��         ��  ��");
    go(row, col + 2);   printf("�����  �����  �����    ���");
    go(row, col + 3);   printf("��        ��    ��        ��     ��");
    go(row, col + 4);   printf("�����  ��    ��  �����     ��");
}

void NORMAL(int row, int col) {
    row -= 8;
    go(row, col);       printf("��      ��    ���    ����    ��      ��    ���    ��");
    go(row, col + 1);   printf("���    ��  ��    ��  ��    ��  ���  ���  ��    ��  ��");
    go(row, col + 2);   printf("��  ��  ��  ��    ��  ����    ��  ��  ��  �����  ��");
    go(row, col + 3);   printf("��    ���  ��    ��  ��    ��  ��      ��  ��    ��  ��");
    go(row, col + 4);   printf("��      ��    ���    ��    ��  ��      ��  ��    ��  ����");
}

void HARD(int row, int col) {
    row += 3;
    go(row, col);       printf("��    ��    ���    ����    ����");
    go(row, col + 1);   printf("��    ��  ��    ��  ��    ��  ��    ��");
    go(row, col + 2);   printf("�����  �����  ����    ��    ��");
    go(row, col + 3);   printf("��    ��  ��    ��  ��    ��  ��    ��");
    go(row, col + 4);   printf("��    ��  ��    ��  ��    ��  ����");
}

void KOREAN(int row, int col) {
    row -= 8;
    go(row, col);       printf("��    ��    ���    ����    �����    ���    ��      ��");
    go(row, col + 1);   printf("��  ��    ��    ��  ��    ��  ��        ��    ��  ���    ��");
    go(row, col + 2);   printf("���      ��    ��  ����    �����  �����  ��  ��  ��");
    go(row, col + 3);   printf("��  ��    ��    ��  ��    ��  ��        ��    ��  ��    ���");
    go(row, col + 4);   printf("��    ��    ���    ��    ��  �����  ��    ��  ��      ��");
}

void Play(int option) {
    if (option == -1)
        return;
    system("cls");
    int row, col;
    switch (option) {
    case 0:
        row = 18, col = 13;
        break;
    case 1:
        row = 28, col = 18;
        break;
    case 2:
        row = 38, col = 23;
        break;
    case 3:
        row = 48, col = 28;
        break;
    case 4:
        row = 58, col = 33;
        break;
    }
    MazeGenerator(row, col);
}

void MazeGenerator(int row, int col) {
    
}