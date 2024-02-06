#include <stdio.h>
#include <math.h>
// #include <conio.h>
#define EPS 0.00001

float f(float x)
{
    return x * sin(x) + cos(x);
}
float fd(float x)
{
    return x * cos(x);
}

int main()
{
    float x0, x1;
    int n = 1;
    do
    {
        printf("Newton Raphson\n");
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
    // getch();
    return 0;
}
