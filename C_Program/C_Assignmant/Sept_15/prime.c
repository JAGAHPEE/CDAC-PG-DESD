#include <stdio.h>
int main()
{
    int num, f = 0;
    scanf("%d", &num);
    
    for( int i=2;i<num;i++)
    {
        if((num%i)!=0)
        {
            f=1;
            break;
        }
    }
    if (f == 0)
    {
        printf("Prime");
    }
    else
    {
        printf("not Prime");
    }
}