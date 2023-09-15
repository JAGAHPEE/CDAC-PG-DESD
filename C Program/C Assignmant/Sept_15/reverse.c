#include<stdio.h>
int main()
{
    int num,r,rev=0;
    scanf("%d",&num);
    int temp=num;
    while (temp>0)
    {
        rev*=10;
        r = temp%10;
        rev = rev+r;
        temp/=10;
        
    }
    printf("%d",rev);
    
    
}