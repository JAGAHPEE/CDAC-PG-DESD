#include<stdio.h>
#include"arithmatic.h"
int main()
{
int a,b;
	printf("Enter the 1st number:");
	scanf("%d",&a);
	printf("\nEnter the 2nd number:");
        scanf("%d",&b);
	printf("Addition: %d\n",add(a,b));
	printf("Multiplication: %d\n",mul(a,b));
	printf("Subtraction: %d\n",sub(a,b));
	printf("Division: %f\n",div(a,b)); 
}
