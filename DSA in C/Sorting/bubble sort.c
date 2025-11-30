#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a positive integer input
int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value <= 0)
    {
        printf("Invalid input. Please enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

// Function to get a integer input
int scan2()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

void Bubble_sort(int array[], int size)
{
    int i, j, temp;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    int size, choice, inner_choice, i;
    int *array = NULL;

    printf("This a program of bubble sort in an array\n");

    while (1)
    {
        printf("Press 1 for making a new array\n");
        printf("Press 2 for exit\n");
        choice = scan();
        switch (choice)
        {
        case 1:
        {
            // Code for creating a new array
            printf("how many elements you want in the array\n");
            size = scan();

            // Memory allocation for the array
            array = (int *)malloc(sizeof(int) * size);

            // Check if memory allocation is successful
            if (array == NULL)
            {
                printf("Memory allocation failed. Exiting \n");
                printf("Thank you %c", 2);
                return 1;
            }

            // Manually enter array elements
            for (i = 0; i < size; i++)
            {
                printf("Enter element number %d\n", i + 1);
                array[i] = scan2();
            }

            printf("The unsorted array is \n");
            for (i = 0; i < size; i++)
                printf("%d ", array[i]);
            printf("\n");

            Bubble_sort(array, size);

            printf("The sorted array is \n");
            for (i = 0; i < size; i++)
                printf("%d ", array[i]);
            printf("\n");
        }
        break;

        case 2:
        {
            // Code for exiting the program
            printf("Exiting\nThank you %c", 2);
            // Free the allocated memory
            free(array);
            exit(0);
        }

        default:
            // Code for handling invalid choices
            printf("Invalid choice enter again\n");
            break;
        }
    }

    return 0;
}
