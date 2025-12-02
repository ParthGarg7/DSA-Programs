// // https://www.geeksforgeeks.org/problems/occurence-of-an-integer-in-a-linked-list/1

// /*
//   Node is defined as
// struct node
// {
//     int data;
//     struct node* next;

//     node(int x){
//         data = x;
//         next = NULL;
//     }
// }*head;
// */

// #include <iostream>

// class Solution
// {
// public:
//     int count(struct Node *head, int key)
//     {
//         int count = 0;
//         Node *temp = head;
//         if (temp == NULL)
//             return 0;
//         while (temp != NULL)
//         {
//             if (key == temp->data)
//                 count += 1;
//             temp = temp->next;
//         }
//         return count;
//     }
// };