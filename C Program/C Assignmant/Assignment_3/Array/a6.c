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
    for(int i=0;i<n;i++)
    {
        int xch = 0;
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr [j] ;
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xch++;
            }
        }
            if(xch ==0)
            {
                break;
            }
    }
    printf("\n");
    printf("\nLargest :  %d",arr[n-1]);
    printf("\nSmallest :  %d",arr[0]);
    printf("\nSecond Largest :  %d",arr[n-2]);
    printf("\nSeond Smallest :  %d",arr[1]);
    
}