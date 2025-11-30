#include <stdio.h>

#define MAX 5

struct Stack
{
   int top;
   int arr[MAX]; 
}s;

int main()
{
    s.top = -1;

    s.arr[++s.top] = 1;
    s.arr[++s.top] = 2;
    s.arr[++s.top] = 3;
    s.arr[++s.top] = 4;
    s.arr[++s.top] = 5;

    for(int i = MAX - 1 ; i >= 0 ; i--)
    {
        printf("%d",s.arr[i]);
    }


    


    return 0;
}