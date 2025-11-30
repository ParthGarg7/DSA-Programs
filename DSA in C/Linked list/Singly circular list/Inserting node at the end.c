#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *new ,*ptemp;

int user_input()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input.\nEnter a integer: ");

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

    int value, node_counter = 0;
    char choice1;

    printf("This is a program of insertion at end in singly circular list\n");

    while (1)
    {
        printf("\tHere is the current list\n\t");
        ptemp = head;
        if (temp != NULL)
        {
            do
            {
                printf("%d ", ptemp->data);
                ptemp = ptemp->next;
            } while (ptemp != head);
        }

        printf("\nDo you want Insert a node\n");
        printf("Press y/Y for Yes\nPress n/N for No\n");
        scanf(" %c", &choice1);

        if (choice1 == 'y' || choice1 == 'Y')
        {
            new = (struct node *)malloc(sizeof(struct node));
            node_counter++;

            printf("\nEnter the value you want to insert in the node\n");
            value = user_input();

            new->data = value;
            new->next = head;

            printf("node %d created\n", node_counter);

            if (new == NULL)
            {
                printf("No memory is available\n");
                return 1;
            }
            else if (head == NULL)
            {
                head = new;
                temp = head;
                new->next = head;
            }
            else
            {
                // while (temp->next != head)
                //     temp = temp->next;         // use this if do not want to use a printing pointer

                temp->next = new;
                temp = new;
            }
        }
        else if (choice1 == 'n' || choice1 == 'N')
            break;
        else
        {
            printf("\nSelect form the options below\n");
        }
    }

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
        printf("Program is exited without creation of any list\n");
    }

    temp = head;
    if (temp != NULL)
    {
        do
        {
            new = temp->next;
            free(temp);
            temp = new;
        } while (temp != head);
    }

    return 0;
}