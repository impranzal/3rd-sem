#include <stdio.h>

int bubbleSort(int A[], int n, int choice)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Pass %d:\n", i + 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d\t ", A[i]);
        }
        printf("\n");

        // Bubble sort logic
        for (int j = 0; j < n - i - 1; j++)
        {
            if (choice == 1)
            { // Ascending
                if (A[j] > A[j + 1])
                {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
            else
            { // Descending
                if (A[j] < A[j + 1])
                {
                    int temp = A[j];
                    A[j] = A[j + 1];
                    A[j + 1] = temp;
                }
            }
            for (int j = 0; j < n; j++)
            {
                printf("%d\t ", A[j]);
            }
            printf("\n");
        }
         printf("\n");
    }
    printf("\n\nThe sorted data is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t ", A[i]);
    }
    printf("\n");
}

int main()
{
    printf("\t****BUBBLE SORT ALGORITHM******\n\n");
    printf("Enter the no. of terms to be sorted: ");
    int terms;
    scanf("%d", &terms);
    int numbers[terms];
    printf("Enter the numbers to be sorted: ");
    for (int i = 0; i < terms; i++)
    {
        scanf("%d", &numbers[i]);
    }

    int choice;
    printf("\nChoose sorting order: ");
    printf("\n1.Ascending");
    printf("\n2.Descending");
    printf("\nEnter your choice:");
    scanf("%d", &choice);

    if (choice == 1)
        bubbleSort(numbers, terms, 1);
    else if (choice == 2)
        bubbleSort(numbers, terms, 2);
    else
        printf("\nInvalid option selected.");

    return 0;
}