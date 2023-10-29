#include<stdio.h>
int main()
{
    int i,j;
    scanf("%d %d",&i,&j);
    if(i<=40 && j<= 40)
    {
        printf("\nBoth less than = 40");
    }
    else{
        printf("\nBoth are not less than = 40");
    }
    if(i == 20 || j==20)
    {
        printf("\nAtleat one is 20");
    }
    else
    {
        printf("Both are not 20");
    }

    ((i<40) || (j<40)) ? printf("\nC Both less than = 40"):printf("\nC Both are not less than = 40");
    ((i==20) || (j==20)) ? printf("\nC Atleat one is 20"):printf("\nC Both are not 20");
    }