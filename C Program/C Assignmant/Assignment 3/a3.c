// WAP to swap numbers by using Pointers
#include<stdio.h>
void swap(int *p1,int *p2)
{
    int temp = *p1;
    *p1=*p2;
    *p2=temp;
}
int main()
{
    int num1,num2;
    printf("Enter the Num1 and Num2 : ");
    scanf("%d %d",&num1,&num2);
    printf("\nBefore Swap Num1 : %d | Num2 : %d",num1,num2);
    swap(&num1,&num2);
    printf("\nAfter Swap Num1  : %d | Num2 : %d",num1,num2);

}