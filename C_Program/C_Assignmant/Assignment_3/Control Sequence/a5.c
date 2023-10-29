//
#include<stdio.h>
int main()
{
    int num,sum=0;
        
    scanf("%d",&num);
    int i=1;
    while(i<=num)
    {
        if(i%2!=0)
        {
            sum = sum +i;       
        }
        i++;
    }
    printf("%d",sum);
}