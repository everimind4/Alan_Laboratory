#include "MazeRunner.h"

int* maze;

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

    int temp;
    for (int i = 0; i < col; i++)
        for (int j = row; j < row * 2 + 1; j++) {
            temp = *(maze + (row * 2 + 1) * i + j);
            *(maze + (row * 2 + 1) * i + j) = *(maze + (row * 2 + 1) * (col * 2 - i) + j);
            *(maze + (row * 2 + 1) * (col * 2 - i) + j) = temp;
        }

    *(maze + row * 2 + 1) = 0;							    // 입구 배치
    *(maze + (row * 2 + 1) * (col * 2 - 1) + row * 2) = 0;	// 출구 배치

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