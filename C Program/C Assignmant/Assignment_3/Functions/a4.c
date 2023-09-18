#include<stdio.h>
unsigned int rotate(int num,int pos)
{
    return (num>>pos);
}
int main()
{
    unsigned int num,pos;
    scanf("%u %u",&num,&pos);
    printf("%d %d",num,pos);
    unsigned int s = rotate(num,pos);
    printf("\n%u",s);
}