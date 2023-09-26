#include<stdio.h>
#define N 50
int main()
{
    int num,n,i,arr[N],item;
    printf("Enter total Numbers: ");
    scanf("%d",&n);
    printf("Enter Numbers: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int arr2[n];
    for(i=0;i<n;i++)
    {
        arr2[i]=arr[i];
    }
    int arev[n];
    for(int i=n-1;i>=0;i--)
    {
        arev[i]=arr[n-i-1];
    }
    printf("\nInput Array array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    printf("\nReverse array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",arev[i]);
    }
    printf("\nCopied array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d,",arr2[i]);
    }
    return 0;
}