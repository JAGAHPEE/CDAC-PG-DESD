// WAP to check pallindrome (check reverse is equal)
#include<stdio.h>
int main()
{
    int num1,sum=0,temp,num2;
    printf("Enter the Number to check Pallidrome : ");
    scanf("%d",&num1);
    num2=num1;
    while (num2>0)
    {
        temp = num2%10;
        sum = sum*10 + temp;
        num2/=10;
    }
    // printf("%d",sum);
    if(num1 == sum)
    {
        printf("\nNumber is Pallidrome");
    }
    else
    {
        printf("\nNumber is not Pallidrome");
    }
    

}