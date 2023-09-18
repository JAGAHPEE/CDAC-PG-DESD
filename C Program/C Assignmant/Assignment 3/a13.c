// WAP to get sum of series 1/1! + 2/2! + 3/3! up to 7th place
#include <stdio.h>
int fact(int a)
{
    int r = 1;
    while (a > 0)
    {
        r = r * a;
        a--;
    }
    return r;
}
int main()
{
    int num;
    float sum = 0.0;
    float count = 0;
    for (int i = 1; i <= 7; i++)
    {
        count++;
        float temp = fact(i);
        sum = sum + (count / temp);
    }
    printf("%.2f", sum);
}