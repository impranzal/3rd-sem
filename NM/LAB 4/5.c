// Finding Eigenvalue and eigenvector using Power Method
#include <stdio.h>
#include <math.h>
#define MAX 10
#define EPS 0.0001

int main()
{
    int i, j, k, n, count = 0;
    float ev = 1.0, ev_temp, temp_max, a[MAX][MAX], x[MAX], y[MAX];
    printf("\nInput size of matrix: ");
    scanf(" %d", &n);
    printf("\nInput elements row-wise : ");

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%f", &a[i][j]);

    for (i = 1; i <= n; i++)
        x[i] = 1;

    do
    {
        for (i = 1; i <= n; i++)
            y[i] = 0;

        ev_temp = ev;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                y[i] = y[i] + a[i][j] * x[j];

        for (i = 1; i <= n; i++)
            x[i] = y[i];

        temp_max = fabs(x[1]);
        k = 1;

        for (j = 2; j <= n; j++)
        {
            if (fabs(x[j]) > temp_max)
            {
                temp_max = fabs(x[j]);
                k = j;
            }
        }

        ev = x[k];

        for (i = 1; i <= n; i++)
            x[i] = x[i] / ev;

        count++;

    } while (fabs((ev_temp - ev) / ev) > EPS);

    printf("\nApproximate eigenvalue is %.5f: ", ev);
    printf("\nCorresponding eigenvector is:\n");
    for (i = 1; i <= n; i++)
        printf("\t%.5f", x[i]);

    printf("\nNumber of iterations: %d\n", count);

    return 0;
}
