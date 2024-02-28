// LAB 5: Write a menu based program to simulate the basic operations of stack
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3
int stack[MAX_SIZE];
int top = -1;
int push(int element);
int pop();
void display();

int main()
{
    int choice, element;

    while (1)
    {
        printf("\n****Stack Operations Menu****\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(element);
            break;
        case 2:
            pop();
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

int push(int element)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack is Overflow\n");
        return 0;
    }
    top = top + 1;
    stack[top] = element;
    return 1;
}

int pop()
{
    if (top == -1)
    {
        printf(" Stack is Underflow\n");
        return -1;
    }
    int poppedElement = stack[top];
    top = top - 1;
    return poppedElement;
}

void display()
{
    if (top == -1)
    {
        printf("Stack is Undeflow.\n");
        return;
    }
    printf("Elements in the stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
