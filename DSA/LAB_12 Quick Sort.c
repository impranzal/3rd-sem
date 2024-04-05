#include <stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choosing the pivot element
    int i = (low - 1);     // Index of smaller element

    // Display partitioning operation
    printf("\nPartitioning array from index %d to %d with pivot %d\n", low, high, pivot);

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        printf("Comparing: %d and %d\n", arr[j], pivot);
        if (arr[j] <= pivot)
        {
            // Swap arr[i] and arr[j]
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            // Display swap operation
            printf("Swapping %d and %d\n", arr[i], arr[j]);
        }
    }
    // Swap arr[i+1] and arr[high] (or pivot)
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    // Display pivot placement
    printf("Placing pivot %d at its correct position\n", pivot);

    // Return the partition index
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);

        // Display the array after partitioning
        printf("\nArray after partitioning: ");
        for (int i = low; i <= high; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");

        // Separately sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Utility function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr_size;
    printf("\t******QUICK SORT******\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter the elements of the array:");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nGiven array is:\n");
    printArray(arr, arr_size);

    // Sorting the array using quick sort
    quickSort(arr, 0, arr_size - 1);

    printf("\n\nSorted array is:\n");
    printArray(arr, arr_size);
    return 0;
}
