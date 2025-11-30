// // #include <stdio.h>
// // int main()
// // {
// //     int array[21] = {1, 2, 3, 45, 5, 3};

// //     int array2[5];

// //     int i;

// //     printf("enter 5 numbers \n");

// //     for  (i = 1; i <= 5; i++)
// //     {
// //         scanf("%d",&array2[i]);
// //     }

// //     scanf("%d", &array2[0]);

// //     scanf("%d", &array2[1]);

// //     scanf("%d", &array2[2]);

// //     scanf("%d", &array2[3]);

// //     scanf("%d", &array2[4]);
// // }

// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// } *head, *newnode, *temp;

// int main()
// {
//     int value;
//     char ans;

//     head = NULL;
//     newnode = (struct node *)(malloc(sizeof(struct node)));
//     if (newnode == NULL)
//     {
//         printf("Storage is full");
//     }
//     else
//     {
//         printf("Do you want a new node? (Y for yes and N for no): ");
//         scanf(" %c", &ans);

//         printf("Enter the number you want to insert\n");
//         scanf("%d", &value);

//         while (ans == 'Y' && newnode != NULL)
//         {
//             if (head == NULL)
//             {
//                 head = newnode;
//                 newnode->data = value;
//                 newnode->next = NULL;
//                 temp = head;
//             }
//             else
//             {
//                 temp->next = newnode;
//                 newnode->data = value;
//                 newnode->next = NULL;
//                 temp = newnode;
//             }
//         }
//     }

//     temp = head;
//     while (temp != NULL)
//     {
//         printf("%d", head->data);
//         temp = temp->next;
//     }
// }

// #include <stdio.h>
// #include <conio.h>

// int main()
// {
//     printf("hi");
//     getch();
// }

// C:\Users\Garg Family\3D Objects\Programming\DSA\DSA in C\Array\array.c