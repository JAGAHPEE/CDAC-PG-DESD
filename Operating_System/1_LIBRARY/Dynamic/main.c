#include<stdio.h>
#include"libarithmatic.h"
int main()
{
	int a,b,sum,subb;
	read_value(&a,&b);
	add(a,b,&sum);
	minus(a,b,&subb);
	printf("Addition of %d and %d: %d\n",a,b,sum);
	printf("Subtraction of %d and %d : %d \n",a,b,subb);
	return 0;
}
