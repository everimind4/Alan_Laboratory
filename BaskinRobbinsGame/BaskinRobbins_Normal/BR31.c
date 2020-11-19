#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Player(int*);		// ���� �� �÷��̾��� ���ʸ� �����ϴ� �Լ�
void Computer(int*);	// ���� �� ��ǻ���� ���ʸ� �����ϴ� �Լ�

void main() {
	int recent = 0;
	for (;;) {
		Player(&recent);
		if (recent >= 31) {
			printf("I win.\n\n");
			break;
		}
		Computer(&recent);
		if (recent >= 31) {
			printf("You win.\n\n");
			break;
		}
	}
	system("pause");
}

void Player(int* recent) {
	int count = 0;			// ����ڰ� �� ���� ���ڸ� �Է��ߴ��� ���� ���� ����
	int check;				// ����ڰ� �ùٸ��� �Է��ߴ��� �˻��ϱ� ���� ����
	char input[100];		// ����ڰ� �Է��ϴ� ���� ���� ���ڸ� '���⸦ ������ ���ڿ���' �����ϱ� ���� ����
	char numstring[3][3];	// �� input ������ ���⸦ �������� �����Ͽ� �����ϱ� ���� ���ڿ� �迭
	int nums[3];			// ����� ���е� ���ڿ��� ���ڷ� ��ȯ�� �����ϴ� ���� �迭
	for (;;) {				// �ùٸ��� �Էµ� �� ���� ���ѷ��� ����
		for (int i = 0; i < 3; i++)				// ���ڿ� �迭�� �� ��Ҹ� Null character�� ����� �ش�.
			numstring[i][0] = '\0';
		printf("You : ");
		check = scanf("%[^\n]", input);			// %[^\n] ������ ����� ���⸦ ������ ���ڿ��� �Է¹޴´�.
		getchar();								// �Է� ���ڿ� �� ������ ���� ���ڸ� �Է� ���ۿ��� ����
		if (check == 0 || strlen(input) == 0) { // scanf()�Լ����� �Է¹��� ���� ���ų�, ��� ������ input�� ���̰� 0�� ��� �ٽ� �Է¹޴´�.
			printf("\nNothing was entered. Try again.\n\n");
			continue;
		}
		int idx = 0; // input ���ڿ��� �߶� numstring�� �Է��� �� ����ϴ� �ε��� ����
		for (int i = 0; i < (signed int)strlen(input) + 1; i++) { // input ���ڿ����� �ϳ��� �о�鿩�� numstring �迭 ��ҿ� ���� (count : ��, idx : column)
			if (input[i] == ' ' || input[i] == '\0') { // input ���ڿ��� ���Ⱑ �ְų� ���ڿ��� ������ ��� numstring�� ����� ���ڿ� �� �ڿ� null���� �Է�
				numstring[count][idx] = '\0';
				count++;
				idx = 0;
				continue;
			}
			if (count == 3 && input[i] != '\0') { // ���ڸ� 3������ ���� �Է����� ��� �ٽ� �Է�
				printf("\nYou've entered too many numbers. Please enter again.\n\n");
				count = 0;	// count�� 0���� �ʱ�ȭ
				check = -1;	// scanf �Է� �˻翡 ����ߴ� ������ check�� ���� - ���ڸ� 3������ ���� �Էµ� ��쿡 ���� ����
				break;
			}
			numstring[count][idx++] = input[i]; // input ���ڿ����� �ϳ��� �о�鿩�� numstring �迭 ��ҿ� ���� (count : ��, idx : column)
		}
		if (check == -1)	// scanf �Է� �˻翡 ����ߴ� ������ check�� ���� - ���ڸ� 3������ ���� �Էµ� ��쿡 ���� ����
			continue;
		count = 0; // ���� ������ �������� count ������ ����Ǵ� ���� �����ǹǷ� ������ nums �迭�� ���ڸ� �����ϸ� ����Ǵ� ������ count ������ �����ϱ� ���� 0���� �ʱ�ȭ
		for (int i = 0; i < 3; i++)
			if (strlen(numstring[i]) > 0)
			{
				nums[i] = atoi(numstring[i]);	// numstring�� ����� ���� ���ڿ��� ������ ��ȯ�� nums�� ����
				count++;						// ������ �� �Էµ� ���� 1 ����
			}
			else
				nums[i] = 0; // 
		switch (count) { // count�� ����� ��(������ �Էµ� ���� ����)�� �������� �Էµ� ������ ������ �˻�
		case 3:
			if (nums[2] - 1 != nums[1]) {	// 3��° ���� - 1 = 2��° �������� �˻�
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count�� 0���� �ʱ�ȭ
				continue;					// ���� �ٸ� ��� �ٽ� �Է�
			}								// switch���� break�� ������ ���� case�� �Ѿ - ���� ���ڸ� ��� �˻��ϱ� ���� break�� �Է����� ����
		case 2:
			if (nums[1] - 1 != nums[0]) {	// 2��° ���� - 1 = 1��° �������� �˻�
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count�� 0���� �ʱ�ȭ
				continue;					// ���� �ٸ� ��� �ٽ� �Է�
			}
		case 1:
			if (nums[0] - 1 != *recent) {	// 1��° ���� - 1 = ���� �������� �˻�
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count�� 0���� �ʱ�ȭ
				continue;					// ���� �ٸ� ��� �ٽ� �Է�
			}
		default: {							// ��� ���ڰ� ����� �Էµ� ���
			printf("\n");
			*recent += count;				// �Էµ� ���� ������ŭ ���� ���ڸ� ������Ų��.
			return;
		}
		}
	}
}

void Computer(int* recent) {
	srand((unsigned int)time(NULL));
	printf("COM : ");
	char text[9];	// ��ǻ�Ͱ� ����� ���ڸ� ���ڿ��� ������ ����
	if (*recent <= 26) {
		switch (rand() % 3 + 1) {
		case 1: sprintf(text, "%d %d %d", *recent + 1, *recent + 2, *recent + 3);
			*recent += 3;
			break;
		case 2: sprintf(text, "%d %d", *recent + 1, *recent + 2);
			*recent += 2;
			break;
		case 3: sprintf(text, "%d", *recent + 1);
			*recent += 1;
			break;
		}
	}
	else
		switch (*recent) {
		case 27: sprintf(text, "%d %d %d", 28, 29, 30);
			*recent += 3;
			break;
		case 28: sprintf(text, "%d %d", 29, 30);
			*recent += 2;
			break;
		default: sprintf(text, "%d", *recent + 1);
			*recent += 1;
			break;
		}
	printf("%s\n\n", text);
}