// WAP to get factorial and gcd using recursion
#include<stdio.h>
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else{ 
        return n*fact(n-1);
    }
}
int gcd(int n1,int n2)
{
    if(n2!=0)
    {
        return gcd(n2,n1%n2);
    }
    else
    {
        return n1;
    }
}
int main()
{
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int result = fact(n1);
    printf("\nFactorial of n1 %d",result);
    // result = fact(n2);
    // printf("\n%d",result);
    result = gcd(n1,n2);
    printf("\n%d",result);

}