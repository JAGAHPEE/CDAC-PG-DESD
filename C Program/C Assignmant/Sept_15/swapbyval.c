// Factorial by recursion
#include<stdio.h>
void swap(int a, int b)
{
    int temp;
    temp = a;
    a=b;
    b=temp;
    printf("\n%d %d",a,b);
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("\n%d %d",a,b);
    swap(a,b);


}