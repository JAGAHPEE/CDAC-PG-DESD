#include<stdio.h>
#include"function.h"
void menu(char *opt)
{
    printf("\n");
    printf("----Simple Calculator----");
    printf("\nPress + for Addition");
    printf("\nPress - for Subtraction");
    printf("\nPress / for Division");
    printf("\nPress * for Multiplication");
    printf("\nPress F for Factorial");
    printf("\nEnter your Options        : ");
    char ch;
    ch = getchar();
    *opt = ch;
    printf("\n");
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