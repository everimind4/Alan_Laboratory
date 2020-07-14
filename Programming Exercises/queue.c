#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = 0;
int rear = 0;
int count = 0;

void Push(int val);
int Pop();
int isFull();
int isEmpty();
void printQueue();

void main()
{
    int num;
    while (1)
    {
        printf("push:1, pop:2, quit:q --> select:");
        if (scanf("%d", &num) == 0)
            break;
        if (num == 1)
        {
            if (isFull())
            {
                printf("Queue is Full!\n");
                continue;
            }
            int val;
            printf("Value to queue: ");
            scanf("%d", &val);
            Push(val);
            printQueue();
        }
        else if (num == 2)
        {
            if (isEmpty())
            {
                printf("Queue is Empty!\n");
                continue;
            }
            Pop();
            printQueue();
        }
        else
        {
            printf("\nWrong number! Try again.\n\n");
            continue;
        }
    }
}


void Push(int val)
{
    queue[rear] = val;
    rear++;

    if (SIZE <= rear)
        rear = 0;

    count++;

    return;
}

int Pop()
{
    int val = queue[front++];

    if (SIZE <= front)
        front = 0;

    count--;

    return val;
}

int isFull()
{
    return (SIZE <= count);
}

int isEmpty()
{
    return (count <= 0);
}

void printQueue()
{
    if (isEmpty())
        printf("Queue is Empty!");
    else
    {
        printf("Queue:");

        if (front < rear)
        {
            for (int i = front; i < rear; i++)
                printf("%d ", queue[i]);
        }
        else
        {
            for (int i = front; i < SIZE; i++)
                printf("%d ", queue[i]);
            for (int i = 0; i < rear; i++)
                printf("%d ", queue[i]);
        }
        printf("\n");
    }
}