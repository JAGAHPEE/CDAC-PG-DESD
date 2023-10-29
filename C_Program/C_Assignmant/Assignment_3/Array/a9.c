#include<stdio.h>
int main()
{
    int arr[5],index;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Index to Delete : ");
    scanf("%d",&index);
    for(int i=index;i<5;i++)
    {
        arr[i]=arr[i+1];
    }
    for(int i=0;i<4;i++)
    {
        printf("%d ",arr[i]);
    }
}