#include <stdio.h>
#include <stdlib.h>

// basic structure of a single linked list
struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

// for getting positive integer as input
int ScanInput()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid option enter a integer\n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

// for making sure the node number taken is valid
int node_number(int num)
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

int insertion()
{
    head = NULL;
    temp = head;

    // declaring variables used in different section of code
    int count, Node_counter;
    char choice1;

    Node_counter = 0;


    // infinite loop which will break when user wants
    while (1)
    {

        printf("\nThere are currently %d node in the list\n", Node_counter);

        // for printing the current status odf list
        printf("Here is the current list\n");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        // Giving user choice to insert
        printf("\nDo you want to insert a node?\n");
        printf("Press Y/y for YES and N/n for NO\n");

        scanf(" %c", &choice1);

        if (choice1 == 'y' || choice1 == 'Y')
        {
            // allocating memory to new node
            new_node = (struct node *)malloc(sizeof(struct node));

            // if allocation is fail
            if (new_node == NULL)
            {
                printf("Memory is full\ncan not insert\n");
                return 1;
            }

            Node_counter += 1;
            printf("\nnode %d is created\n", Node_counter);

            // assigning data in new node
            printf("Enter the value you want to insert\n");
            new_node->data = ScanInput();
            new_node->next = NULL;

            // creation of new node
            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                printf("After which node you want to insert the new node\n");
                count = node_number(Node_counter);

                temp = head;
                for (int i = 0; i < count - 1; i++)
                    temp = temp->next;

                if (count == 0)
                {
                    new_node->next = head;
                    head = new_node;
                }
                else
                {
                    new_node->next = temp->next;
                    temp->next = new_node;
                }
            }
        }
        else if (choice1 == 'n' || choice1 == 'N')
        {
            break;
        }
        else
        {
            printf("Invalid Input\nEnter again from the options below\n");
        }
    }

    // printing the final list
    printf("\nThis is the final list after insertion\n");
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    printf("This is a Program for deletion at end in the singular linked list\n");
    printf("Let's Create a list first\n");

    insertion();

    temp = head;
    while (temp->next != NULL)
    {
        new_node = temp;
        temp = temp->next;
    }

    free(temp);

    new_node->next = NULL;

    // printing the final list
    printf("\nThe final list after deletion at the end is\n");
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
