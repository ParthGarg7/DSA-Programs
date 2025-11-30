#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

int user_input()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input\nEnter a integer: ");

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

    int node_counter = 0, value;
    char choice1;

    printf("This is a program of insertion of a new at the starting of the circular singly list\n");

    while (1)
    {

        printf("\n\tThis is the current list\n\t");
        temp = head;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }

        printf("\nDo you want to insert a node\n");
        printf("Press Y/y for YES and N/n for NO\n");
        scanf(" %c", &choice1);

        if (choice1 == 'y' || choice1 == 'Y')
        {

            new_node = (struct node *)malloc(sizeof(struct node));
            node_counter += 1;

            printf("Node %d created\n", node_counter);

            printf("\nEnter the Value you want to insert in node %d: \n", node_counter);
            value = user_input();

            new_node->data = value;
            new_node->next = NULL;

            if (new_node == NULL)
            {
                printf("NO FREE MEMORY\n");
                return 1;
            }
            else if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                new_node->next = head;
                head = new_node;
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

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head;

    printf("\n\tThis is the final list\n\t");
    temp = head;
    if (temp != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    else
    {
        printf("No list is created and no operation is performed\n");
    }

    temp = head;
    if (temp != NULL)
    {
        do
        {
            new_node = temp->next;
            free(temp);
            temp = new_node;
        } while (temp != head);
    }

    return 0;
}
