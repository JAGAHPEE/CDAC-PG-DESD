// Factorial by recursion
#include<stdio.h>
void swap(int *a, int *b)
{   
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("\nBefore Swap : %d %d",a,b);
    swap(&a,&b);
    printf("\nAfter Swap  : %d %d",a,b);


}