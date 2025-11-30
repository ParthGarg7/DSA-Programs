#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice1, value;

    struct node
    {
        struct node * back;
        int data;
        struct node *next;

    } *head, *new_node, *temp, *tnext;

    head = NULL;

    while (1)
    {
        printf("Do you want to add a note?\n");
        printf("Press 1 for yes\n");
        scanf("%d", &choice1);
        if (choice1 == 1)
        {
            // allocating memory to new node
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->next = NULL;
            new_node->back = NULL;

            printf("Enter the value you want to insert\n");
            scanf("%d", &value);

            // assigning data in new node
            new_node->data = value;

            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                new_node->next = head;
                head->back = new_node;
                head = new_node;
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