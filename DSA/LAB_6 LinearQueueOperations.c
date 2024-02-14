// LAB 6:Write a menu driven program to simulate the operation in linear queue.
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 2

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int element);
int dequeue();
void display();

int main()
{
    int choice, element;

    while (1)
    {
        printf("\nLinear Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue: ");
            scanf("%d", &element);
            enqueue(element);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

void enqueue(int element)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue is full. Cannot enqueue element.\n");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = element;
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty. Cannot dequeue element.\n");
        return -1;
    }
    int dequeuedElement = queue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    return dequeuedElement;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
