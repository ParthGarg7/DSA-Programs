#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *new_node, *temp;

int NodeCounter = 0;

int ScanInput()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1)
    {
        printf("Invalid input Enter a valid integer: \n");
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return value;
}

void PrintList()
{

    printf("There are currently %d node in the list\n", counter);
    printf("Here is the current list\n\t");

    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    int choice1, node_counter, list_size;

    node_counter = 0;

    head = NULL;

    while (1)
    {

        printf("This is the program of linked list\n");
        printf("Press 0 for exiting the program\n");
        printf("Press 1 for fixed size linked list\n");
        printf("Press 2 for dynamic size linked list\n");

        choice1 = scan();

        if (choice1 == 0)
        {
            list_end:
            if (head == NULL)
            {
                printf("No list is created and no operation is performed\n");
                printf("So sad to see that you don't use any operations\n");
            }
            
            exit(0);
        }
        else if (choice1 == 1)
        {
            printf("Enter the size of the list\n");
            list_size = scan();

            if(list_size == 0)
            {
               goto list_end;
            }

            for (int i = 0; i < list_size; i++)
            {
                print_list(node_counter);
            }
        }
        else if (choice1 == 2)
        {
        }
        else
        {
            printf("\e[1;1H\e[2J");  
            printf("Invalid Input select from the option below\n\n");
        }
    }

    return 0;
}