// WAP to check the input number in the given list and use break statement
#include<stdio.h>
#define N 10
int main()
{
    int num;
    int array[N] = {10,2,45,12,78,12,40,14,25,11};
    printf("Enter the number to Check in the List : ");
    scanf("%d",&num);
    int f=0;
    int index=0;
    while(index<N)
    {
        if(num==array[index])
        {
            f=1;
            break;
        }
        else{
            index++;
        }
    }

if(f==1)
{
    printf("\n Number found\n");
}
else{
    printf("\n Number Not Found\n");
}
}