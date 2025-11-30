// #include <stdio.h>

// int main() {
//     int size;

//     printf("Enter the size of the array: ");
//     scanf("%d", &size);

//     int arr[size];

//     printf("Enter %d elements:\n", size);
//     for (int i = 0; i < size; i++) {
//         printf("Element %d: ", i + 1);
//         scanf("%d", &arr[i]);
//     }

//     printf("\n\tOriginal Array: \t\n");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }

//     int newElement,newElement2;
//     printf("\nEnter the element to insert at the end: ");
//     scanf("%d", &newElement);
//     //printf("\nEnter the element to insert at the end: ");
//     //scanf("\n%d\n", &newElement2);

//     size++;
//     arr[size - 1] = newElement;
//     //arr[size - 2] = newElement;

//     printf("\tUpdated Array:\t\n ");
//     for (int i = 0; i < size; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n%d", size);

//     return 0;
// }

#include <stdio.h>
int main()
{
    int n;
    printf("enter the size of the array\n");
    scanf("%d", &n);
    int a[n];

    printf("enter %d elements\n", n);

    for (size_t i = 0; i < n; i++)
        scanf(" %d", &i[a]);
  
    a[n+1] = 5;

}