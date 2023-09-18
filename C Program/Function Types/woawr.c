// Without Argument with Return type
#include<stdio.h>
float function();
int main()
{
    printf("Division of two numbers is %.2f",function());
}
float function()
{
    int a,b;
    float div;
    printf("Enter the Values : ");
    scanf("%d %d",&a,&b);
    div =(float) a/b;
    return div;
}