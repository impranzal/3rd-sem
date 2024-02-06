#include <stdio.h>
#include <math.h>
// #include <conio.h>
#define EPS 0.00001

float g(float x)
{
    return (5 + 0.5 * sin(x));
}

int main()
{
    float x0, x1;
    int n = 1;
    printf("Fixed Point Iteration Method\n");
    printf("Enter an initial point x0 : ");
    scanf("%f", &x0);
    x1 = g(x0);
    while (fabs((x1 - x0) / x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = g(x0);
        if (g(x1) == x1)
            break;
    }

    printf("The approximate root  is %f with %d  iterations.", x1, n);
    //  getch();
    return 0;
}
