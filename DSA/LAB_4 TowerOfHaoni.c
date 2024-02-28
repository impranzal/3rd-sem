// LAB 4: Write a recursive program to print the moves in Tower of Hanoi for input no of disk
#include <stdio.h>
int toh(int n, char A, char B, char C);

void output(int n, char A, char C)
{
    static int count = 1;
    printf("%d. Move disc %d from %c to %c\n", count, n, A, C);
    count++;
}
int main()
{
    printf("****TOWER OF HANOI****\n");
    printf("\nEnter the number of disc: ");
    int n;
    scanf("%d", &n);
    printf("\nThe steps are: \n");
    toh(n, 'A', 'B', 'C');
}

int toh(int n, char A, char B, char C)
{
    if (n == 1)
    {
        output(1, A, C);
    }
    else
    {
        toh(n - 1, A, C, B);
        output(n, A, C);
        toh(n - 1, B, A, C);
    }
}
