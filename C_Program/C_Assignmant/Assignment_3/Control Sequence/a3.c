#include<stdio.h>
int main()
{
    int num,sum=0;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {
        if(i%5==0)
        {
            continue;
        }
        else
        {
            sum = sum + i;
        }
    }
    printf("%d",sum);
}