#include "MazeRunner.h"

extern int* maze;

void Play(int option) {
    if (option == -1)
        return;
    system("cls");
    int row = 0, col = 0, baserow = 15, basecol = 10;
    switch (option)
    default: row = baserow + option * 10, col = basecol + option * 5;
    MazeGenerator(row, col);
    ShowStartNEnd(row, col);
    MazeRunner(row, col);
}

void ShowStartNEnd(int row, int col) {
    int printrow = 120, printcol = 34 - col;
    for (int i = 0; i < 3; i++) {
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("Start бц");
        go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("бч End");
        if (i != 2)
            Sleep(500);
        else
            Sleep(3000);
        go(printrow - row * 2 - 1 - 8, printcol + 1); printf("        ");
        go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("      ");
        Sleep(500);
    }
}

void MazeRunner(int row, int col) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    int maze_x = 120 - row * 2 - 1, maze_y = 34 - col;
    int goal_x = 120 + row * 2 - 1, goal_y = 34 + col - 1;
    int x = 0, y = 1, direction = RIGHT;
    *(maze + row * 2 + 2) = 1;
    go(maze_x + x * 2, maze_y + y); printf("в║");
    char key;
    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ESC) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                int printrow = 120, printcol = 35 - col;
                go(maze_x + x * 2, maze_y + y);
                printf("  ");
                go(printrow - row * 2 + 1, printcol++);
                for (int i = 1; i < col * 2; i++) {
                    for (int j = 1; j < row * 2; j++)
                        printf("  ");
                    go(printrow - row * 2 + 1, printcol++);
                }
                printrow = 96, printcol = 33 - col / 2;
                go(printrow, printcol++); printf("бсбсбс      бсбс    бс    бс  бсбсбсбс  бсбсбсбс");
                go(printrow, printcol++); printf("бс    бс  бс    бс  бс    бс  бс        бс");
                go(printrow, printcol++); printf("бсбсбс    бсбсбсбс  бс    бс  бсбсбсбс  бсбсбсбс");
                go(printrow, printcol++); printf("бс        бс    бс  бс    бс        бс  бс");
                go(printrow, printcol);   printf("бс        бс    бс    бсбс    бсбсбсбс  бсбсбсбс");
                while (1) {
                    key = _getch();
                    if (key == ESC) {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                        printrow = 120, printcol = 35 - col;
                        go(printrow - row * 2 + 1, printcol++);
                        for (int i = 1; i < col * 2; i++) {
                            for (int j = 1; j < row * 2; j++)
                                if (*(maze + (row * 2 + 1) * i + j) == 1)
                                    printf("бс");
                                else
                                    printf("  ");
                            go(printrow - row * 2 + 1, printcol++);
                        }
                        go(maze_x + x * 2, maze_y + y);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
                        switch (direction) {
                        case UP:
                            printf("бу");
                            break;
                        case DOWN:
                            printf("бх");
                            break;
                        case LEFT:
                            printf("в╕");
                            break;
                        case RIGHT:
                            printf("в║");
                            break;
                        }
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
                    if (*(maze + x + y * (row * 2 + 1)) == 1) y++;
                    break;
                case DOWN:
                    direction = DOWN;
                    y++;
                    if (*(maze + x + y * (row * 2 + 1)) == 1) y--;
                    break;
                case LEFT:
                    direction = LEFT;
                    x--;
                    if (*(maze + x + y * (row * 2 + 1)) == 1) x++;
                    break;
                case RIGHT:
                    direction = RIGHT;
                    x++;
                    if (*(maze + x + y * (row * 2 + 1)) == 1) x--;
                    break;
                }
                go(maze_x + x * 2, maze_y + y);
                switch (direction) {
                case UP:
                    printf("бу");
                    break;
                case DOWN:
                    printf("бх");
                    break;
                case LEFT:
                    printf("в╕");
                    break;
                case RIGHT:
                    printf("в║");
                    break;
                }
                if (maze_x + x * 2 == goal_x && maze_y + y == goal_y) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                    return;
                }
            }
        }
    }
}