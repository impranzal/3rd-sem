#include <stdio.h>
#include <math.h>
#include <conio.h>
#define EPS 0.00001

float f(float x)
{
    
    // return exp(x) - x - 2;
    //return sin(x)-2*x+1;
    return 2*x+3*cos(x)-exp(x);
}

int main()
{
    float a, b, c;
    int n = 0;
    do
    {
        printf("Enter two initial points a and b: ");
        scanf("%f%f", &a, &b);
    } while (f(a) * f(b) >= 0);

    do
    {
        n++;
        c = (a + b) / 2;
        if (f(c) == 0)
            break;
        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;
    }

    while (fabs((b - a) / a) > EPS);
    printf("The approximate root  is %f with %d iterations.", c, n);
    getch();
    return 0;
}