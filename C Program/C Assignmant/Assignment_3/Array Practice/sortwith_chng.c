#include<stdio.h>
int main()
{
    int arr[50],n,i;
    printf("Enter Arrray total number: ");
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&arr[i]);
    }
    int num;
    printf("Enter the Element to Insert : ");
    scanf("%d",&num);
    for(i=n-2;num<arr[i] && i>=0 ;i--)
    {
        arr[i+1]= arr[i];
    }
    arr[i+1]=num;
    for(int j=0;j<n;j++)
    {
        printf("%d ",arr[j]);
    }
}