#include <stdio.h>
#include <math.h>
#include <conio.h>
#define EPS 0.00001

float f(float x)
{
    //return x*exp(x)-1;
   //return  x*x*x+x*x-3*x-3;
   return 3*x+sin(x)-exp(x);
}
float fd(float x)
{
    //return 2*exp(x);
    //return 3*x*x+2*x-3;
    return 3+cos(x)-exp(x);
}

int main()
{
    float x0, x1;
    int n = 1;
    do
    {
        printf("Enter a valid initial point x0 :");
        scanf("%f", &x0);
    } while (fd(x0) == 0);
    x1 = x0 - (f(x0) / fd(x0));
    while (fabs((x1 - x0) / x1) > EPS)
    {
        n++;
        x0 = x1;
        x1 = x0 - (f(x0) / fd(x0));
        if (f(x1) == 0)
            break;
    }
    printf("The approximate root  is %f with %d  iterations.", x1, n);
    getch();
    return 0;
}
