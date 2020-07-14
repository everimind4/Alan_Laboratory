#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int stack[SIZE];
int idx = 0;

void Push(int);
int Pop();
int isFull();
int isEmpty();
void printStack();

void main()
{
	int num;
	while (1)
	{
		printf("Push : 1, Pop : 2, quit : q --> select : ");
		if (scanf("%d", &num) == 0)
		{
			printf("\nBye.\n");
			break;
		}
		if (num == 1)
		{
			if (isFull())
			{
				printf("\nStack if Full!\n\n");
				continue;
			}
			int val;
			printf("\nValue to stack: ");
			scanf("%d", &val);
			Push(val);
			printStack();
		}
		else if (num == 2)
		{
			if (isEmpty())
			{
				printf("\nStack is Empty!\n\n");
				continue;
			}
			Pop();
			printStack();
		}
		else
		{
			printf("\nWrong number! Try again.\n\n");
			continue;
		}
		puts("");
	}
}

void Push(int val)
{
	stack[idx++] = val;
}

int Pop()
{
	return idx--;
}

int isFull()
{
	return (SIZE <= idx);
}

int isEmpty()
{
	return (idx <= 0);
}

void printStack()
{
	if (idx == 0)
		printf("\nStack is Empty!");
	else
	{
		printf("\nStack : ");
		for (int i = 0; i < idx; i++)
			printf("%d ", stack[i]);
	}
	puts("");
}

