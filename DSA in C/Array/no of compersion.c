#include <stdio.h>
#include <stdlib.h>

int scan()
{
    int value;
    char ch;

    while (scanf("%d", &value) != 1 || value <= 0)
    {
        printf("Invalid input. Please enter a positive integer: ");
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    return value;
}

int main()
{

    int number, choice, pass_no, total_comparison;

    printf("This is an program to tell the number of comparisons in a array after the bubble sort\n");
    printf("How many elements you want in the array\n");

    number = scan();

    while (1)
    {
        printf("As the array have %d elements \nSo the number of passes of bubble sort is %d\n", number, number - 1);

        printf("Enter your choice\n");
        printf("Press 1 for knowing the total number of comparison done\n");
        printf("Press 2 for knowing the total number of comparison till a particular pass\n");
        printf("Press 3 for knowing the total number of comparison happened in a particular pass\n");
        printf("Press 4 for changing the number of the elements in the array\n");
        printf("Press 5 for exit\n");

        choice = scan();

        switch (choice)
        {

        case 1:
            total_comparison = number * (number - 1) / 2;
            printf("The total number of the comparisons which will take place is %d\n", total_comparison);
            break;

        case 2:
        {
            printf("Enter the pass number\n");
            pass_no = scan();
            total_comparison = number * pass_no - (pass_no * (pass_no + 1) / 2);
            printf("The total comparison done till the %d pass is %d\n", pass_no, total_comparison);
        }
        break;

        case 3:
        {
            printf("Enter the pass number\n");
            pass_no = scan();
            total_comparison = number - pass_no;
            printf("The total comparison done in the %d pass is %d\n", pass_no, total_comparison);
        }
        break;

        case 4:
            printf("How many elements you want in the array\n");
            number = scan();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}