// WAP to print su, of digits of the Number
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the Number : ");
    scanf("%d",&num);
    int num1 = num;
    int sum=0;
    while (num>0)
    {
        int t = num%10;
        sum = sum+t;
        num/=10; 
    }
    printf("\n Sum of Digits of the Number %d : %d\n", num1,sum);

}