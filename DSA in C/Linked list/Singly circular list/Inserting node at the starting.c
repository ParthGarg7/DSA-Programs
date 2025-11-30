#include <stdio.h>
#include <stdlib.h>

// Basic structure of a singular list
struct node
{
    int data;
    struct node *next;
} *head, *new, *temp, *ptemp;

// User defined function for taking valid integer input
int ScanInput()
{
    int value;
    char ch;

    // Checking of input enter by the user
    while (scanf("%d", &value) != 1)
    {
        printf("Invalid Input\nYou have entered a character\nEnter a integer: \n");

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    // For clearing the memory buffer when a character is enter with a integer
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

int main()
{
    head = NULL;

    // Variables used in different parts of program
    int node_counter = 0;
    char choice1;

    printf("This is a program of insertion of a new node at the starting of the circular singly list\n");

    // Infintie loop so can user can insert data as much time they want
    while (1)
    {

        // for printing the curent list
        printf("\n\tThis is the current list\n\t");
        if (head != NULL)
        {
            ptemp = head;
            do
            {
                printf("%d ", ptemp->data);
                ptemp = ptemp->next;
            } while (ptemp != head);
        }

        // Asking user if they want to insert the node
        printf("\nDo you want to insert a node\n");
        printf("Press y/Y for YES and n/N for NO\n");
        scanf(" %c", &choice1);

        // If user choice is yes
        if (choice1 == 'Y' || choice1 == 'y')
        {
            // Allocation memory to a new node
            new = (struct node *)malloc(sizeof(struct node));

            // Checking of memory allocation to new node
            if (new == NULL)
            {
                printf("MEMORY IS FULL\n");
                return 1; // for exiting the program if no memory is free
            }

            node_counter += 1;
            printf("Node %d created\n", node_counter);

            // Taking the value form user and assigning in node
            printf("Enter the value you want to insert in the node %d\n",node_counter);

            new->data = ScanInput();
            new->next = NULL;

            // Creation of 1st node in the list
            if (head == NULL)
            {
                head = new;
                temp = head;
                temp->next = head;
            }
            else
            {
                new->next = head;
                head = new;
                temp->next = head; // updating the address in the last node
            }
        }
        else if (choice1 == 'N' || choice1 == 'n')
        {
            // If no list is created
            if (head == NULL)
                printf("No list is created\n");

            break;
        }
        else
        {
            printf("Invalid Option\nEnter form the option below\n");
        }
    }

    // for printing the final list
    printf("\n\tThis is the final list\n\t");
    if (head != NULL)
    {
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    // for freeing the memory of the list
    if (head != NULL)
    {
        temp = head;
        do
        {
            new = temp->next;
            free(temp);
            temp = new;
        } while (temp != head);
    }

    return 0;
}