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
int NodeNumber(int node_counter, int num)
{
    int value;
    char ch;

    if (num == 0)
    {

        while (scanf("%d", &value) != 1 || value < 0 || value >= node_counter)
        {
            printf("Enter a valid node number\n");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }
    else
    {

        while (scanf("%d", &value) != 1 || value < 0 || value > node_counter)
        {
            printf("Enter a valid node number\n");
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    return value;
}

void PrintList()
{
    if (head != NULL)
    {
        temp = head;
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    return;
}

int CreateNode(int node_counter)
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
    printf("Enter the value you want to insert in the node %d\n", node_counter);

    new->data = ScanInput();
    new->next = head;

    return node_counter;
}

int Insertion_at_start(int node_counter)
{

    node_counter = CreateNode(node_counter);

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
        // new->next = head;
        head = new;
        tail->next = head;
    }

    return node_counter;
}

int Insertion_at_last(int node_counter)
{
    node_counter = CreateNode(node_counter);

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
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = new;

        // Updating the address in the last node
        tail = temp->next;

        // tail = head;
        // while (tail->next != head)
        //     tail = tail->next;
    }

    return node_counter;
}

int Insertion_at_location(int node_counter)
{
    int count;
    node_counter = CreateNode(node_counter);

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
        count = NodeNumber(node_counter, 0);

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

    return node_counter;
}

int Deletion_at_start(int node_counter)
{
    if (head == NULL)
        printf("There is no node in the list\nCreate a list first\n");
    else
    {
        temp = head;
        head = temp->next;
        tail->next = head;

        free(temp);

        if (node_counter == 1)
            head = NULL;

        node_counter -= 1;
    }

    return node_counter;
}

int Deletion_at_end(int node_counter)
{
    if (head == NULL)
        printf("There is no node in the list\nCreate a list first\n");
    else
    {
        temp = head;
        while (temp->next != tail)
            temp = temp->next;

        free(tail);

        tail = temp;

        if (node_counter > 1)
            tail->next = head;

        if (node_counter == 1)
            head = NULL;

        node_counter -= 1;
    }

    return node_counter;
}

int Deletion_at_location(int node_counter)
{
    if (head == NULL)
        printf("There is no node in the list\nCreate a list first\n");
    else
    {
        printf("Which node data you want to delete?\n");
        int count = NodeNumber(node_counter, 1);

        if (count == 1)
            node_counter = Deletion_at_start(node_counter);
        else if (count == node_counter)
            node_counter = Deletion_at_end(node_counter);
        else
        {
            temp = head;
            new = temp;
            for (int i = 1; i < count; i++)
            {
                new = temp;
                temp = temp->next;
            }

            new->next = temp->next;

            free(temp);

            node_counter -= 1;
        }
    }

    return node_counter;
}

int main()
{
    int choice1, node_counter = 0;
    head = NULL;

    while (1)
    {
        printf("There are currently %d nodes in the list\n", node_counter);
        printf("\tHere is the current list\n\t");

        PrintList();

        printf("\nPress 0 for exit\n");
        printf("Press 1 for insertion at starting\n");
        printf("Press 2 for insertion at end\n");
        printf("Press 3 for insertion at particular location\n");
        printf("Press 4 for deletion at starting\n");
        printf("Press 5 for deletion at end\n");
        printf("Press 6 for deletion at particular location\n");
        choice1 = ScanInput();

        switch (choice1)
        {
        case 0:
        {
            if (head == NULL)
                printf("List is empty\n");

            // for printing the final list
            printf("\n\tThis is the final list\n\t");
            PrintList();

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

            exit(0);
        }
        break;

        case 1:
        {
            node_counter = Insertion_at_start(node_counter);
        }
        break;

        case 2:
        {
            node_counter = Insertion_at_last(node_counter);
        }
        break;

        case 3:
        {
            node_counter = Insertion_at_location(node_counter);
        }
        break;

        case 4:
        {
            node_counter = Deletion_at_start(node_counter);
        }
        break;

        case 5:
        {
            node_counter = Deletion_at_end(node_counter);
        }
        break;

        case 6:
        {
            node_counter = Deletion_at_location(node_counter);
        }
        break;

        default:
        {
            printf("Invalid option\nEnter from the options below\n");
        }
        break;
        }
    }

    return 0;
}