#include <stdio.h>
#include <stdlib.h>

// creation of structure of singular linked list
struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

// for taking a integer value as input
int ScanInput()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input. Please enter a integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

// Program for insertion at end in the linked list
int main()
{
    // declaring variables used in different section of code
    int Node_Counter;
    char choice1;

    Node_Counter = 0;

    head = NULL;
    temp = head;

    printf("Hi this is a program of Insertion of node in the ending of the singular linked list\n\n");

    // infinite loop which will break when user wants
    while (1)
    {
        printf("There are currently %d node in the list\n", Node_Counter);

        // for printing the current status of the list
        printf("\tHere is the current list\n\t");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        // Giving user choice to insert
        printf("\nDo you want to insert a node?\n");
        printf("Press y/Y for YES and N/n for NO\n");
        scanf(" %c", &choice1);

        if (choice1 == 'Y' || choice1 == 'y')
        {
            // Allocating memory to the new node
            new_node = (struct node *)malloc(sizeof(struct node));

            //Checking of memory allocation
            if (new_node == NULL)
            {
                printf("Memory is full can't insert\nThank you");
                return 1;
            }

            // taking the data from the user
            printf("Enter the data you want to enter in the node\n");

            // assigning values in the node
            new_node->data = ScanInput();
            new_node->next = NULL;

            Node_Counter += 1;

            printf("\n\nnode %d is created\n", Node_Counter);

            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                // Traverse to the end of the list
                temp = head;
                while (temp->next != NULL) // method 2
                    temp = temp->next;     // temp->next = newnode;
                                           // temp = newnode

                // Link the new node to the end of the list
                temp->next = new_node;
            }
        }
        else if (choice1 == 'N' || choice1 == 'n')
            break;
        else
            printf("Invalid option\nEnter From the option below\n");
    }

    // for printing the linked list
    printf("\n\tHere is the final list\n\t");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free the allocated memory for each node
    temp = head;
    while (temp != NULL)
    {
        new_node = temp->next;
        free(temp);
        temp = new_node;
    }

    return 0;
}
