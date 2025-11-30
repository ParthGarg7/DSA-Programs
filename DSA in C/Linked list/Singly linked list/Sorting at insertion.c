#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new, *temp, *ptr;

int input()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input\nEnter a valid integer\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

int Create_node(int counter)
{
    new = (struct node *)malloc(sizeof(struct node));
    counter += 1;

    printf("\nNODE %d created\n", counter);
    printf("Enter the data you want to enter in the node\n");

    new->data = input();
    new->next = NULL;

    return counter;
}

void Print_list()
{
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return;
}

void Sort_list()
{
    temp = head;
    while (temp != NULL)
    {
        if (new->data > temp->data)
        {
            ptr = temp;
            temp = temp->next;
        }
        else
            break;
    }

    if (temp == NULL)
        ptr->next = new;
    else if (temp == head)
    {
        new->next = head;
        head = new;
    }
    else
    {
        ptr->next = new;
        new->next = temp;
    }
}

void Free_list()
{
    temp = head;
    while (temp != NULL)
    {
        new = temp->next;
        free(temp);
        temp = new;
    }
    return;
}

int main()
{
    int size_choice, size, node_counter = 0;
    char choice;

    printf("This is a program of singly linked list\n");
    printf("To automatically compare data and adjust nodes in ascending order\n");

    while (1)
    {
        printf("\nPress 0 for exit\n");
        printf("Press 1 for fixed size linked list\n");
        printf("Press 2 for dynamic size linked list\n");
        size_choice = input();

        switch (size_choice)
        {
        case 0:
        {
            exit(0);
        }
        break;

        case 1:
        {
            head = NULL;
            temp = head;

            node_counter = 0;

            printf("Enter the Size of the list\n");
            size = input();

            for (int i = 0; i < size; i++)
            {
                printf("\n\tThis is the current list\n\t");
                Print_list();

                node_counter = Create_node(node_counter);

                if (new == NULL)
                {
                    printf("NO FREE MEMORY\n");
                    return 1;
                }
                else if (head == NULL)
                {
                    head = new;
                    temp = head;
                }
                else
                {
                    Sort_list();
                }
            }

            printf("\n\tThis is the final list\n\t");
            Print_list();

            Free_list();
        }
        break;

        case 2:
        {
            head = NULL;
            temp = head;

            node_counter = 0;

            while (1)
            {

                printf("\n\tThis is the current list\n\t");
                Print_list();

                printf("\nDo you want enter a node?\n");
                printf("Press y/Y for YES and N/n for NO\n");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y')
                {
                    node_counter = Create_node(node_counter);

                    if (new == NULL)
                    {
                        printf("NO FREE MEMORY\n");
                        return 1;
                    }
                    else if (head == NULL)
                    {
                        head = new;
                        temp = head;
                    }
                    else
                    {
                        Sort_list();
                    }
                }
                else if (choice == 'n' || choice == 'N')
                {
                    break;
                }
                else
                    printf("Invalid choice\nEnter form the options below\n");
            }

            printf("\n\tThis is the final list\n\t");
            Print_list();

            Free_list();
        }
        break;

        default:
            printf("Invalid option\nEnter form the option below\n");
            break;
        }
    }

    return 0;
}
