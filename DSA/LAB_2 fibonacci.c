// LAB 2: Write a recursive program to display n number of fibonaci numbers for user input n
#include <stdio.h>
int fibonacci(int n);
int main()
{
    int num, fibo;
    printf("*****FIBONACCI*****\n");
    printf("Enter any number:");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        fibo = fibonacci(i);
        printf("%d\t", fibo);
    }
    return 0;
}
int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}