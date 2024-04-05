#include <stdio.h>

// Function to perform shell sort
void shellSort(int arr[], int size)
{
    // Start with a large gap, then reduce the gap
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        printf("\nGap: %d\n", gap);
        printf("---------------\n");

        // Perform insertion sort for elements at a gap
        for (int i = gap; i < size; i++)
        {
            int key = arr[i];
            int j;
            // Move elements of arr[0..i-gap], arr[1..i-gap+1], etc., by gap positions ahead
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            {
                // Shift the elements and print the operation
                arr[j] = arr[j - gap];
                printf("Swapping %d and %d\n", arr[j - gap], key);
            }
            // Insert the stored key at its correct position in sorted array
            arr[j] = key;

            // Display the array after each insertion
            printf("Array after inserting %d at index %d: ", key, j);
            for (int k = 0; k < size; k++)
            {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
}

int main()
{
    int arr_size;
    printf("\t******SHELL SORT******\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];

    printf("Enter the elements of the array:");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array is:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sorting the array using shell sort
    shellSort(arr, arr_size);

    printf("\nSorted array is:\n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
