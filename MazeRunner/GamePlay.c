#include "MazeRunner.h"

extern int* field;

int Play(int option) {
    if (option == -1)
        return 0;
    system("cls");
    int baserow = 15, basecol = 10;
    int row = baserow + option * 10, col = basecol + option * 5;
    MazeGenerator(row, col);
    // ShowStartNEnd(row, col);
    return MazeRunner(row, col);
}

void ShowStartNEnd(int row, int col) {
    int printrow = 120, printcol = 34 - col;
    for (int i = 0; i < 3; i++) {
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("Start ¡æ");
        go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("¡ç End");
        if (i != 2)
            Sleep(500);
        else
            Sleep(1500);
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("        ");
        go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("      ");
        Sleep(500);
    }
    int key;
    while (1)
        if (_kbhit()) {
            key = _getch();
            if (key == ENTER)
                break;
        }
}

int MazeRunner(int row, int col) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    int maze_x = 120 - row * 2 - 1, maze_y = 34 - col;
    int goal_x = 120 + row * 2 - 1, goal_y = 34 + col - 1;
    int x = 0, y = 1, direction = RIGHT;

    Arrow(maze_x + x * 2, maze_y + y, direction);
    char key;

    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ESC) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                int printrow = 120, printcol = 35 - col;
                ShowMaze(printrow, printcol, row, col, 0);
                go(maze_x + x * 2, maze_y + y);
                printf("  ");
                printrow = CENTERROW - 20, printcol = CENTERCOL;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 3 << 4);
                DrawString(printrow, printcol, "PAUSE");
                go(CENTERROW - 8, CENTERCOL + 2); printf("");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                int select = 0;
                while (1) {
                    key = _getch();
                    if (key == ENTER) {
                        free(field);
                        return 1;
                    }                        
                    else if (key == ESC) {
                        printrow = 120, printcol = 35 - col;
                        ShowMaze(printrow, printcol, row, col, 1);
                        Arrow(maze_x + x * 2, maze_y + y, direction);
                        break;
                    }
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
                continue;
            }
            else if (key == -32) {
                go(maze_x + x * 2, maze_y + y);
                printf("  ");
                key = _getch();
                switch (key) {
                case UP:
                    direction = UP;
                    y--;
                    if (*(field + x + y * (row * 2 + 1)) == 1) y++;
                    break;
                case DOWN:
                    direction = DOWN;
                    y++;
                    if (*(field + x + y * (row * 2 + 1)) == 1) y--;
                    break;
                case LEFT:
                    direction = LEFT;
                    x--;
                    if (*(field + x + y * (row * 2 + 1)) == 1) x++;
                    break;
                case RIGHT:
                    direction = RIGHT;
                    x++;
                    if (*(field + x + y * (row * 2 + 1)) == 1) x--;
                    break;
                }
                Arrow(maze_x + x * 2, maze_y + y, direction);
                if (maze_x + x * 2 == goal_x && maze_y + y == goal_y) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                    free(field);
                    return 0;
                }
            }
        }
    }
}

void ShowMaze(int printrow, int printcol, int row, int col, int option) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
    go(printrow - row * 2 + 1, printcol++);
    for (int i = 1; i < col * 2; i++) {
        for (int j = 1; j < row * 2; j++)
            if (option == 0)
                printf("  ");
            else if (*(field + (row * 2 + 1) * i + j) == 1)
                printf("¡á");
            else
                printf("  ");
        go(printrow - row * 2 + 1, printcol++);
    }
}

void Arrow(int row, int col, int direction) {
    go(row, col);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    switch (direction) {
    case UP:
        printf("¡ã");
        break;
    case DOWN:
        printf("¡å");
        break;
    case LEFT:
        printf("¢¸");
        break;
    case RIGHT:
        printf("¢º");
        break;
    }
}