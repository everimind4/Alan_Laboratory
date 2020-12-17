#include "MazeRunner.h"

int* maze;

void MazeGenerator(int row, int col) {
    srand((unsigned int)time(NULL)); // ���� ������ ���� �õ� ����

    // �̷��� ���ο� ���� ĭ ���� ���� ������ ��ü �̷� �迭 ���� �Ҵ�
    maze = (int*)malloc(sizeof(int) * (row * 2 + 1) * (col * 2 + 1));
    for (int i = 0; i < col * 2 + 1; i++)	            // ��� ���� ��ȸ
        for (int j = 0; j < row * 2 + 1; j++)	        // �ش� �� ���� ��� �� ��Ҹ� ��ȸ
            if (i % 2 == 0 || j % 2 == 0)		        // �̷ΰ� ������� �ʾ����Ƿ� �̷� ������ ������ ��� �迭 ĭ
                *(maze + (row * 2 + 1) * i + j) = 1;	// ���� �ִٰ� ǥ���ϱ�
            else								        // �̷� ������ �ش��ϴ� ĭ�� ����
                *(maze + (row * 2 + 1) * i + j) = 0;	// ���� ���ٰ� ǥ���ϱ�

    int lastgroupwidth = 1;						        // ������ �׷��� �����ϰ� ������ �� ����ϴ� ����

    for (int i = 0; i < col; i++)			            // ��� ���� ��ȸ
        for (int j = 0; j < row; j++)			        // �ش� �� ���� ��� �� ��Ҹ� ��ȸ
            if (i != col - 1 && j != row - 1)	        // ���� �Ʒ� ��� ���� ������ ���� �ƴ� ���
                if (rand() % 2) {					    // 1/2 Ȯ���� �׷��� Ȯ��
                    *(maze + (row * 2 + 1) * (i * 2 + 1) + (j + 1) * 2) = 0;	// �ش� ĭ�� ������ �� ����
                    lastgroupwidth++;					// �׷��� Ȯ��Ǿ����Ƿ� �ش� �࿡�� ������ Ȯ��� �׷��� ���̸� ����
                }
                else {								    // �׷��� Ȯ����� ���� ���
                    int rnum = rand() % lastgroupwidth;	// �ش� �׷� �� �� ��Ҹ� �ϳ��� ���
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + (j - lastgroupwidth + 1 + rnum) * 2 + 1) = 0; // �Ʒ��� ���� ����
                    lastgroupwidth = 1;					// �׷� ���̸� ��Ÿ���� ���� �缳��
                }
            else if (i != col - 1 && j == row - 1)	    // ���� �Ʒ� ���� ������ ������ ���� ���� ������ �� ��ҿ� ����
                if (lastgroupwidth == 1)				// ������ �� ��Ұ� ���� �׷�� ������ �׷��� ���
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + j * 2 + 1) = 0;	// �Ʒ� �������� �� ����
                else {									// ������ �� ��Ұ� ���� �׷�� ������ �׷쿡 ���� ���
                    int rnum = rand() % lastgroupwidth;	// �ش� �׷� �� �� ��Ҹ� �ϳ��� ���
                    *(maze + (row * 2 + 1) * (i + 1) * 2 + (j - lastgroupwidth + 1 + rnum) * 2 + 1) = 0;	// �Ʒ��� ���� ����
                    lastgroupwidth = 1;					// �׷� ���̸� ��Ÿ���� ���� �缳��
                }
            else if (j != row - 1)					    // ������ ������ ������ �� ��Ҹ� ������ ��� �� ��ҿ� ����
                *(maze + (row * 2 + 1) * (i * 2 + 1) + (j + 1) * 2) = 0;	// �ش� ����� ������ �� ���� (������ ���� �̷� �� ��� �� ����)

    int temp;
    for (int i = 0; i < col; i++)
        for (int j = row; j < row * 2 + 1; j++) {
            temp = *(maze + (row * 2 + 1) * i + j);
            *(maze + (row * 2 + 1) * i + j) = *(maze + (row * 2 + 1) * (col * 2 - i) + j);
            *(maze + (row * 2 + 1) * (col * 2 - i) + j) = temp;
        }

    *(maze + row * 2 + 1) = 0;							    // �Ա� ��ġ
    *(maze + (row * 2 + 1) * (col * 2 - 1) + row * 2) = 0;	// �ⱸ ��ġ

    int printrow = 120, printcol = 34 - col;
    go(printrow - row * 2 - 1, printcol++);
    for (int i = 0; i < col * 2 + 1; i++) {			    // ��ü �̷� �迭�� �� �࿡ ����
        for (int j = 0; j < row * 2 + 1; j++)			// �ش� ���� �� �� ��Ҹ� ��ȸ�ϸ�
            if (*(maze + (row * 2 + 1) * i + j) == 1)   // 1�� ���
                printf("��");                            // �׸� ���
            else                                        // 0�� ���
                printf("  ");	                        // ��ĭ ���
        go(printrow - row * 2 - 1, printcol++);
    }
}