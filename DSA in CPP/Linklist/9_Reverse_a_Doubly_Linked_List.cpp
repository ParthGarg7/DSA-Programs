// // https://www.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

// /*
// class Node {
//   public:
//     int data;
//     Node *next;
//     Node *prev;
//     Node(int val) {
//         data = val;
//         next = NULL;
//         prev = NULL;
//     }
// };

// */
// class Solution 
// {
//   public:
//     Node *reverse(Node *head) 
//     {
//         if(head == NULL)
//         return NULL;
    
//         Node* curr = head;
//         while(curr != NULL)
//         {
//             Node* origNext = curr->next;
//             Node* origPrev = curr->prev;   

        
//             curr->next = origPrev;
//             curr->prev = origNext;

//             head = curr;
//             curr = origNext;
//         }
        
//         return head;
        
        
        
//     }
// };