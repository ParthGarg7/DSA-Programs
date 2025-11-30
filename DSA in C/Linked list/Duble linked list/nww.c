#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *new, *tail;

int main()
{
    int choice1, node_counter = 0;
    head = NULL;

    while (1)
    {
        printf("There are currently %d nodes in the list\n", node_counter);
        printf("\tHere is the current list\n\t");

        if (head != NULL)
        {
            temp = head;
            do
            {
                printf("%d ", temp->data);
                temp = temp->next;
            } while (temp != head);
        }

        printf("\nPress 0 for exit\n");
        printf("Press 1 for insertion at starting\n");
        printf("Press 2 for insertion at end\n");
        printf("Press 3 for insertion at particular location\n");
        printf("Press 4 for deletion at starting\n");
        printf("Press 5 for deletion at end\n");
        printf("Press 6 for deletion at particular location\n");

        scanf(" %c", &choice1);

        switch (choice1)
        {
        case 0:
        {
            if (head == NULL)
                printf("List is empty\n");

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

            exit(0);
        }
        break;

        case 1:
        {
            new = (struct node *)malloc(sizeof(struct node));

            if (new == NULL)
            {
                printf("MEMORY IS FULL\n");
                return 1;
            }

            node_counter += 1;
            printf("Node %d created\n", node_counter);

            printf("Enter the value you want to insert in the node %d\n", node_counter);

            scanf("%d", &new->data);
            new->next = head;

            if (head == NULL)
            {
                head = new;
                temp = head;
                temp->next = head;
                tail = head;
            }
            else
            {
                head = new;
                tail->next = head;
            }
        }
        break;

        case 2:
        {
            new = (struct node *)malloc(sizeof(struct node));

            if (new == NULL)
            {
                printf("MEMORY IS FULL\n");
                return 1;
            }

            node_counter += 1;
            printf("Node %d created\n", node_counter);

            printf("Enter the value you want to insert in the node %d\n", node_counter);

            scanf("%d", &new->data);
            new->next = head;

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
                tail = temp->next;
            }
        }
        break;

        case 3:
        {
            int count;

            new = (struct node *)malloc(sizeof(struct node));

            if (new == NULL)
            {
                printf("MEMORY IS FULL\n");
                return 1;
            }

            node_counter += 1;
            printf("Node %d created\n", node_counter);

            printf("Enter the value you want to insert in the node %d\n", node_counter);

            scanf("%d", &new->data);
            new->next = head;

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
                scanf("%d", &count);

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
        break;

        case 4:
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
        }
        break;

        case 5:
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
        }
        break;

        case 6:
        {
            if (head == NULL)
                printf("There is no node in the list\nCreate a list first\n");
            else
            {
                int count;
                printf("Which node data you want to delete?\n");
                scanf("%d", &count);

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