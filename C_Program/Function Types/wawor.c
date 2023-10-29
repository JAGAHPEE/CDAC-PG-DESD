// With Argument and Without Return Type 
#include<stdio.h>
void funct(int,int);
int main()
{
    int a,b;
    printf("Enter Value 1 and 2 : ");
    scanf("%d %d",&a,&b);
    funct(a,b);

}
void funct(int a,int b)
{
    int sum = a+b;
    printf("Sum of %d and %d : %d\n",a,b,sum);
}