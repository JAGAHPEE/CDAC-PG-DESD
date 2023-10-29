#include<stdio.h>
int main()
{
int a;
int max;
int b;
printf("Enter First Value : ");
scanf("%d",&a);
printf("\nEnter Second Value : ");
scanf("%d",&b);
// Conditional Operator
max = (a>b)? a:b;

    printf("\nMax b/w %d & %d is = %d\n",a,b,max);

}
