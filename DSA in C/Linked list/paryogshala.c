#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
} *head , *new;


int main()
{
    new = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to enter\n");
    scanf("%d",&new->data);
    new->next = head;
    head = new;
    return 0;
}