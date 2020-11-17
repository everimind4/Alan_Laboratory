#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

// Function Prototypes
void Talk(char*, int, int);	// 콘솔 출력을 Time Delay를 이용해 사람이 타이핑하는 것과 유사하게 보이도록 만드는 함수
void Greet();				// 사용자에게 환영 메시지를 보내는 함수
void Guide();				// 게임의 규칙을 아는지 묻고 모를 경우 규칙을 출력하는 함수
void Play();				// 실제로 게임을 진행하는 함수
int Player(int*);			// 게임 내 플레이어의 차례를 진행하는 함수
void Computer(int*, int);	// 게임 내 컴퓨터의 차례를 진행하는 함수
int Replay();				// 다시 도전할 지 여부를 묻는 함수

void main() {
	Greet();
	Guide();
	Play();
}

void Talk(char* text, int newline, int wait) { // text는 출력할 텍스트, newline과 wait는 출력 옵션
	srand((unsigned int)time(NULL));
	for (int i = 0; i < (signed int)strlen(text); i++) {
		printf("%c", text[i]);
		Sleep(rand() % 41 + 40); // 1글자가 0.04~0.08초의 시간 간격을 가지고 출력되도록 설정
	}
	if (newline) { // newline이 0이면 개행하지 않음, 1이면 개행 2회
		Sleep(10); printf("\n"); Sleep(10); printf("\n");
	}
	if (wait) { // wait가 0이면 텍스트 출력 이후 대기시간 없음, 1이면 텍스트 출력 이후 1.5초 대기
		Sleep(1500);
	}
}

void Greet() { 
	char name[10];			// 사용자 이름을 저장할 변수
	printf("Enter your name : ");
	scanf("%s", name);		// 사용자 이름 입력
	getchar();				// 대답 입력 시 입력된 개행 문자를 버퍼에서 삭제
	char greet[20];			// 환영 메시지를 저장할 변수
	sprintf(greet, "Greeting, %s.", name); // 환영 메시지에 사용자 이름 삽입하여 저장
	printf("\n"); printf(". "); Sleep(800); printf(". "); Sleep(800); printf("."); Sleep(800); // 로딩하는 것과 유사한 효과를 내기 위한 출력 구문
	Talk((char*)"Okay.", 1, 1); // 로딩 완료
	Talk(greet, 0, 1); 
	Talk(" Welcome to Baskin Robbins Game.", 1, 1); // 환영 메시지 출력
}

void Guide() {
	Talk("Do you know the rule of this game?", 0, 0); // 사용자에게 규칙을 아는지 질문
	char answer[2];			// 대답을 저장하는 변수
	printf(" [Y/N] : ");	// 대답 형식 안내문
	scanf("%s", answer);	// 대답 저장
	getchar();				// 대답 입력 시 입력된 개행 문자를 버퍼에서 삭제
	answer[1] = '\0';		// Yes, No 등 여러 글자가 입력됐을 경우 맨 앞 글자만 저장
	Sleep(1000);
	printf("\n");
	for (;;) {
		if (answer[0] == *"Y" || answer[0] == *"y") { // 규칙을 안다고 할 경우 바로 게임 시작
			Talk("Okay. Let's play!", 1, 1);
			return;
		}
		else if (answer[0] == *"N" || answer[0] == *"n") { // 규칙을 모른다고 할 경우 규칙 출력
			Talk("Okay. Here's the rule.", 1, 1);
			Talk("1. Say numbers alternately.", 0, 1); printf("\n");
			Talk("2. A minimum of one number and a maximum of three digits in one's turn.", 0, 1); printf("\n");
			Talk("3. Start with one, and the one who says 31 loses.", 1, 1); printf("\n");
			Talk("", 0, 1);
			Talk("Now, Let's play!", 1, 1);
			return;
		}
		else { // Y나 N이 아닌 문자를 입력한 경우
			Talk("Enter either Y or N.", 1, 1);
			Talk("Do you know the rule of this game?", 0, 0);
			printf(" [Y/N] : ");// 대답 형식 안내문
			scanf("%s", answer);// 대답 저장
			getchar();			// 대답 입력 시 입력된 개행 문자를 버퍼에서 삭제
			answer[1] = '\0';	// Yes, No 등 여러 글자가 입력됐을 경우 맨 앞 글자만 저장
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
			if (nums[0] - 1 != *recent) {	// 1번째 숫자 - 1 = 2번째 숫자인지 검사
				printf("\nYou have entered an invalid value. Please enter again.\n\n");
				count = 0;					// count를 0으로 초기화
				continue;					// 서로 다를 경우 다시 입력
			}
		default: {							// 모든 숫자가 제대로 입력된 경우
			printf("\n");
			*recent += count;				// 입력된 숫자 개수만큼 현재 숫자를 증가시킨다.			
			return count;					// count를 0으로 초기화시킨다.
		}
		}
	}
}

void Computer(int* recent, int count) {
	printf("COM : ");
	char text[9];	// 컴퓨터가 대답할 숫자를 문자열로 저장할 변수
	switch (count) {
	case 1: sprintf(text, "%d %d %d", *recent + 1, *recent + 2, *recent + 3);	// 사용자가 1개를 입력했을 경우 숫자 3개 대답
		*recent += 3;
		break;
	case 2: sprintf(text, "%d %d", *recent + 1, *recent + 2);					// 사용자가 2개를 입력했을 경우 숫자 2개 대답
		*recent += 2;
		break;
	case 3: sprintf(text, "%d", *recent + 1);									// 사용자가 3개를 입력했을 경우 숫자 1개 대답
		*recent += 1;
		break;
	}	
	Talk("", 0, 1); Talk(text, 1, 0);											// 이렇게 대답하도록 설정한 이유는 비밀입니다.
}

int Replay() {
	srand((unsigned int)time(NULL));
	int num = rand() % 4;
	Talk("", 0, 1);
	switch (num) { // 승리했음을 나타내는 메시지 출력
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
	// 아래는 게임을 다시 진행할 지를 묻는 코드로, Guide함수의 구조와 동일하다.
	Talk("Would you like to play one more time?", 0, 0); // 사용자에게 규칙을 아는지 질문
	char answer[2];			// 대답을 저장하는 변수
	printf(" [Y/N] : ");	// 대답 형식 안내문
	scanf("%s", answer);	// 대답 저장
	getchar();				// 대답 입력 시 입력된 개행 문자를 버퍼에서 삭제
	answer[1] = '\0';		// Yes, No 등 여러 글자가 입력됐을 경우 맨 앞 글자만 저장
	Sleep(1000);
	printf("\n");
	for (;;) {
		if (answer[0] == *"Y" || answer[0] == *"y") {		// 한 번 더 하는 경우 1 반환
			Talk("Okay. Let's play!", 1, 0);
			return 1;
		}
		else if (answer[0] == *"N" || answer[0] == *"n") {	// 안 한다고 한 경우 0 반환
			Talk("Good Bye.", 0, 1);
			printf("\n\n");
			return 0;
		}
		else { // Y나 N이 아닌 문자를 입력한 경우
			Talk("Enter either Y or N.", 1, 1);
			Talk("Do you know the rule of this game?", 0, 0);
			printf(" [Y/N] : "); // 대답 형식 안내문
			scanf("%s", answer); // 대답 저장
			answer[1] = '\0'; // Yes, No 등 여러 글자가 입력됐을 경우 맨 앞 글자만 저장
			printf("\n");
		}
	}
}