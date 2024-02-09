
#include <stdio.h>
#define MAX 15

int main() {
    int n, i, j;
    float x[MAX], f[MAX], fp, lf, sum, xp;

    printf("\n Input the number of data pairs (maximum %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX || n <= 0) {
        printf("\n Invalid input. Number of data pairs should be between 1 and %d.\n", MAX);
        return 1;
    }

    printf("\nInput data pairs x(i) and values f(i) (one set in each line):\n");
    for (i = 0; i < n; i++)
        scanf("%f%f", &x[i], &f[i]);

    printf("\n Input x at which interpolation is required: ");
    scanf("%f", &xp);

    sum = 0.0;
    for (i = 0; i < n; i++) {
        lf = 1.0;
        for (j = 0; j < n; j++) {
            if (i != j)
                lf *= (xp - x[j]) / (x[i] - x[j]);
        }
        sum += lf * f[i];
    }
    fp = sum;
    printf("\n Interpolated function value at x = %f is %f.\n", xp, fp);

    return 0;
}
