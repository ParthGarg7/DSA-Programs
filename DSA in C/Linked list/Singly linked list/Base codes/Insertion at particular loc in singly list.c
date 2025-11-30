#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice1, choice2, value;

    struct node
    {
        int data;
        struct node *next;
    } *head, *new, *temp, *prev, *tnext;

    head = NULL;

    while (1)
    {
        printf("Do you want to add a note?\n");
        printf("Press 1 for yes\n");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            // allocating memory to new node
            new = (struct node *)malloc(sizeof(struct node));
            new->next = NULL;

            printf("Enter the value you want to insert\n");
            scanf("%d", &value);

            // assigning data in new node
            new->data = value;

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
                    prev = temp;
                    temp = temp->next;
                }

                new->next = temp;
                prev->next = new;
            }
        }
        else
        {
            break;
        }
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