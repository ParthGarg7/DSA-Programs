// // https://www.geeksforgeeks.org/problems/deletion-and-reverse-in-linked-list/1

// /*
// class Node {
//     int data;
//     Node *next;

//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };
// */
// class Solution
// {
// public:
//     Node *deleteNode(Node *head, int key)
//     {
//         if (head == NULL)
//             return NULL;

//         if (head->next == head)
//         {
//             delete head;
//             return NULL;
//         }

//         Node *last = head;
//         Node *prevlast = head;
//         while (last->next != head)
//         {
//             prevlast = last;
//             last = last->next;
//         }

//         Node *curr = head;
//         Node *prev = NULL;

//         do
//         {
//             if (key == curr->data)
//             {
//                 if (key == head->data)
//                 {
//                     last->next = head->next;
//                     delete head;
//                     head = last->next;
//                     return head;
//                 }

//                 if (key == last->data)
//                 {
//                     prevlast->next = last->next;
//                     delete last;
//                     last = prevlast;
//                     return head;
//                 }

//                 prev->next = curr->next;
//                 delete curr;
//                 return head;
//             }

//             prev = curr;
//             curr = curr->next;

//         } while (curr != head);

//         return head;
//     }
// };