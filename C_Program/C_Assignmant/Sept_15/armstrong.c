// Armstrong Number 
#include <stdio.h>
int pwr(int,int);
int main()
{
    int num, f = 0;
    scanf("%d", &num);
    int temp = num;
    int digit = 0,i=0;
    while(temp>0)
    {
        temp = temp/10;
        digit++;

    }
    // printf("Digit %d",digit);
    int a;
    temp = num;
    int sum=0,t;
    while(temp>0)
    {
        t = temp%10;
        sum = sum + pwr(t,digit);
        temp/=10;

    }
    printf("%d",sum);
    // printf("%d",pwr(a,digit));
    
}
int pwr(int a,int dig)
{
    int sum=1;
    while(dig>0)
    {
        sum  = sum*a;
        // printf("%d\n",sum);
        dig--;
    }
    return sum;
}