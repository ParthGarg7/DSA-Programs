#include <stdio.h>

int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value <= 0)
    {
        printf("Invalid input. Please enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return value;
}



int main()
{
  int size;

  printf("Enter the size of the array\n");
  size = scan();


    return 0;
}

// #include <stdio.h>

// void main()
// {
//     int a[6969], size, element, UB, LB = 0, i, temp, location, choice1,limit;
//     printf("Enter the size of the array\n");
//     scanf("%d", &size);
//     a[size];
//     printf("How many elements you want to enter?\n");
//     scanf("%d",&limit);
//     printf("Enter the elements of the array\n");
//     for (i = 0; i < limit; i++)
//         scanf("%d", &a[i]);
//     UB=limit-1;    
//     printf("\tOriginal Array\t\n");
//     for (i = 0; i < limit; i++)
//         printf("%d \n", a[i]);

//     printf("What you want to do?\nPress 1 for insertion or Press 2 for deletion\n");
//     scanf(" %d", &choice1);

//     switch (choice1)
//     {
//     case 1:
//     {
//         int choice2;
//         printf("Press 1 for inserting at the end, 2 for inserting at the beginning or 3 for inserting at a particular position\n");
//         scanf(" %d", choice2);

//         switch (choice2)
//         {
//         case 1:
//         {
//             printf("Enter the element you want to enter\n");
//             scanf("%d", &element);
//             if (UB == size - 1)
//                 printf("Array is full\n");
//             else if (UB < 0)
//             {
//                 LB = UB = 0;
//                 a[UB] = element;
//             }
//             else
//             {
//                 UB++;
//                 a[UB] = element;
//             }
//             printf("\tAltered Array\t\n");
//             for (int i = 0; i < size; i++)
//                 printf("%d \n", a[i]);
//         }
//         break;

//         case 2:
//         {
//             printf("Enter the element you want to enter\n");
//             scanf("%d", &element);
//             size++;
//             if (UB == size - 1)
//                 printf("Array is full\n");
//             else if (UB < 0)
//             {
//                 LB = UB = 0;
//                 a[UB] = element;
//             }
//             else
//             {
//                 // for(i=size-1;i>=0;i--)
//                 // a[i]==a[i-1];
//                 // a[0]=element;

//                 // for(temp=UB;temp>=LB;temp--)
//                 //{
//                 //     a[temp+1]=a[temp];
//                 // }
//                 // a[LB]=element;

//                 temp = UB;
//                 while (temp >= LB)
//                 {
//                     a[temp + 1] = a[temp];
//                     temp--;
//                 }
//                 a[LB] = element;
//             }
//             printf("\tAltered Array\t");
//             for (int i = 0; i < size; i++)
//                 printf("%d \n", a[i]);
//         }
//         break;

//         case 3:
//         {
//             printf("Enter the position you want to enter the element");
//             scanf("%d", &location);
//             printf("Enter the element you want to enter");
//             scanf("%d", &element);

//             if (UB == size - 1)
//                 printf("Array is full\n");
//             else if (UB < 0)
//             {
//                 if (location > size)
//                     printf("Not a valid location");
//                 else
//                 {
//                     a[location] = element;
//                     UB = location;
//                 }
//             }
//             else
//             {
//                 while (temp > location)
//                 {
//                     a[temp + 1] = a[temp];
//                     temp--;
//                 }
//                 a[location] = element;
//                 UB = UB + 1;
//             }
//             printf("\tAltered Array\t");
//             for (int i = 0; i < size; i++)
//                 printf("%d \n", a[i]);
//         }
//         break;

//         default:
//             printf("Please input a valid option");
//             break;
//         }
//     }
//     default:
//     printf("Enter a valid option\n");
//     break;

//     }
// }