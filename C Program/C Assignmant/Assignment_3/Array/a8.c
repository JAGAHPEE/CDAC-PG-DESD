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

    int index,ip;
    printf("\nEnter the Index to Insert: ");
    scanf("%d",&index);
    printf("\nEnter the Number: ");
    scanf("%d",&ip);
    arr[index]=ip;
    for(int i=0;i<n;i++)
    {
        printf("%d,",arr[i]);
    }
    return 0;
}