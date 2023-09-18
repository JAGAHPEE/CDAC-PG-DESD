//  WAP to checl whether a number is Armstrong or not
#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    int sum=0;
    int num1=num;
    while (num>0)
    {
        int t = num%10;
        sum = sum + (t*t*t);    
        num/=10;

    }
    if(num1 == sum)
    {
        printf("Number is Armstronge Number");
    }
    else
    {
        printf("Number is not an Armstronge Number");
    }
    // printf("%d",sum);
    
}