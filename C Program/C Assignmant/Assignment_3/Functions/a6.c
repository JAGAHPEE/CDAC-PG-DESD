
// WAP to invert the bit no. of an integer n starting from position p leaving the other unchange#include<stdio.h>
unsigned int invert(unsigned int n,int p,int b)
{
    unsigned int mask = ((1<<b)-1)<<p;
    return n^mask;
}
int main()
{
    unsigned int num,pos,bitv;
    scanf("%u",&num);
    scanf("%u",&pos);
    scanf("%u",&bitv);

    unsigned int result = invert(num,pos,bitv);
    printf("%d %d : %u",num,pos,result);
}