#include<stdio.h>
#define max 10
int main()
{

    int arr[max][max];
    printf("Enter Element: ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(i==j)
            {
                arr[i][j]=1;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1]+ arr[i-1][j];
            }

        }
    }
    for(int i =0;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            printf("%2d ",arr[i][j]);
        }
        printf("\n");
    }
}