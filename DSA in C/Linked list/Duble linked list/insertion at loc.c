#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *back;
    int data;
    struct node *next;
} *head, *new_node, *temp;

int ScanIntegerInput()
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

int main()
{
    head = NULL;
    temp = head;

    int count, node_counter = 0;
    char choice1;

    while (1)
    {
        printf("Do you want to insert a node?\n");
        printf("Press y/Y for YES and n/N for NO\n");

        scanf(" %c", &choice1);

        if (choice1 == 'y' || choice1 == 'Y')
        {
            new_node = (struct node *)malloc(sizeof(struct node));

            if (new_node == NULL)
            {
                printf("NO FREE MEMORY\n");
                return 1;
            }

            printf("Enter the value you want to insert in the node\n");
            node_counter += 1;

            new_node->data = ScanIntegerInput();
            new_node->back = NULL;
            new_node->next = NULL;

            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                printf("After which node you want to insert the node?\n");
                count = NodeNumber(node_counter);

                if (count == 0)
                {
                    new_node->next = head;
                    head->back = new_node;
                    head = new_node;
                }
                else
                {
                    temp = head;
                    for (int i = 0; i < count - 1; i++)
                        temp = temp->next;

                    new_node->next = temp->next;
                    new_node->back = temp;
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
            printf("Invalid input\nEnter form the option below\n");
        }
    }

    printf("\n\tThis is the final list\n\t");
    temp = head;
    new_node = head;
    while (temp != NULL)
    {
        new_node = temp;
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n\tThis is the final list\n\t");
    while (new_node != NULL)
    {
        printf("%d ", new_node->data);
        new_node = new_node->back;
    }

    temp = head;
    while (temp != NULL)
    {
        new_node = temp->next;
        free(temp);
        temp = new_node;
    }
}