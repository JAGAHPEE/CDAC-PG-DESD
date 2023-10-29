#include<stdio.h>
int main()
{
    int num1,sum,temp;
    printf("Enter First Value : ");
    scanf("%d",&num1);
    temp = num1;
    int num2=num1;
    sum=0;

    while (num1 >0)
    {
        temp = num1%10;
        sum = sum + temp;
        num1 = num1/10;
    }
    printf("Sum of Digits of %d : %d\n",num2,sum);   
}