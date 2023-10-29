#include<stdio.h>
int main()
{
    int num1,num2;
    printf("Enter First Value : ");
    scanf("%d",&num1);
    printf("\nEnter Second Value : ");
    scanf("%d",&num2);
    int sum=0;
    for(int i=num1;i<=num2;i++)
    {
        sum = sum+i;
    }
    
    printf("\nSum of Numbers from %d & %d : %d\n",num1,num2,sum);
}