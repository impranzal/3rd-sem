#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE] = {0};

int hash1(int key)
{
    return key % TABLE_SIZE;
}

int hash2(int key)
{
    return 7 - (key % 7);
}

void insert()
{
    int key, index, i;
    printf("\nEnter a value to insert into hash table: ");
    scanf("%d", &key);
    index = hash1(key);
    if (h[index] == 0)
    {
        h[index] = key;
    }
    else
    {
        int increment = hash2(key);
        for (i = 1; i < TABLE_SIZE; i++)
        {
            index = (hash1(key) + i * increment) % TABLE_SIZE;
            if (h[index] == 0)
            {
                h[index] = key;
                break;
            }
        }
        if (i == TABLE_SIZE)
            printf("\nElement cannot be inserted\n");
    }
}

void search()
{
    int key, index, i;
    printf("\nEnter search element: ");
    scanf("%d", &key);
    index = hash1(key);
    if (h[index] == key)
    {
        printf("Value is found at index %d\n", index);
        return;
    }
    else
    {
        int increment = hash2(key);
        for (i = 1; i < TABLE_SIZE; i++)
        {
            index = (hash1(key) + i * increment) % TABLE_SIZE;
            if (h[index] == key)
            {
                printf("Value is found at index %d\n", index);
                return;
            }
        }
    }
    printf("Value is not found\n");
}

void display()
{
    int i;

    printf("\n   Hash Table\n");
    printf("----------------\n");
    printf("|  Index | Value |\n");
    printf("-----------------\n");
    for (i = 0; i < TABLE_SIZE; i++)
        printf("|   %2d  |  %3d  |\n", i, h[i]);
    printf("-----------------\n");
}

int main()
{
    int opt;
    printf("\t******DOUBLE HASHING******\n\n");
    while (1)
    {

        printf("Press:\n1. Insert\n2. Display\n3. Search\n4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            search();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}
