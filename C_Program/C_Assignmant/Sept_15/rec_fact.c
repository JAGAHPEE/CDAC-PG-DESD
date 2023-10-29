// Factorial by recursion
#include<stdio.h>
int fact(int a)
{
    if(a==1)
    {
        return 1;
    }
    else
    {
        return fact(a-1)*a;
    }
    
}
int main()
{
    int a=0,b=1,result,n;
    scanf("%d",&n);
    printf("%d",fact(n));

}