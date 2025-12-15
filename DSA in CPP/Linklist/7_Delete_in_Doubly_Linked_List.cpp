// // https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

// /* Structure of Node
// class Node {
//   public:
//     int data;
//     Node *next;
//     Node *prev;

//     Node(int val) {
//         data = val;
//         this->next = NULL;
//         this->prev = NULL;
//     }
// };
// */

// class Solution
// {
// public:
//     Node *delPos(Node *head, int x)
//     {
//         if (head == NULL)
//             return NULL;

//         int count = 1;

//         if (count == x)
//         {
//             Node *todel = head->next;
//             head->data = todel->data;
//             head->next = todel->next;
//             if (todel->next != NULL)
//                 todel->next->prev = head;
//             delete todel;
//             return head;
//         }

//         Node *curr = head;
//         while (curr != NULL)
//         {
//             if (count == x)
//             {
//                 curr->prev->next = curr->next;
//                 if (curr->next != NULL)
//                     curr->next->prev = curr->prev;
//                 delete curr;
//                 return head;
//             }
//             curr = curr->next;
//             count++;
//         }
//     }
// };