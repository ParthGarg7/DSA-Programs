#include <stdio.h>
#include <stdlib.h>

// This code demonstrates different methods of array creation in C
int main()
{
    // Method 1: Using a static array
    int array1[5] = {1, 2, 3, 4, 5};

    printf("Method 1: Using a basic static array\n");
    for (int i = 0; i < 5; i++)
        printf("%d ", array1[i]);
    printf("\n");

    // Method 2: Using a dynamically allocated array
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int *Array2 = (int *)malloc(sizeof(int) * size);

    // Check if memory allocation was successful
    if (Array2 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1; // Exit with an error code
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &Array2[i]);
    }

    printf("Method 2: Using a dynamically allocated array\n");
    for (int i = 0; i < size; i++)
        printf("%d ", Array2[i]);
    printf("\n");

    // Free the allocated memory
    free(Array2);
    Array2 = NULL; // Prevent dangling pointer

    return 0;
}
