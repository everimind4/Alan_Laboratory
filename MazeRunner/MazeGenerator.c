#include "MazeRunner.h"

int* field;
int WIDTH, HEIGHT;
void SetRight(int, int, int);
void SetDown(int, int, int);
int GetDown(int, int);

void MazeGenerator(int row, int col) {
    srand((unsigned int)time(NULL)); // 난수 생성을 위한 시드 설정
    WIDTH = row, HEIGHT = col;

    char* maze = (char*)malloc(sizeof(char) * WIDTH);
    if (maze == NULL) return;
    for (int i = 0; i < WIDTH; i++)
        maze[i] = 0;

    field = (int*)malloc(sizeof(int) * (HEIGHT * 2 + 1) * (WIDTH * 2 + 1)); // 전체 미로 공간 저장
    if (field == NULL) return;

    for (int i = 0; i < HEIGHT * 2 + 1; i++)
        for (int j = 0; j < WIDTH * 2 + 1; j++)
            if (i % 2 == 0 || j == 0 || j == WIDTH * 2)
                *(field + i * (WIDTH * 2 + 1) + j) = 1;
            else
                *(field + i * (WIDTH * 2 + 1) + j) = 0;

    int set = 0;
    int lastsetwidth = 1;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            if (maze[j] == 0)
                maze[j] = ++set;
        if (i != HEIGHT - 1) {
            for (int j = 0; j < WIDTH - 1; j++)
                if (maze[j + 1] == maze[j])
                    SetRight(i, j, 1);
            for (int j = 0; j < WIDTH - 1; j++)
                if (rand() % 2)
                    SetRight(i, j, 1);
                else
                    maze[j + 1] = maze[j];
            for (int j = 0; j < WIDTH; j++)
                if (j != WIDTH - 1) {
                    if (maze[j + 1] == maze[j]) {
                        lastsetwidth++;
                        if (rand() % 2)
                            SetDown(i, j, 0);
                    }
                    else {
                        SetDown(i, j + 1 - lastsetwidth + rand() % lastsetwidth, 0);
                        lastsetwidth = 1;
                    }
                }
                else {
                    if (maze[j] != maze[j - 1])
                        SetDown(i, j, 0);
                    else {
                        SetDown(i, j + 1 - lastsetwidth + rand() % lastsetwidth, 0);
                        lastsetwidth = 1;
                    }
                }
            for (int j = 0; j < WIDTH; j++)
                if (GetDown(i, j) == 1)
                    maze[j] = 0;
        }
        else
            for (int j = 0; j < WIDTH - 1; j++)
                if (maze[j + 1] == maze[j])
                    SetRight(i, j, 1);
    }

    free(maze);

    *(field + row * 2 + 1) = 0;							    // 입구 배치
    *(field + (row * 2 + 1) * (col * 2 - 1) + row * 2) = 0;	// 출구 배치    
}

void SetRight(int row, int col, int option) {
    *(field + (row * 2 + 1) * (WIDTH * 2 + 1) + (col + 1) * 2) = option;
}

void SetDown(int row, int col, int option) {
    *(field + (row + 1) * 2 * (WIDTH * 2 + 1) + col * 2 + 1) = option;
}

int GetDown(int row, int col) {
    return *(field + (row + 1) * 2 * (WIDTH * 2 + 1) + col * 2 + 1);
}