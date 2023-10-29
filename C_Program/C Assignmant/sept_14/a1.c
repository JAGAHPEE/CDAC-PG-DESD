#include<stdio.h>
int main()
{
int a;
printf("Enter Value : ");
scanf("%d",&a);
int b = a%2;
if(b==1)
{
    printf("Odd\n");
}
else
{
    printf("Even\n");
}

}
