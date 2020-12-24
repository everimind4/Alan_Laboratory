#include "MazeRunner.h"

void DrawTitle() {
    int row = CENTERROW - 56, col = CENTERCOL - 20;
    go(row, col++);  printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
    go(row, col);    printf("¡á"); go(row + 122, col++); printf("¡á");
    go(row, col);    printf("¡á"); go(row + 122, col++); printf("¡á");

    go(row, col);    printf("¡á"); go(row + 12, col++);  printf("¡á¡á¡á¡á  ¡á  ¡á      ¡á¡á¡á    ¡á    ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á¡á¡á    ¡á    ¡á        ¡á ¡á¡á¡á¡á¡á¡á¡á¡á   ¡á");
    go(row, col);    printf("¡á"); go(row + 11, col++);  printf("¡á    ¡á  ¡á  ¡á    ¡á      ¡á  ¡á          ¡á                    ¡á    ¡á    ¡á        ¡á                     ¡á");
    go(row, col);    printf("¡á"); go(row + 10, col++);  printf("¡á    ¡á  ¡á  ¡á    ¡á      ¡á  ¡á        ¡á  ¡á                  ¡á    ¡á    ¡á        ¡á ¡á¡á¡á¡á¡á¡á¡á       ¡á");
    go(row, col);    printf("¡á"); go(row + 9, col++);   printf("¡á    ¡á¡á¡á  ¡á    ¡á      ¡á  ¡á      ¡á      ¡á          ¡á¡á¡á¡á  ¡á¡á    ¡á    ¡á¡á¡á                       ¡á");
    go(row, col);    printf("¡á"); go(row + 8, col++);   printf("¡á    ¡á  ¡á  ¡á    ¡á      ¡á  ¡á    ¡á          ¡á        ¡á          ¡á    ¡á        ¡á ¡á¡á¡á¡á¡á¡á           ¡á");
    go(row, col);    printf("¡á"); go(row + 7, col++);   printf("¡á    ¡á  ¡á  ¡á    ¡á      ¡á  ¡á                          ¡á          ¡á    ¡á        ¡á                         ¡á");
    go(row, col);    printf("¡á"); go(row + 6, col++);   printf("¡á¡á¡á¡á  ¡á  ¡á      ¡á¡á¡á    ¡á    ¡á¡á¡á¡á¡á¡á¡á        ¡á¡á¡á¡á    ¡á    ¡á¡á¡á¡á  ¡á ¡á¡á¡á¡á¡á               ¡á");

    go(row, col);    printf("¡á"); go(row + 122, col++); printf("¡á");
    go(row, col);    printf("¡á"); go(row + 122, col++); printf("¡á");
    go(row, col);    printf("¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
}

void DrawMenu() {
    int row = MENUINITROW, col = MENUINITCOL;
    col += MENUCOLDIST;
    DrawString(row, col, "START");
    row += 6; col += MENUCOLDIST;
    DrawString(row, col, "EXIT");
}

void PrintVersion() {
    go(CENTERROW + 56, CENTERCOL - 11); printf("v1.0.1");
}

void PrintCopyright() {
    go(CENTERROW - 18, CENTERCOL + 32); printf("Copyright 2020 Youngin Choi. All right reserved.");
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
                    return level;
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
            go(row,     MENUINITCOL + i * MENUCOLDIST);     printf("¡¡");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 1); printf("¡¡");
            go(row + 4, MENUINITCOL + i * MENUCOLDIST + 2); printf("¡¡");
            go(row + 2, MENUINITCOL + i * MENUCOLDIST + 3); printf("¡¡");
            go(row,     MENUINITCOL + i * MENUCOLDIST + 4); printf("¡¡");
        }
        else
        {
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST);       printf("¡¡");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1);   printf("¡¡");
            go(row     - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 2);   printf("¡¡");
            go(row + 2 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3);   printf("¡¡");
            go(row + 4 - levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 4);   printf("¡¡");
            row += levelarrowdist;
            go(row     + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST);       printf("¡¡");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 1);   printf("¡¡");
            go(row + 4 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 2);   printf("¡¡");
            go(row + 2 + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 3);   printf("¡¡");
            go(row     + levelarrowwidth, MENUINITCOL + i * MENUCOLDIST + 4);   printf("¡¡");
            row -= levelarrowdist;
        }
    }
    if (menu != 0) {
        go(row, col);           printf("¡á");
        go(row + 2, col + 1);   printf("¡á");
        go(row + 4, col + 2);   printf("¡á");
        go(row + 2, col + 3);   printf("¡á");
        go(row, col + 4);       printf("¡á");
    }
    else {
        go(row + 4 - levelarrowwidth, col);       printf("¡á");
        go(row + 2 - levelarrowwidth, col + 1);   printf("¡á");
        go(row     - levelarrowwidth, col + 2);   printf("¡á");
        go(row + 2 - levelarrowwidth, col + 3);   printf("¡á");
        go(row + 4 - levelarrowwidth, col + 4);   printf("¡á");
        row += levelarrowdist;
        go(row     + levelarrowwidth, col);       printf("¡á");
        go(row + 2 + levelarrowwidth, col + 1);   printf("¡á");
        go(row + 4 + levelarrowwidth, col + 2);   printf("¡á");
        go(row + 2 + levelarrowwidth, col + 3);   printf("¡á");
        go(row     + levelarrowwidth, col + 4);   printf("¡á");
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
    DrawString(row, col, "NEWBIE");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
}

void EASY(int row, int col) {
    row += 3;
    DrawString(row, col, "EASY");
}

void NORMAL(int row, int col) {
    row -= 8;
    DrawString(row, col, "NORMAL");
}

void HARD(int row, int col) {
    row += 3;
    DrawString(row, col, "HARD");
}

void KOREAN(int row, int col) {
    row -= 8;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4 | 3 << 4);
    DrawString(row, col, "KOREAN");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14 | 3 << 4);
}