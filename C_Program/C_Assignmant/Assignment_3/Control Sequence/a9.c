#include<stdio.h>
int main()
{
    char opt;
    int result,a,b,subt,mul;
    float div;

    printf("\n Press + for Addition ");
    printf("\n Press - for Subtraction ");
    printf("\n Press * for Multiplication ");
    printf("\n Press / for Division ");
    printf("\n Enter the options : ");

    scanf("%c",&opt);
    printf("\n Enter First Value   : ");
    scanf("%d",&a);

    printf("\n Enter Second Value  : ");
    scanf("%d",&b);

    switch (opt)
    {
    case '+':
        result = a+b;
        printf("\n Sum of %d and %d : %d\n",a,b,result);
        break;
    case '-':
        result = a-b;
        printf("\n Subtraction of %d and %d : %d\n",a,b,result);
        break;
    case '*':
        result = a*b;
        printf("\n Multiplication of %d and %d : %d\n",a,b,result);
        break;
    case '/':
        div  =  (float) a/b;
        printf("\n Division of %d and %d : %.2f \n",a,b,div);
        break;
    default:
        printf("\nIncorrect Options");
        break;
    }

}