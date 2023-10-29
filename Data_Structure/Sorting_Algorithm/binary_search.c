/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include<stdio.h>
int main()
{
    int n;
    int arr[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int item;
    scanf("%d",&item);
    int low=0,mid,high=n-1,flag =0;
    int count =0 ;
    while (low<=high)
    {
        count++;
        mid = (low+high)/2;
        if(item == arr[mid])
        {
            flag =1;
            break;
        }
        else if(item>arr[mid])
        {
            low  = mid+1;
        }
        else
        {
            high = mid-1;
        }
        // printf("\nCount:%d",count);
    }
    if(flag==1)
    {
        printf("Element Found");
    }
    else
    {
        printf("Element not Found");
    }
    
}
/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/