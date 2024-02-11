#include <stdio.h>
int factorial(int n);
int main()
{
    int num, fact;
    printf("*****FACTORIAL*****\n");
    printf("Enter any number:");
    scanf("%d", &num);
    fact = factorial(num);
    printf("\nFactorial of %d = %d\n", num, fact);
    return 0;
}
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return (n * factorial(n - 1));
}
