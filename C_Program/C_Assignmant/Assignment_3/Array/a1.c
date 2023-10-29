#include<stdio.h>
int main()
{
    char name[7];
    for(int i=0;i<7;i++)
    {
        // scanf("%c",&name[i]);
       scanf("%c",&name[i]);

    }
    for(int i=0;i<7;i++)
    {
        printf("%c",name[i]);

    }
    printf("\nSize of Array %d",sizeof(name));
}