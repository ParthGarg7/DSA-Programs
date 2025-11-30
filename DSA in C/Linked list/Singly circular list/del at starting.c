#include <stdio.h>
#include <stdlib.h>

// basic structure of a singular linked list
struct node
{
    int data;
    struct node *next;
} *head, *temp, *new, *tail;

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

// for making sure the node number entered is valid
int NodeNumber(int num)
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value < 0 || value >= num)
    {
        printf("Enter a valid node number\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

int Insertion()
{

    head = NULL;
    temp = head;

    // Variable declaration which are used in different part of code
    int node_counter = 0, count;
    char choice1;

    // Infinite loop which will continue till user want to add value
    while (1)
    {

        printf("Ther are currently %d nodes in the list\n", node_counter);
        printf("\tHere is the current list\n\t");

        if (temp != NULL)
        {
            temp = head;
            do
            {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != head);
        }

        // Asking for user choice
        printf("\nDo you want to insert a node?\n");
        printf("Press y/Y for YES and N/n for NO\n");
        scanf(" %c", &choice1);

        // if the () is empty then it will give a expected expression error
        if (choice1 == 'y' || choice1 == 'Y')
        {
            // Allocation memory to the new node
            new = (struct node *)malloc(sizeof(struct node));

            // Checking of memory allocation
            if (new == NULL)
            {
                printf("NO SPACE IS AVAILABLE\n");
                return 1;
            }

            node_counter += 1;
            printf("Node %d created\n", node_counter);

            // Taking the value form user and assigning in node
            printf("Enter the value you want to insert in the node %d\n", node_counter);

            new->data = ScanInput();
            new->next = NULL;

            // Creation of 1st node in the list
            if (head == NULL)
            {
                head = new;
                temp = head;
                temp->next = head;
                tail = head;
            }
            else
            {
                printf("After which node you want to insert the data ?\nFor insertion in starting press 0\n");
                count = NodeNumber(node_counter);

                // Insertion at starting of the list
                if (count == 0)
                {
                    new->next = head;
                    head = new;
                    tail->next = head;
                }
                else
                {
                    temp = head;
                    for (int i = 0; i < count - 1; i++)
                        temp = temp->next;

                    new->next = temp->next;
                    temp->next = new;

                    tail = head;
                    while (tail->next != head)
                        tail = tail->next;
                }
            }
        }
        // for breaking the loop
        else if (choice1 == 'n' || choice1 == 'N')
        {
            // if no node is created
            if (head == NULL)
                printf("No list is created and no data is entered\n");

            break;
        }
        // for making sure that loop only breaks when n/N is entered or its ASCII value is entered
        else
        {
            printf("Invalid Option.\nEnter from the options below\n");
        }
    }

    printf("\n\tThis is the final list after insertion\n\t");
    if (head != NULL)
    {
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    return node_counter;
}

int main()
{
    int node_counter;
    char choice1;

    printf("This is a program of deletion at starting in singly circular linked list\n");

    printf("Lets Create the list first\n");

    node_counter = Insertion();

    if (node_counter != 0)
    {

        while (1)
        {
            printf("\nThere are currently %d nodes in the list\n", node_counter);
            printf("\tHere is the current list\n\t");

            if (temp != NULL)
            {
                temp = head;
                do
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                } while (temp != head);
            }

            printf("\nDo you want to del the node at starting\n");
            printf("Press y/Y for YES and N/n for NO\n");
            scanf(" %c", &choice1);

            if ((choice1 == 'y' || choice1 == 'Y') && (node_counter > 0))
            {
                node_counter -= 1;

                temp = head->next;
                free(head);
                head = temp;
                tail->next = head;
            }
            // for breaking the loop
            else if (choice1 == 'n' || choice1 == 'N' || node_counter == 0)
                break;

            // for making sure that loop only breaks when n/N is entered or its ASCII value is entered
            else
                printf("Invalid Option.\nEnter from the options below\n");
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
    }
    else
        printf("There is no node in the list\n");

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