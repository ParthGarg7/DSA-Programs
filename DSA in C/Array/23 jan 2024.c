#include <stdio.h>
int main()
{

    // elements insertion
    int size, element, UB, LB = 0, i, j, temp, location, choice1, limit;
    printf("Enter the size of the array\n");
    scanf("%d", &size);

    int a[size];
    a[size];
    printf("How many elements you want to enter?\n");
    scanf("%d", &limit);
    printf("Enter the elements of the array\n");
    for (i = 0; i < limit; i++)
        scanf("%d", &a[i]);
    UB = limit - 1;

    printf("\tOriginal Array\t\n");
    for (i = 0; i < limit; i++)
        printf("%d ", a[i]);

    // for sorting array
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\n\tSorted Array\t\n");
    for (i = 0; i < limit; i++)
        printf("%d ", a[i]);

    // binary search
    int value, beg, end, mid, loc, counter = 0;
    beg = 0, end = size - 1;
    printf("\nEnter the Value you want to find\n");
    scanf("%d", &value);

    while (beg <= end)
    {
        mid = (beg + end) / 2;
        if (a[mid] == value)
        {
            loc = mid;
            printf("Element found at index %d", loc);
            counter++;
            break;
        }
        else if (value > a[mid])
            beg = mid + 1;
        else
            end = mid - 1;
    }

    if (counter = 0)
        printf("Element not found");
}