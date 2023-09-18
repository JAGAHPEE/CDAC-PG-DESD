// WAP to print nPr and nCr using Function
#include<stdio.h>
int fact(int n)
{
    if(n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
int main()
{
    int n,r,nCr,nPr;
    printf("Enter the Value : ");
    scanf("%d %d",&n,&r);
    if(n>r)
    {
    nCr  = fact(n)/(fact(r)*fact(n-r));
    nPr  = fact(n)/fact(n-r);
    }

    printf("%dP%d : %d\n",n,r,nPr);
    printf("%dC%d : %d\n",n,r,nCr);

}