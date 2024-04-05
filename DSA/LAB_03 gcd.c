// LAB 3: write a recursive program to find the gcd og two user input integers
#include <stdio.h>
int gcd(int n1, int n2);
int main()
{
    int n1, n2, res;
    printf("*****GCD*****\n");
    printf("Enter two numbers: ");
    scanf("%d%d", &n1, &n2);
    if (n1 < n2)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    res = gcd(n1, n2);
    printf("The GCD of %d and %d is %d", n1, n2, res);
    return 0;
}
int gcd(int n1, int n2)
{
    if (n2 == 0)
        return n1;
    else
        return gcd(n2, n1 % n2);
}
