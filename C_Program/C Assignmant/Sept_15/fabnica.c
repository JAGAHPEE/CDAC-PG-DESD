#include<stdio.h>

int main()
{
    int a=0,b=1,result,n;
    scanf("%d",&n);
    int count=0;
    while(count < n)
    {
        result = a+b;
        a=b;
        printf("%d ",result);
        b=result;
        count++;
    }
    // printf("%d",result);s
}