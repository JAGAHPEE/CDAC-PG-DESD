#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n>='a' && n<='z')
    {
        printf("It is lower case");
    }
    else if(n>='A' && n<= 'Z')
    {
        printf("Upper case");
    }
    else if(n>='0'&& n<='9')
    {
        printf("Digit");
    }
    else if(n==' ')
    {
        printf("White Space");
    }
}