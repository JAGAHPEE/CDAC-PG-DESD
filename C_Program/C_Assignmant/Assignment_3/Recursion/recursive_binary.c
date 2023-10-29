#include<stdio.h>
#include<math.h>
int bin_to_dec(int b,int e)
{
    if(b==0)
    {
        return 0;
    }
    int ld = b%10;
    int d = ld * pow(2,e);
    return d+bin_to_dec(b/10,e+1);
}
int main()
{
    int a;
    scanf("%d",&a);
    int dec = bin_to_dec(a,0);
    printf("%d",dec);
}