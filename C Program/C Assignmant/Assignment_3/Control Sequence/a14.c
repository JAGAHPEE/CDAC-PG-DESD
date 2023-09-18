// WAP to print N number of Prime Numbers
#include<stdio.h>
int main()
{
    int num=1;
    int prev=1,new=0;
    int fact;
    scanf("%d",&fact);
    int prime=1;
    int count=0;
    int check =0;

    while(num<fact)
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
            new = num;
            // printf("Prime %d ",num);
            if((new-prev)==1)
            {
                printf("\n%d %d",prev,new);
                // break;
            }
            prev = new;
        }
        num++;
    }
}