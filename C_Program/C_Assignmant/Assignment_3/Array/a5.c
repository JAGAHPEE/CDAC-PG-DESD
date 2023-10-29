#include<stdio.h>
int main()
{
    int n;
    printf("Enter the No. of Elements:");
    scanf("%d",&n);
    int digit[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        // scanf("%c",&text[i]);
        scanf("%d",&digit[i]);
        sum=sum+digit[i];
    }
    printf("Sum of Array: %d",sum);
    printf("\nSum of Array: %.2f",(float)sum/n);

}