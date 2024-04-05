#include <stdio.h>

// Function to merge two sorted subarrays arr[l..m] and arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        // Display comparison operation
        printf("\nComparing: %d and %d\n", L[i], R[j]);
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if any
    while (i < n1)
    {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if any
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    // Display merging operation
    printf("Merging subarrays: arr[%d..%d] and arr[%d..%d]\n", l, m, m + 1, r);

    // Print the array after each merge operation
    printf("Array after merge: ");
    for (int idx = l; idx <= r; idx++)
    {
        printf("%d ", arr[idx]);
    }
    printf("\n");
}

// Main function to perform merge sort
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Find the middle point
        int m = l + (r - l) / 2;

        // Recursively sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
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
    printf("\t******MERGE SORT******\n\n");
    printf("Enter the size of the array: ");
    scanf("%d", &arr_size);

    int arr[arr_size];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < arr_size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Given array is: ");
    printArray(arr, arr_size);

    // Sorting the array using merge sort
    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
