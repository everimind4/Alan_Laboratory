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

    DrawString(CENTERROW - 20, CENTERCOL - 3, "PRESS\nENTER");

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

    clock_t start = clock();

    while (1) {
        if (_kbhit()) {
            key = _getch();
            if (key == ESC) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
                go(maze_x + x * 2, maze_y + y); printf("  ");
                ShowMaze(row, col, 0);   
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 3 << 4);
                DrawString(CENTERROW - 20, CENTERCOL - 2, "PAUSE");
                go(CENTERROW - 3, CENTERCOL + 6); printf("ESC :: RESUME"); 
                go(CENTERROW - 3, CENTERCOL + 8); printf("ENTER :: EXIT");
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
                    clock_t end = clock();
                    for (int i = 0; i < 9; i++) {
                        go(CENTERROW - 75, CENTERCOL - 2 + i);
                        printf("                                                                                                                                                              ");
                    }
                    Score(end - start);
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

void Score(clock_t time) {
    int row = CENTERROW - 52, col = CENTERCOL - 5;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15 | 3 << 4);
    DrawString(row - 19, col + 5, "CONGRATULATIONS!"); Sleep(1500);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
    ClearConsole(); Sleep(500);
    DrawString(row + 27, col - 15, "Records"); Sleep(1000);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10 | 3 << 4);

    if (time >= 6000000) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
        DrawString(row + 20, col, "Time out!");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
    }
    else {
        if (time >= 60000) {
            if (time / 60000 > 9)
                DrawNumber(row, col, time / 600000 % 10);
            row += 28;
            DrawNumber(row, col, time / 60000 % 10);
            row += 5;
            DrawChar(row, col + 11, 'M');
            row += 42;
            DrawNumber(row, col, time % 60000 / 10000 % 10);
            row += 28;
            DrawNumber(row, col, time / 1000 % 10);
            row += 5;
            DrawChar(row, col + 11, 'S');
        }
        else {
            row += 28;
            if (time / 1000 > 9)
                DrawNumber(row, col, time / 10000 % 10);
            row += 28;
            DrawNumber(row, col, time / 1000 % 10);
            go(row + 2, col + 14); printf("¡á¡á");
            go(row + 1, col + 15); printf("¡á¡á");
            row += 36;
            DrawNumber(row, col, time / 100 % 10);
            row += 5;
            DrawChar(row, col + 11, 'S');
            row -= 39;       
        }
    }

    Sleep(1000);
    
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
    DrawString(CENTERROW - 45, CENTERCOL + 23, "PRESS   ENTER");
}
