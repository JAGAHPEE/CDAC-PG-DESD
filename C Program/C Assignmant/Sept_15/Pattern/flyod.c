#include<stdio.h>
int main()
{
    int n=5,k=1;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++,k++)
        {
            printf("%d ",k);
        }
        printf("\n");
    }
}