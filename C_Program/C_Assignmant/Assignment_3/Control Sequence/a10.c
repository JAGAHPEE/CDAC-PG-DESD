// WAP to print Pattern
//       1
//      212
//     32123
//    4321234
//   543212345
//  65432123456

#include<stdio.h>
int main()
{
    int n,count=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>i;j--)
        {
            printf(" ");
        }
        int k=0;
        for(k=0;k<=i;k++)
        {
            printf("%d",count);
            count--;
        }
        int temp = count +2;
        count = count + k+1;
        for(k=0;k<i;k++)
        {
            printf("%d",temp);
            temp++;
        }
        printf("\n");
    }

}