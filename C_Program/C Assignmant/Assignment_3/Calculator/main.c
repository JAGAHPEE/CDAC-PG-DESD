#include <stdio.h>
#include "function.h"
void main()
{
    int num1, num2;
    char opt;
    while (1)
    {
        menu(&opt);
        if (opt == 'F')
        {
            printf("\nEnter the Value : ");
            scanf("%d", &num1);
        }
        else if (opt == '+' || opt == '/' || opt == '*' || opt == '-')
        {
            printf("\nEnter 1st Value : ");
            scanf("%d", &num1);
            printf("\nEnter 2nd Value : ");
            scanf("%d", &num2);
        }
        else
        {
            printf("\nInvalid Output");
        }
        switch (opt)
        {
        case '+':
            printf("\n Addition of       %d and %d : %d\n", num1, num2, sum(num1, num2));
            break;
        case '-':
            printf("\n Subtraction of    %d and %d : %d\n", num1, num2, subt(num1, num2));
            break;
        case '*':
            printf("\n Multiplication of %d and %d : %d\n", num1, num2, mul(num1, num2));
            break;
        case '/':
            printf("\n Division of       %d and %d : %.2f\n", num1, num2, div(num1, num2));
            break;
        case 'F':
            printf("\n Factorial of      %d        : %d\n", num1, fact(num1));
            break;
        }
        
    }
}
