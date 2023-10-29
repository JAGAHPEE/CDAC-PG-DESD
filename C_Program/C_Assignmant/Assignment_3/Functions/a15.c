#include <stdio.h>
char menu();

int sum(int, int);
int subt(int, int);
int mul(int, int);
float div(int, int);
int fact(int);
int main()
{
    int num1, num2;
    char opt = menu();
    if (opt == 'F')
    {
        printf("\nEnter the Value : ");
        scanf("%d", &num1);
    }
    else if(opt == '+' ||opt == '/'||opt == '*'||opt == '-')
    {
        printf("\nEnter 1st Value : ");
        scanf("%d", &num1);
        printf("\nEnter 2nd Value : ");
        scanf("%d", &num2);
    }
    else{
        printf("\nInvalid Output");
    }
    switch (opt)
    {
    case '+':
        printf("\n Addition of       %d and %d : %d\n",num1,num2,sum(num1,num2));
        break;
    case '-':
        printf("\n Subtraction of    %d and %d : %d\n",num1,num2,subt(num1,num2));
        break;
    case '*':
        printf("\n Multiplication of %d and %d : %d\n",num1,num2,mul(num1,num2));
        break;
    case '/':
        printf("\n Division of       %d and %d : %.2f\n",num1,num2,div(num1,num2));
        break;
    case 'F':
        printf("\n Factorial of      %d        : %d\n",num1,fact(num1));
        break;
    }
}

char menu()
{
    printf("Simple Calculator");
    printf("\nPress + for Addition");
    printf("\nPress - for Subtraction");
    printf("\nPress / for Division");
    printf("\nPress * for Multiplication");
    printf("\nPress F for Factorial");
    printf("\nEnter your Options        : ");
    char opt;
    scanf("%c", &opt);
    return opt;
}
int sum(int a, int b)
{
    int result = a + b;
    return result;
}
int subt(int a, int b)
{
    int result = a - b;
    return result;
}
int mul(int a, int b)
{
    int result = a * b;
    return result;
}
float div(int a, int b)
{
    float result = (float)a / b;
    return result;
}

int fact(int a)
{
    if(a==1)
    {
        return 1;
    }
    else
    {
        return a*fact(a-1);
    }
}