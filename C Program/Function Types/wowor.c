// Without Argument and Without Return Type
#include<stdio.h>
void function();

int main()
{
    function();

}

void function()
{
    int a,b;
    int Sub;
    printf("Enter the Values : ");
    scanf("%d %d",&a,&b);
    printf("\nSubtraction of two number %d & %d is %d\n",a,b,a-b);
}