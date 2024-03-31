#include <stdio.h>
#include <stdlib.h>

int number[50];

int linearSearch(int total, int temp) {
    for (int i = 0; i < total; i++) {
        if (number[i] == temp) {
            return (i + 1); // Return the position (index + 1) if the number is found
        }
    }
    return 0; // Return 0 if the number is not found
}

int main() {
    int total, temp;
    printf("Enter the total number of data: ");
    scanf("%d", &total);
    printf("\nEnter the data now (Ascending order only):\n");
    for (int i = 0; i < total; i++) {
        scanf("%d", &number[i]);
    }
    while (1) {
        printf("\nEnter the number to be searched in the array: ");
        scanf("%d", &temp);
        int res = linearSearch(total, temp);
        if (res == 0)
            printf("Number not found.\n");
        else
            printf("Number found at position %d.\n", res);
        printf("Do you want to continue (y/n)? ");
        fflush(stdin);
        char choice;
        scanf(" %c", &choice); // Note the space before %c to consume the newline character
        if (choice != 'y' && choice != 'Y')
            exit(0);
    }
    return 0;
}
