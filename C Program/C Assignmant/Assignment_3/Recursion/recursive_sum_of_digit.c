#include <stdio.h>
int sum(int n,int r)
{
    if (n > 0)
    {
        return (n%r + sum(n/r,r));
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", sum(n,10));
}