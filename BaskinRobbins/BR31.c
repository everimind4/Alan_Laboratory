#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

// Function Prototypes
void Talk(char*, int, int);	// �ܼ� ����� Time Delay�� �̿��� ����� Ÿ�����ϴ� �Ͱ� �����ϰ� ���̵��� ����� �Լ�
void Greet();				// ����ڿ��� ȯ�� �޽����� ������ �Լ�
void Guide();				// ������ ��Ģ�� �ƴ��� ���� �� ��� ��Ģ�� ����ϴ� �Լ�
void Play();				// ������ ������ �����ϴ� �Լ�
int Player(int*);			// ���� �� �÷��̾��� ���ʸ� �����ϴ� �Լ�
void Computer(int*, int);	// ���� �� ��ǻ���� ���ʸ� �����ϴ� �Լ�
int Replay();				// �ٽ� ������ �� ���θ� ���� �Լ�

void main() {
	Greet();
	Guide();
	Play();
}

void Talk(char* text, int newline, int wait) { // text�� ����� �ؽ�Ʈ, newline�� wait�� ��� �ɼ�
	srand((unsigned int)time(NULL));
	for (int i = 0; i < (signed int)strlen(text); i++) {
		printf("%c", text[i]);
		Sleep(rand() % 41 + 40); // 1���ڰ� 0.04~0.08���� �ð� ������ ������ ��µǵ��� ����
	}
	if (newline) { // newline�� 0�̸� �������� ����, 1�̸� ���� 2ȸ
		Sleep(10); printf("\n"); Sleep(10); printf("\n");
	}
	if (wait) { // wait�� 0�̸� �ؽ�Ʈ ��� ���� ���ð� ����, 1�̸� �ؽ�Ʈ ��� ���� 1.5�� ���
		Sleep(1500);
	}
}

void Greet() { 
	char name[10];			// ����� �̸��� ������ ����
	printf("Enter your name : ");
	scanf("%s", name);		// ����� �̸� �Է�
	getchar();				// ��� �Է� �� �Էµ� ���� ���ڸ� ���ۿ��� ����
	char greet[20];			// ȯ�� �޽����� ������ ����
	sprintf(greet, "Greeting, %s.", name); // ȯ�� �޽����� ����� �̸� �����Ͽ� ����
	printf("\n"); printf(". "); Sleep(800); printf(". "); Sleep(800); printf("."); Sleep(800); // �ε��ϴ� �Ͱ� ������ ȿ���� ���� ���� ��� ����
	Talk((char*)"Okay.", 1, 1); // �ε� �Ϸ�
	Talk(greet, 0, 1); 
	Talk(" Welcome to Baskin Robbins Game.", 1, 1); // ȯ�� �޽��� ���
}

void Guide() {
	Talk("Do you know the rule of this game?", 0, 0); // ����ڿ��� ��Ģ�� �ƴ��� ����
	char answer[2];			// ����� �����ϴ� ����
	printf(" [Y/N] : ");	// ��� ���� �ȳ���
	scanf("%s", answer);	// ��� ����
	getchar();				// ��� �Է� �� �Էµ� ���� ���ڸ� ���ۿ��� ����
	answer[1] = '\0';		// Yes, No �� ���� ���ڰ� �Էµ��� ��� �� �� ���ڸ� ����
	Sleep(1000);
	printf("\n");
	for (;;) {
		if (answer[0] == *"Y" || answer[0] == *"y") { // ��Ģ�� �ȴٰ� �� ��� �ٷ� ���� ����
			Talk("Okay. Let's play!", 1, 1);
			return;
		}
		else if (answer[0] == *"N" || answer[0] == *"n") { // ��Ģ�� �𸥴ٰ� �� ��� ��Ģ ���
			Talk("Okay. Here's the rule.", 1, 1);
			Talk("1. Say numbers alternately.", 0, 1); printf("\n");
			Talk("2. A minimum of one number and a maximum of three digits in one's turn.", 0, 1); printf("\n");
			Talk("3. Start with one, and the one who says 31 loses.", 1, 1); printf("\n");
			Talk("", 0, 1);
			Talk("Now, Let's play!", 1, 1);
			return;
		}
		else { // Y�� N�� �ƴ� ���ڸ� �Է��� ���
			Talk("Enter either Y or N.", 1, 1);
			Talk("Do you know the rule of this game?", 0, 0);
			printf(" [Y/N] : ");// ��� ���� �ȳ���
			scanf("%s", answer);// ��� ����
			getchar();			// ��� �Է� �� �Էµ� ���� ���ڸ� ���ۿ��� ����
			answer[1] = '\0';	// Yes, No �� ���� ���ڰ� �Էµ��� ��� �� �� ���ڸ� ����
			printf("\n");
		}
	}
}

void Play() {
	int recent = 2;
	printf("COM : ");
	Talk("", 0, 1); Talk("1 2", 1, 0);
	for (;;) {		
		int count = Player(&recent);
		Computer(&recent, count);
		if (recent == 30)
			if (Replay()) {
				recent = 2;
				printf("COM : ");
				Talk("", 0, 1); Talk("1 2", 1, 0);
				continue;
			}
			else
				break;
	}
}

int Player(int* recent) {
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
			if (nums[0] - 1 != *recent) {	// 1��° ���� - 1 = 2��° �������� �˻�
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count�� 0���� �ʱ�ȭ
				continue;					// ���� �ٸ� ��� �ٽ� �Է�
			}
		default: {							// ��� ���ڰ� ����� �Էµ� ���
			printf("\n");
			*recent += count;				// �Էµ� ���� ������ŭ ���� ���ڸ� ������Ų��.			
			return count;					// count�� 0���� �ʱ�ȭ��Ų��.
		}
		}
	}
}

void Computer(int* recent, int count) {
	printf("COM : ");
	char text[9];	// ��ǻ�Ͱ� ����� ���ڸ� ���ڿ��� ������ ����
	switch (count) {
	case 1: sprintf(text, "%d %d %d", *recent + 1, *recent + 2, *recent + 3);	// ����ڰ� 1���� �Է����� ��� ���� 3�� ���
		*recent += 3;
		break;
	case 2: sprintf(text, "%d %d", *recent + 1, *recent + 2);					// ����ڰ� 2���� �Է����� ��� ���� 2�� ���
		*recent += 2;
		break;
	case 3: sprintf(text, "%d", *recent + 1);									// ����ڰ� 3���� �Է����� ��� ���� 1�� ���
		*recent += 1;
		break;
	}	
	Talk("", 0, 1); Talk(text, 1, 0);											// �̷��� ����ϵ��� ������ ������ ����Դϴ�.
}

int Replay() {
	srand((unsigned int)time(NULL));
	int num = rand() % 4;
	Talk("", 0, 1);
	switch (num) { // �¸������� ��Ÿ���� �޽��� ���
	case 0: Talk("Haha, I won!", 1, 1);
		break;
	case 1: Talk("You don't seem to be enough to be my opponent yet.", 1, 1);
		break;
	case 2: Talk("You'd better practice more.", 1, 1);
		break;
	case 3: Talk("I think...", 0, 1);
		Talk("I won.", 1, 1);
		break;
	}
	// �Ʒ��� ������ �ٽ� ������ ���� ���� �ڵ��, Guide�Լ��� ������ �����ϴ�.
	Talk("Would you like to play one more time?", 0, 0); // ����ڿ��� ��Ģ�� �ƴ��� ����
	char answer[2];			// ����� �����ϴ� ����
	printf(" [Y/N] : ");	// ��� ���� �ȳ���
	scanf("%s", answer);	// ��� ����
	getchar();				// ��� �Է� �� �Էµ� ���� ���ڸ� ���ۿ��� ����
	answer[1] = '\0';		// Yes, No �� ���� ���ڰ� �Էµ��� ��� �� �� ���ڸ� ����
	Sleep(1000);
	printf("\n");
	for (;;) {
		if (answer[0] == *"Y" || answer[0] == *"y") {		// �� �� �� �ϴ� ��� 1 ��ȯ
			Talk("Okay. Let's play!", 1, 0);
			return 1;
		}
		else if (answer[0] == *"N" || answer[0] == *"n") {	// �� �Ѵٰ� �� ��� 0 ��ȯ
			Talk("Good Bye.", 0, 1);
			printf("\n\n");
			return 0;
		}
		else { // Y�� N�� �ƴ� ���ڸ� �Է��� ���
			Talk("Enter either Y or N.", 1, 1);
			Talk("Do you know the rule of this game?", 0, 0);
			printf(" [Y/N] : "); // ��� ���� �ȳ���
			scanf("%s", answer); // ��� ����
			answer[1] = '\0'; // Yes, No �� ���� ���ڰ� �Էµ��� ��� �� �� ���ڸ� ����
			printf("\n");
		}
	}
}