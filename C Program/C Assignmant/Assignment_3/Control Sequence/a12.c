// WAP to print N number of Prime Numbers
#include<stdio.h>
int main()
{
    int num=1;
    int fact;
    scanf("%d",&fact);
    int prime=1;
    int count=0;
    int check =0;
    while(num != check)
    {
        count=0;
        for(int i=1;i<num;i++)
        {
            if((num%i) == 0)
            {
                count ++;

            }
        }
        if(count<2)
        {
            check++;
            printf("%d ",num);
            if(check==10)
            {
                break;
            }
        }
        num++;
    }
}