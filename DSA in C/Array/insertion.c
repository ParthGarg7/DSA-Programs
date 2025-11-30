#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, *LB, *UB;
    int size;
    char choice;

    UB = LB = NULL;

    printf("Enter the size of the array\n");
    scanf(" %d", &size);

    array = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        printf("Do you want to enter a element at position %d", i + 1);
        printf("Press y/Y for YES and n/N for NO: ");
        scanf(" %c",&choice);
        if (choice == 'y' || choice == 'Y')
        {
            
        }
        else if ()
        {
            
        }
        else
        {
        
        }
        
        
    }

    return 0;
}