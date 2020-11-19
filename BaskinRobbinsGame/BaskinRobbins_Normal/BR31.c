#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Player(int*);		// 게임 내 플레이어의 차례를 진행하는 함수
void Computer(int*);	// 게임 내 컴퓨터의 차례를 진행하는 함수

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
	int count = 0;			// 사용자가 몇 개의 숫자를 입력했는지 세기 위한 변수
	int check;				// 사용자가 올바르게 입력했는지 검사하기 위한 변수
	char input[100];		// 사용자가 입력하는 여러 개의 숫자를 '띄어쓰기를 포함한 문자열로' 저장하기 위한 변수
	char numstring[3][3];	// 위 input 변수를 띄어쓰기를 기준으로 구분하여 저장하기 위한 문자열 배열
	int nums[3];			// 띄어쓰기로 구분된 문자열을 숫자로 변환해 저장하는 숫자 배열
	for (;;) {				// 올바르게 입력될 때 까지 무한루프 실행
		for (int i = 0; i < 3; i++)				// 문자열 배열의 각 요소를 Null character로 만들어 준다.
			numstring[i][0] = '\0';
		printf("You : ");
		check = scanf("%[^\n]", input);			// %[^\n] 형식을 사용해 띄어쓰기를 포함한 문자열을 입력받는다.
		getchar();								// 입력 문자열 맨 마지막 개행 문자를 입력 버퍼에서 제거
		if (check == 0 || strlen(input) == 0) { // scanf()함수에서 입력받은 것이 없거나, 어떠한 이유로 input의 길이가 0일 경우 다시 입력받는다.
			printf("\nNothing was entered. Try again.\n\n");
			continue;
		}
		int idx = 0; // input 문자열을 잘라서 numstring에 입력할 때 사용하는 인덱스 변수
		for (int i = 0; i < (signed int)strlen(input) + 1; i++) { // input 문자열에서 하나씩 읽어들여서 numstring 배열 요소에 저장 (count : 행, idx : column)
			if (input[i] == ' ' || input[i] == '\0') { // input 문자열에 띄어쓰기가 있거나 문자열이 끝나는 경우 numstring에 저장된 문자열 맨 뒤에 null문자 입력
				numstring[count][idx] = '\0';
				count++;
				idx = 0;
				continue;
			}
			if (count == 3 && input[i] != '\0') { // 숫자를 3개보다 많이 입력했을 경우 다시 입력
				printf("\nYou've entered too many numbers. Please enter again.\n\n");
				count = 0;	// count를 0으로 초기화
				check = -1;	// scanf 입력 검사에 사용했던 변수인 check를 재사용 - 숫자를 3개보다 많이 입력된 경우에 대한 진단
				break;
			}
			numstring[count][idx++] = input[i]; // input 문자열에서 하나씩 읽어들여서 numstring 배열 요소에 저장 (count : 행, idx : column)
		}
		if (check == -1)	// scanf 입력 검사에 사용했던 변수인 check를 재사용 - 숫자를 3개보다 많이 입력된 경우에 대한 진단
			continue;
		count = 0; // 띄어쓰기 개수를 기준으로 count 변수에 저장되는 값이 결정되므로 실제로 nums 배열에 숫자를 저장하며 저장되는 개수를 count 변수에 저장하기 위해 0으로 초기화
		for (int i = 0; i < 3; i++)
			if (strlen(numstring[i]) > 0)
			{
				nums[i] = atoi(numstring[i]);	// numstring에 저장된 숫자 문자열을 정수로 변환해 nums에 저장
				count++;						// 저장할 때 입력된 개수 1 증가
			}
			else
				nums[i] = 0; // 
		switch (count) { // count에 저장된 값(실제로 입력된 숫자 개수)을 기준으로 입력된 숫자의 적정성 검사
		case 3:
			if (nums[2] - 1 != nums[1]) {	// 3번째 숫자 - 1 = 2번째 숫자인지 검사
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count를 0으로 초기화
				continue;					// 서로 다를 경우 다시 입력
			}								// switch문에 break가 없으면 다음 case로 넘어감 - 다음 숫자를 계속 검사하기 위해 break를 입력하지 않음
		case 2:
			if (nums[1] - 1 != nums[0]) {	// 2번째 숫자 - 1 = 1번째 숫자인지 검사
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count를 0으로 초기화
				continue;					// 서로 다를 경우 다시 입력
			}
		case 1:
			if (nums[0] - 1 != *recent) {	// 1번째 숫자 - 1 = 현재 숫자인지 검사
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count를 0으로 초기화
				continue;					// 서로 다를 경우 다시 입력
			}
		default: {							// 모든 숫자가 제대로 입력된 경우
			printf("\n");
			*recent += count;				// 입력된 숫자 개수만큼 현재 숫자를 증가시킨다.
			return;
		}
		}
	}
}

void Computer(int* recent) {
	srand((unsigned int)time(NULL));
	printf("COM : ");
	char text[9];	// 컴퓨터가 대답할 숫자를 문자열로 저장할 변수
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