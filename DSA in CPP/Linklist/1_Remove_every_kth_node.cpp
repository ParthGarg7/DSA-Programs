// // https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

// /* Link list Node

// struct Node
// {
//     int data;
//     struct Node* next;

//     Node(int x){
//         data = x;
//         next = NULL;
//     }

// };
// */

// /*You are required to complete this method*/

// /* Function to get the middle of the linked list*/
// /*K will always be in range */
// class Solution
// {
// public:
//     Node *deleteK(Node *head, int k)
//     {
//         int count = 0;
//         Node *temp = head;
//         while (temp != NULL)
//         {
//             count++;
//             if ((count + 1) == k)
//             {
//                 if (temp->next == NULL && temp->next == NULL)
//                     return head;
//                 temp->next = temp->next->next;
//                 count = 0;
//             }
//             temp = temp->next;
//         }
//         return head;
//     }
// };