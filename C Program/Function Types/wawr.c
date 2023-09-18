// With Argument and With Return Type
#include<stdio.h>
int function(int , int);

int main()
{
    int a,b,product;
    printf("Enter the Values : ");
    scanf("%d %d",&a,&b);
    printf("Product of %d and %d is %d\n",a,b,function(a,b));
}
int function(int a, int b)
{
    int sum = a*b;
    return sum;
}