//Published by :- Sandesh Kale
// @github     :- JAGAHPEE
#include<stdio.h>
int main()
{
    int num;
    printf("Enter Value : ");
    scanf("%d",&num);
    int sum=0;

    for(int i=1;i<num+1;i++)
    {
        sum = sum+i;
    }
    printf("Sum of %d Natural No. : %d",num,sum);
    

}