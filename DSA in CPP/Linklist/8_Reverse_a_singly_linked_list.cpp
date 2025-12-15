// // https://www.geeksforgeeks.org/problems/reverse-a-linked-list/1

// /*
// class Node {
//  public:
//     int data ;
//     Node *next ;

//     Node(int x) {
//         data = x ;
//         next = NULL ;
//     }
// };
// */

// class Solution {
//   public:
//     Node* reverseList(Node* head)
//     {
//         Node* prev = NULL, *curr = head , *next = NULL;
        
//         while(curr != NULL)
//         {
//             next = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = next;
//         }
//         return prev;
//     }
// };