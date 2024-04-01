#include <stdio.h>
#include <stdlib.h>

int number[50];

int linearSearch(int total, int temp) {
    for (int i = 0; i < total; i++) {
        if (number[i] == temp) {
            return (i + 1); 
        }
    }
    return 0;
}
int main() {
    int total, temp;
    printf  ("\t******LINEAR SEARCH ALGORITHM ******\n\n");
    printf("Enter the total number of data: ");
    scanf("%d", &total);
    printf("\nEnter the data now (Ascending order only):\n");
    for (int i = 0; i < total; i++) {
        scanf("%d", &number[i]);
    }
    while (1) {
        printf("\nEnter the number to be searched in the array: ");
        scanf("%d", &temp);
        int res = linearSearch(total, temp)-1;
        if (res == 0)
            printf("Number not found.\n");
        else
            printf("Number found at index %d.\n", res);
        printf("Do you want to continue (y/n)? ");
        fflush(stdin);
        char choice;
        scanf(" %c", &choice); 
        if (choice != 'y' && choice != 'Y')
            exit(0);
    }
    return 0;
}
