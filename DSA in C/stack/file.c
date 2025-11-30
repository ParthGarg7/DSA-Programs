#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum stack size

// Stack structure
struct Stack
{
    int top;
    int arr[MAX];
};


// Main function
int main()
{
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    display(&s);

    printf("Top element is: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    display(&s);

    return 0;
}

// Function to initialize the stack
void initStack(struct Stack *s)
{
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

// Function to push an element onto the stack
void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow! Cannot pop.\n");
        return -1;
    }
    return s->arr[s->top--];
}

// Function to get the top element of the stack
int peek(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return s->arr[s->top];
}

// Function to display the stack
void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}


