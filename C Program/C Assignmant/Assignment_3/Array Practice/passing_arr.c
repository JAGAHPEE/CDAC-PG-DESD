#include<stdio.h>
void check(int a[5])
{
    for(int i=0;i<5;i++)
    {
        if(a[i]%2==0)
        {
            printf("Even");
        }
        else{
            printf("Odd");
        }
    }
}
int main()
{
    int num,arr[5];
    for(int i=0;i<5;i++)
    {
        scanf("%d ",&arr[i]);
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    check(arr);

}