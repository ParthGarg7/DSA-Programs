#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
} *root, *new_node, *ptr;

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

int main()
{
    root = NULL;
    ptr = NULL;

    char choice;

    while (1)
    {
        printf("Do you want to insert in tree?\n");
        printf("Press y/Y for YES and n/N for NO\n");
        scanf(" %c", &choice);
        if (choice == 'y' || choice == 'Y')
        {
            new_node = (struct node *)malloc(sizeof(struct node));

            if (new_node == NULL)
            {
                printf("NO FREE SPACE\n");
                return;
            }

            printf("Enter the data you want to enter in the Tree\n");
            new_node->data = ScanIntegerInput();
            new_node->left = NULL;
            new_node->right = NULL;

            if (root == NULL)
            {
                root = new_node;
            }
            else
            {
                 if (new_node->data >= root->data )
                 {
                    root->right = new_node;
                 }
                 else
                 {
                  
                 }
                 
            }
            

        }
        else if (choice == 'n' || choice == 'N')
        {
            break;
        }
        else
        {
            printf("Invalid input\n");
        }
    }

    return 0;
}