#include<stdio.h>
int main()
{

    int i,j,n;
    scanf("%d",&n);
    int arr[n];
    for(j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
    for(i=1;i<n;i++)
    {
        int k=arr[i];
        for(j=i-1;j>=0 && k<arr[j];j--)
        {
            arr[j+1] = arr[j];
        }
        arr[j+1] = k;
    }
    for(j=0;j<n;j++)
    {
        printf("%d",arr[j]);
    }
}