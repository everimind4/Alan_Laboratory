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
#define ESC 27

#define MENUINITROW 90
#define MENUINITCOL 35
#define MENUCOLDIST 8

int* maze;

void Fullscreen() {
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void SetConsoleColor() {
    system("color 3E");
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
    int row = MENUINITROW, col = MENUINITCOL;
    col += MENUCOLDIST;
    go(row, col);       printf("■■■■  ■■■    ■■    ■■■    ■■■");
    go(row, col + 1);   printf("■          ■    ■    ■  ■    ■    ■");
    go(row, col + 2);   printf("■■■■    ■    ■■■■  ■■■      ■");
    go(row, col + 3);   printf("      ■    ■    ■    ■  ■    ■    ■");
    go(row, col + 4);   printf("■■■■    ■    ■    ■  ■    ■    ■");
    row += 6; col += MENUCOLDIST;
    go(row, col);       printf("■■■■  ■  ■  ■■■  ■■■");
    go(row, col + 1);   printf("■         ■■     ■      ■");
    go(row, col + 2);   printf("■■■■    ■      ■      ■");
    go(row, col + 3);   printf("■         ■■     ■      ■");
    go(row, col + 4);   printf("■■■■  ■  ■  ■■■    ■");
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
                    if (menu != 0) menu--;
                    break;
                case DOWN:
                    if (menu != 2) menu++;
                    break;
                case LEFT:
                    if (menu == 0) {
                        if (level != 0) level--;
                        ShowLevel(level);
                    }
                    break;
                case RIGHT:
                    if (menu == 0) {
                        if (level != 4) level++;
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
            go(row,     MENUINITCOL + i * MENUCOLDIST);     printf("　");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 1); printf("　");
            go(row + 4, MENUINITCOL + i * MENUCOLDIST + 2); printf("　");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 3); printf("　");
            go(row,     MENUINITCOL + i * MENUCOLDIST + 4); printf("　");
        }
        else
        {
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST);     printf("　");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1); printf("　");
            go(row - levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST + 2); printf("　");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3); printf("　");
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 4); printf("　");
            row += levelarrowdist;
            go(row + levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST);     printf("　");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1); printf("　");
            go(row + 4 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 2); printf("　");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3); printf("　");
            go(row + levelarrowwidth,     MENUINITCOL + i * MENUCOLDIST + 4); printf("　");
            row -= levelarrowdist;
        }
    }
    if (menu != 0) {
        go(row, col);           printf("■");
        go(row + 2, col + 1);   printf("■");
        go(row + 4, col + 2);   printf("■");
        go(row + 2, col + 3);   printf("■");
        go(row, col + 4);       printf("■");
    }
    else {
        go(row + 4 - levelarrowwidth, col);       printf("■");
        go(row + 2 - levelarrowwidth, col + 1);   printf("■");
        go(row - levelarrowwidth,     col + 2);   printf("■");
        go(row + 2 - levelarrowwidth, col + 3);   printf("■");
        go(row + 4 - levelarrowwidth, col + 4);   printf("■");
        row += levelarrowdist;
        go(row + levelarrowwidth,     col);       printf("■");
        go(row + 2 + levelarrowwidth, col + 1);   printf("■");
        go(row + 4 + levelarrowwidth, col + 2);   printf("■");
        go(row + 2 + levelarrowwidth, col + 3);   printf("■");
        go(row + levelarrowwidth,     col + 4);   printf("■");
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
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 3 << 4);
    go(row, col);       printf("■      ■  ■■■■  ■  ■  ■  ■■■    ■■■  ■■■■");
    go(row, col + 1);   printf("■■    ■  ■        ■  ■  ■  ■    ■    ■    ■");
    go(row, col + 2);   printf("■  ■  ■  ■■■■  ■  ■  ■  ■■■      ■    ■■■■");
    go(row, col + 3);   printf("■    ■■  ■         ■■■■   ■    ■    ■    ■");
    go(row, col + 4);   printf("■      ■  ■■■■    ■  ■    ■■■    ■■■  ■■■■");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
}

void EASY(int row, int col) {
    row += 3;
    go(row, col);       printf("■■■■    ■■    ■■■■  ■    ■");
    go(row, col + 1);   printf("■        ■    ■  ■         ■  ■");
    go(row, col + 2);   printf("■■■■  ■■■■  ■■■■    ■■");
    go(row, col + 3);   printf("■        ■    ■        ■     ■");
    go(row, col + 4);   printf("■■■■  ■    ■  ■■■■     ■");
}

void NORMAL(int row, int col) {
    row -= 8;
    go(row, col);       printf("■      ■    ■■    ■■■    ■      ■    ■■    ■");
    go(row, col + 1);   printf("■■    ■  ■    ■  ■    ■  ■■  ■■  ■    ■  ■");
    go(row, col + 2);   printf("■  ■  ■  ■    ■  ■■■    ■  ■  ■  ■■■■  ■");
    go(row, col + 3);   printf("■    ■■  ■    ■  ■    ■  ■      ■  ■    ■  ■");
    go(row, col + 4);   printf("■      ■    ■■    ■    ■  ■      ■  ■    ■  ■■■");
}

void HARD(int row, int col) {
    row += 3;
    go(row, col);       printf("■    ■    ■■    ■■■    ■■■");
    go(row, col + 1);   printf("■    ■  ■    ■  ■    ■  ■    ■");
    go(row, col + 2);   printf("■■■■  ■■■■  ■■■    ■    ■");
    go(row, col + 3);   printf("■    ■  ■    ■  ■    ■  ■    ■");
    go(row, col + 4);   printf("■    ■  ■    ■  ■    ■  ■■■");
}

void KOREAN(int row, int col) {
    row -= 8;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    go(row, col);       printf("■    ■    ■■    ■■■    ■■■■    ■■    ■      ■");
    go(row, col + 1);   printf("■  ■    ■    ■  ■    ■  ■        ■    ■  ■■    ■");
    go(row, col + 2);   printf("■■      ■    ■  ■■■    ■■■■  ■■■■  ■  ■  ■");
    go(row, col + 3);   printf("■  ■    ■    ■  ■    ■  ■        ■    ■  ■    ■■");
    go(row, col + 4);   printf("■    ■    ■■    ■    ■  ■■■■  ■    ■  ■      ■");    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
}

void Play(int option) {
    if (option == -1)
        return;
    system("cls");
    int row = 0, col = 0, baserow = 15, basecol = 10;
    switch (option)
    default: row = baserow + option * 10, col = basecol + option * 5;
    MazeGenerator(row, col);
    // ShowStartNEnd(row, col);
    MazeRunner(row, col);
}

void MazeGenerator(int row, int col) {
    srand((unsigned int)time(NULL)); // 난수 생성을 위한 시드 설정

    // 미로의 가로와 세로 칸 수와 벽을 포함한 전체 미로 배열 동적 할당
    maze = (int*)malloc(sizeof(int) * (row * 2 + 1) * (col * 2 + 1));
    for (int i = 0; i < col * 2 + 1; i++)	            // 모든 행을 순회
        for (int j = 0; j < row * 2 + 1; j++)	        // 해당 행 내의 모든 열 요소를 순회
            if (i % 2 == 0 || j % 2 == 0)		        // 미로가 연결되지 않았으므로 미로 공간을 제외한 모든 배열 칸
                *(maze + (row * 2 + 1) * i + j) = 1;	// 벽이 있다고 표시하기
            else								        // 미로 공간에 해당하는 칸에 대해
                *(maze + (row * 2 + 1) * i + j) = 0;	// 벽이 없다고 표시하기
    *(maze + row * 2 + 1) = 0;							// 입구 배치
    *(maze + row * 2 + 1 + row * 2) = 0;				// 출구 배치

    int lastgroupwidth = 1;						        // 인접한 그룹을 랜덤하게 연결할 때 사용하는 변수

    for (int i = 0; i < col; i++)			            // 모든 행을 순회
        for (int j = 0; j < row; j++)			        // 해당 행 내의 모든 열 요소를 순회
            if (i != col - 1 && j != row - 1)	        // 가장 아래 행과 가장 오른쪽 열이 아닌 경우
                if (rand() % 2) {					    // 1/2 확률로 그룹을 확장
                    *(maze + (row * 2 + 1) * (i * 2 + 1) + (j + 1) * 2) = 0;	// 해당 칸의 오른쪽 벽 제거
                    lastgroupwidth++;					// 그룹이 확장되었으므로 해당 행에서 직전에 확장된 그룹의 길이를 저장
                }
                else {								    // 그룹이 확장되지 않은 경우
                    int rnum = rand() % lastgroupwidth;	// 해당 그룹 내 열 요소를 하나만 골라서
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + (j - lastgroupwidth + 1 + rnum) * 2 + 1) = 0; // 아래쪽 벽을 제거
                    lastgroupwidth = 1;					// 그룹 길이를 나타내는 변수 재설정
                }
            else if (i != col - 1 && j == row - 1)	    // 가장 아래 행을 제외한 나머지 행의 가장 오른쪽 열 요소에 대해
                if (lastgroupwidth == 1)				// 마지막 열 요소가 이전 그룹과 별개의 그룹일 경우
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + j * 2 + 1) = 0;	// 아래 방향으로 벽 제거
                else {									// 마지막 열 요소가 이전 그룹과 동일한 그룹에 속한 경우
                    int rnum = rand() % lastgroupwidth;	// 해당 그룹 내 열 요소를 하나만 골라서
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + (j - lastgroupwidth + 1 + rnum) * 2 + 1) = 0;	// 아래쪽 벽을 제거
                    lastgroupwidth = 1;					// 그룹 길이를 나타내는 변수 재설정
                }
            else if (j != row - 1)					    // 마지막 열에서 마지막 행 요소를 제외한 모든 열 요소에 대해
                *(maze + (row * 2 + 1) * (i * 2 + 1) + (j + 1) * 2) = 0;	// 해당 요소의 오른쪽 벽 제거 (마지막 행의 미로 내 모든 벽 제거)
    int printrow = 120, printcol = 34 - col;
    go(printrow - row * 2 - 1, printcol++);
    for (int i = 0; i < col * 2 + 1; i++) {			    // 전체 미로 배열의 각 행에 대해
        for (int j = 0; j < row * 2 + 1; j++)			// 해당 행의 각 열 요소를 순회하며
            if (*(maze + (row * 2 + 1) * i + j) == 1)   // 1인 경우
                printf("■");                            // 네모 출력
            else                                        // 0인 경우
                printf("  ");	                        // 빈칸 출력
        go(printrow - row * 2 - 1, printcol++);
    }
}

void ShowStartNEnd(int row, int col) {
    int printrow = 120, printcol = 34 - col;
    for (int i = 0; i < 3; i++) {
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("Start →");
        go(printrow + row * 2 + 1, printcol + 1); printf("← End");
        if (i != 2)
            Sleep(500);
        else
            Sleep(3000);
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("        ");
        go(printrow + row * 2 + 1, printcol + 1); printf("      ");
        Sleep(500);
    }
}

void MazeRunner(int row, int col) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    int maze_x = 120 - row * 2 - 1, maze_y = 35 - col;
    int x = 0, y = 0, direction = 0;
    int pause = 0;
    go(maze_x, maze_y); printf("▶");
    char key;
    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ESC) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                int printrow = 120, printcol = 35 - col;
                if (pause == 0) {
                    go(maze_x + x, maze_y + y);
                    printf("  ");
                    go(printrow - row * 2 + 1, printcol++);
                    for (int i = 1; i < col * 2; i++) {
                        for (int j = 1; j < row * 2; j++)
                            printf("  ");
                        go(printrow - row * 2 + 1, printcol++);
                    }
                    pause++;
                }   
                else {
                    go(maze_x + x, maze_y + y);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
                    switch (direction) {
                    case 0:
                        printf("▶");
                        break;
                    case 1:
                        printf("▲");
                        break;
                    case 2:
                        printf("◀");
                        break;
                    case 3:
                        printf("▼");
                        break;
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                    go(printrow - row * 2 + 1, printcol++);
                    for (int i = 1; i < col * 2; i++) {
                        for (int j = 1; j < row * 2; j++)
                            if (*(maze + (row * 2 + 1) * i + j) == 1)
                                printf("■");
                            else
                                printf("  ");
                        go(printrow - row * 2 + 1, printcol++);
                    }
                    pause--;
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
                continue;
            }
            else if (key == -32) {
                key = _getch();
                switch (key) {
                case UP:
                    // 위로 이동 (벽이면 제자리)       캐릭터 자리에 ▲ 출력
                    break;
                case DOWN:
                    // 아래로 이동 (벽이면 제자리)     캐릭터 자리에 ▼ 출력
                    break;
                case LEFT:
                    // 아래로 이동 (벽이면 제자리)     캐릭터 자리에 ◀ 출력
                    break;
                case RIGHT:
                    // 아래로 이동 (벽이면 제자리)     캐릭터 자리에 ▶ 출력
                    break;
                }
            }
        }
    }
}