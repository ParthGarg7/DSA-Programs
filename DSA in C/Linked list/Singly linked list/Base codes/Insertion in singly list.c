#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new, *temp, *tnext, *previous;

int main()
{
    head = NULL;

    int choice1, value, choice2;

    while (1)
    {

        printf("Press 0 for exit\n");
        printf("Press 1 for insertion at end\n");
        printf("Press 2 for insertion at beginning\n");
        printf("Press 3 for insertion at particular location\n");

        scanf("%d", &choice1);

        switch (choice1)
        {

        case 1:
        {
            new = (struct node *)malloc(sizeof(struct node));

            printf("Enter the value you want to insert in the list\n");
            scanf("%d", &value);

            new->data = value;
            new->next = NULL;

            if (head == NULL)
            {
                head = new;
                temp = head;
            }
            else
            {
                temp->next = new;
                temp = new;
            }
        }
        break;

        case 2:
        {
            new = (struct node *)malloc(sizeof(struct node));

            printf("Enter the value you want to insert in the list\n");
            scanf("%d", &value);

            new->data = value;
            new->next = NULL;

            if (head == NULL)
            {
                head = new;
                temp = head;
            }
            else
            {
                new->next = head;
                head = new;
            }
        }
        break;

        case 3:
        {
            new = (struct node *)malloc(sizeof(struct node));

            printf("Enter the value you want to insert in the list\n");
            scanf("%d", &value);

            new->data = value;
            new->next = NULL;

            if (head == NULL)
            {
                head = new;
                temp = head;
            }
            else
            {
                printf("\nAfter which node you want to Insert the data?\n");
                scanf("%d", &choice2);

                temp = head;
                for (int i = 0; i < choice2; i++)
                {
                    previous = temp;
                    temp = temp->next;
                }

                new->next = temp;
                previous->next = new;
            }
        }
        break;

        default:
        {
            if(choice1 != 0)
            printf("Invalid option\nEnter again\n");
        }

        break;
        }

        if (choice1 == 0)
            break;
    }

    // printing the final list
    printf("\nThis is the final list\n");
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
        tnext = temp->next;
        free(temp);
        temp = tnext;
    }

    return 0;
}