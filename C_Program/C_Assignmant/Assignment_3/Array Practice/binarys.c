#include<stdio.h>
int binaryc(int arr[],int size,int item)
{
    int low=0,up=size-1,mid;
    while (low<=up)
    {
        mid = low+up/2;
        if(item > arr[mid])
        {
            low = mid+1;
        }
        else if(item < arr[mid])
        {
            up = mid -1;
        }
        else
        {
            return mid;
        }
    }
        return -1;
    

}
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
    printf("Enter item to serach: ");
    scanf("%d",&item);
    int index = binaryc(arr,n,item);
    if(index ==-1)
        printf("Item not found");
    else
        printf("Item %d is at index %d",item,index);

    
}