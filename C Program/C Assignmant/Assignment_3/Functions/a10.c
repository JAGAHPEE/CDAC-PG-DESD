#include<stdio.h>
int main()
{
    int num,bi;
    scanf("%d",&num);
    int sum=0;
    int num1=num;
    while(num>0)
    {
        int temp = num%2;
        sum = sum*10 + temp;
        num/=2;
    }
    printf("%d",sum);
    int rev=sum;
    int sum1=0;
    while(sum>0)
    {
        int temp = sum%10;
        sum1 = sum1+temp;
        sum1*=10;
        sum/=10; 
    }
    if(num1%2!=0)
    {
        sum1/=10;
    }
    printf("\n%d",sum1);
}