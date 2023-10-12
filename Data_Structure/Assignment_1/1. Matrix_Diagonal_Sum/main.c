#include <stdio.h>
#define MAX 3
int summ(int a[MAX][MAX])
{
    int s=0;
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            printf("%d ",a[i][j]);
            if(i>j)
            {
                s = s+ a[i][j];
            }
        }
        printf("\n");
    }
    return s;
}
int main()
{
    int a[MAX][MAX];
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Sum : %d",summ(a));
}