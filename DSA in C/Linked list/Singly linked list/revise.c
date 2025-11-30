#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head, *temp, *new_node;

// Function to make insure the integer input is valid
int ScanInput()
{
    int data;
    char ch;

    while (scanf("%d", &data) != 1)
    {
        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }

    while ((ch = getchar()) != '\n' && ch != EOF)
        ;

    return data;
}

int main()
{
    char choice;

    head = NULL;

    while (1)
    {
        // Giving choice to the user
        printf("Do you to enter a node?\n");
        printf("Press Y/y for YES and N/n for NO\n");
        scanf("%c", &choice);

        if (choice == 'y' || choice == 'Y')
        {

            // Allocating memory to the new node in the list
            new_node = (struct node *)malloc(sizeof(struct node));

            // Checking of dynamic memory allocation
            if (new_node == NULL)
            {
                printf("NO FREE SPACE\n");
                return 1;
            }

            // Taking the data from user
            printf("Enter the data you want to enter in the node\n");
            new_node->data = ScanInput();
            new_node->next = NULL;

            if (head == NULL)
            {
                head = new_node;
                temp = head;
            }
            else
            {
                temp->next = new_node;
                temp = new_node;
            }


        }// ending of the if for choice of none
        else if (choice == 'N' || choice == 'n')
        {
            break;  // for breaking of the loop
        }
        else
        {
            printf("Invalid input\nEnter fromthe option below\n");
        }

    }// end of the infinite will loop

    //for printing the final list
    temp = head;
    while(temp != NULL)
    {
      printf("%d ",temp->data);
      temp = temp->next;
    }

    // for free the memory of the list
    temp = head;
    while (temp != NULL)
    {
        new_node = temp;
        temp = temp->next;
        free(new_node);
        
    }
    

    return 0;
}
