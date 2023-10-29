#include<stdio.h>
#define N 50
int linears(int a[],int n, int item)
{
    int i=0;
    while (i<n && a[i]!=item)
    {
        i++;
    }
    if(i<n)
    {
        return i;
    }
    else
    {
        return -1;
    }
    
}
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
    printf("Enter item to serach: ");
    scanf("%d",&item);
    int index = linears(arr,n,item);
    if(index ==-1)
        printf("Item niot found");
    else
        printf("Item %d is at index %d",item,index);

}