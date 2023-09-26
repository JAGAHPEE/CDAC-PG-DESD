#include<stdio.h>
int reverse(int n,int r)
{
    if(n==0)
    {
        return r;
    }
    int t = n%10;
    int d = r*10 + t;
    return d+reverse(n/10,r); 
}
int main()
{
    int a;
    scanf("%d",&a);
    int num = reverse(a,0);
    if(num==a)
    {
        printf("Number is Pallindrome");
    }
    else{
        printf("Number is not Pallindrome");
    }
}