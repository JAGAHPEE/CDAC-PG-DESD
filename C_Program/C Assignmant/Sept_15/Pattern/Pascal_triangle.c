
#include<stdio.h>
int main()
{   int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int k=n;k>i;k--)
        {
            printf(" ");
        }
        int num=1;
        for(int j=1;j<=i;j++)
        {
            printf( " %d",num);
            num = num*(i-j)/j;

        }
        printf("\n");
       
    }
}
