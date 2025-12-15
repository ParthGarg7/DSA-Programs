// // https://www.geeksforgeeks.org/problems/circular-linked-list/1

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

// /* Should return true if linked list is circular, else false */
// class Solution {
//   public:
//     bool isCircular(Node *head)
//     {
//         Node * fast = head;
//         Node * slow = head;
//         while(fast != NULL && fast->next != NULL)
//         {
//             if(head == NULL)
//             return NULL;
            
//             fast = fast->next->next;
//             slow = slow->next;
//             if(slow == fast)
//             return true;
//         }
//         return false;
        
//     }
// };