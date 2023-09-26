#include<stdio.h>
int main()
{
    int n;
    printf("Enter the No. of Elements:");
    scanf("%d",&n);
    int digit[n];
    for(int i=0;i<n;i++)
    {
        // scanf("%c",&text[i]);
        scanf("%d",&digit[i]);
    }
    printf("Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",digit[i]);
    }
}