#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>b && b<c)
    {
        if (a>c)
        {
            printf("A is bigger");
        }
        else
        {
            printf("C is greater");
        }
        
    }
    else if(b>a && b>c)
    {
        printf("b is greater");
    }
    else
    {
        printf("C is greater");
    }
}