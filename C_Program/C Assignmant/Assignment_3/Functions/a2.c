// WAP to get factorial by using Function
#include<stdio.h>
int fact(int a)
{
    int sum=1;
    while (a>0)
    {
       sum =sum*a;
       a--;
    }
    return sum;
    
}
int main()
{
    int num;
    printf("Enter the Number : ");
    scanf("%d",&num);
    printf("Factorial of %d : %d\n",num,fact(num));
}