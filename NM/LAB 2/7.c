//7.Fitting an exponential equation

#include <stdio.h>
#include <math.h>
#include <conio.h>
#define MAX 10
int main()
{
    int i, n;
    float x[MAX], y[MAX], u[MAX];
    float sumx = 0.0, sumu = 0.0, sumxx = 0.0, sumxu = 0.0, xmean, umean, denom, a, b;
    // Reading data values//
    printf("Input number of data points:");
    scanf("%d", &n);
    printf("\n Input x and y values: ");
    for (i = 1; i <= n; i++)
        scanf("%f %f", &x[i], &y[i]);
    for (i = 1; i <= n; i++)
        u[i] = log(y[i]);
    // Computing constants a and b//
    for (i = 1; i <= n; i++)
    {
        sumx = sumx + x[i];
        sumu = sumu + u[i];
        sumxx = sumxx + x[i] * x[i];
        sumxu = sumxu + x[i] * u[i];
    }
    xmean = sumx / n;
    umean = sumu / n;
    denom = n * sumxx - sumx * sumx;
    b = (n * sumxu - sumx * sumu) / denom;
    a = exp(umean - b * xmean);
    printf("\n The exponential equation that is fit to the given data is y = %fe^%fx.", a, b);
    getch();
    return 0;
}