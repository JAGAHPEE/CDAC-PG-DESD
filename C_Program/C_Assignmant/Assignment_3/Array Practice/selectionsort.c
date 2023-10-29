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
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
            if(i!=min)
            {
                int temp =arr [i] ;
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
    
}