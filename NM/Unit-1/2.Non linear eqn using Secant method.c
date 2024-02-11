#include <stdio.h>
#include <math.h>
#include <conio.h>
#define EPS 0.00001

float f(float x)
{
    // return x * x * x - 3 * x + 1;
    // return x*x*x -2*sin(x);
    return 3*x+sin(x)-exp(x);
}

int main()
{

    float x0, x1, x2;
    int n = 0;
    do
    {
       
        printf("Enter two  initial points x0 & x1 : ");
        scanf("%f%f", &x0, &x1);
    } while (f(x0) == f(x1));

    do
    {
        n++;
        x2 = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
        if (f(x2) == 0)
            break;
        x0 = x1;
        x1 = x2;
    } while (fabs((x1 - x0) / x1) > EPS);
    printf("The approximate root  is %f with %d  iterations.", x2, n);
    getch();
    return 0;
}