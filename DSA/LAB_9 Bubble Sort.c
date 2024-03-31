#include <stdio.h>
void bubbleSort(int array[], int size);
int main()
{
    int array[10], size;
    printf  ("\t******BUBBLE SORT ALGORITHM ******\n\n");
    printf("Enter number of elements: ");
    scanf("%d", &size);

    printf("Enter %d integers:\n", size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    bubbleSort(array, size);
    printf("Sorted list in ascending order:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d\t", array[i]);
    }
    return 0;
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
