#include "MazeRunner.h"

extern int* field;

int Play(int option) {
    if (option == -1)
        return 0;
    system("cls");
    int baserow = 15, basecol = 10;
    int row = baserow + option * 10, col = basecol + option * 5;
    MazeGenerator(row, col);
    ShowStartNEnd(row, col);
    return MazeRunner(row, col);
}

void ShowStartNEnd(int row, int col) {
    ShowMaze(row, col, -1);

    int printrow = 120, printcol = 34 - col;
    go(printrow - row * 2 - 1 - 8, printcol + 1); printf("Start ¡æ");
    go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("¡ç End");

    DrawString(CENTERROW - 40, CENTERCOL - 3, "PRESS\nENTER");

    char key;
    while ((key = _getch()) != ENTER);

    go(printrow - row * 2 - 1 - 8, printcol + 1); printf("        ");
    go(printrow + row * 2 + 1, printcol + col * 2 - 1); printf("      ");

    ShowMaze(row, col, 0);
    Sleep(100);    
    ShowMaze(row, col, 1);
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
                go(maze_x + x * 2, maze_y + y); printf("  ");
                ShowMaze(row, col, 0);   
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 3 << 4);
                DrawString(CENTERROW - 40, CENTERCOL - 2, "PAUSE");
                go(CENTERROW - 23, CENTERCOL + 6); printf("ESC :: RESUME"); 
                go(CENTERROW - 23, CENTERCOL + 8); printf("ENTER :: EXIT");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                int select = 0;
                while (1) {
                    key = _getch();
                    if (key == ENTER) {
                        free(field);
                        return 1;
                    }                        
                    else if (key == ESC) {
                        ShowMaze(row, col, 1);
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
                    for (int i = 0; i < 9; i++) {
                        go(CENTERROW - 95, CENTERCOL - 2 + i);
                        printf("                                                                                                                                                              ");
                    }
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 3 << 4);
                    DrawString(CENTERROW - 91, CENTERCOL, "CONGRATULATIONS!");
                    for (int i = 0; i < 4; i++) {
                        go(CENTERROW - 29, CENTERCOL + 7 + i);
                        printf("                         ");
                    }
                    go(CENTERROW - 27, CENTERCOL + 8); printf("     ENTER TO EXIT     ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                    while ((key = _getch()) != ENTER);
                    free(field);
                    return 1;
                }
            }
        }
    }
}

void ShowMaze(int row, int col, int option) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
    int printrow = 120, printcol = 35 - col;
    if (option != -1) {
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
    else {
        go(printrow - row * 2 - 1, printcol - 1);
        for (int i = 0; i < col * 2 + 1; i++) {
            if (i == 0 || i == col * 2)
                for (int j = 0; j < row * 2 + 1; j++)
                    printf("¡á");
            else {
                if (i != 1)
                    printf("¡á");
                go(printrow + row * 2 - 1, printcol - 1);
                if (i != col * 2 - 1)
                    printf("¡á");
            }
            go(printrow - row * 2 - 1, printcol++);
        }
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