#include<stdio.h>
int main()
{
    int num;
    printf("Enter Value : ");
    scanf("%d",&num);
    int sum=0;

    for(int i=1;i<num;i++)
    {
        if((num%i)==0)
        {
            sum = sum+i;
        }
    }
    if(sum==num)
    {
        printf("Perfact Number");
    }
    else
    {
        printf("Not a Perfact Number");
    }
    
    

}