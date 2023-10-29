#include<stdio.h>
int main()
{
    int opt,num1,num2,sum,mul,subt;
    float div;
    char c;
    while(1)
    {
        printf(" -- -- -- -- -- -- -- -- -- \n");
        printf("--SIMPLE CALCULATOR--");
        
        printf("\n Press + for Addition");
        printf("\n Press - for Subtraction");
        printf("\n Press / for Division");
        printf("\n Press * for Multiplication\n");
        printf(" -- -- -- -- -- -- -- -- -- \n");

        printf("Enter Options: ");
        // scanf("%d",&opt);
        scanf("%c",&c);
        printf("\nEnter First Value: ");
        scanf("%d",&num1);
        printf("\nEnter Second Value: ");
        scanf("%d",&num2);
        // switch (opt)
        switch (c)
        {
        case '+':
            sum = num1+num2;
            printf("Addition of %d and %d : %d\n",num1,num2,sum);
            break;
        case '-':
            subt = num1-num2;
            printf("Subtraction of %d and %d : %d\n",num1,num2,subt);
            break;
        case '/':
            div = (float) num1/num2;
            printf("Division of %d and %d : %.2f\n",num1,num2,div);
            break;
        case '*':
            mul = num1*num2;
            printf("Multiplication of %d and %d : %d\n",num1,num2,sum);
            break;
        default:
            printf("Incorrect options\n");
            break;
        }
    }

}