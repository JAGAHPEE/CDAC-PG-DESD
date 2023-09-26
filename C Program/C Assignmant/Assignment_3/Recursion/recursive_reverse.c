#include <stdio.h>
int reverse(int n, int r)
{
    if (n == 0)
    {
        return r;
    }
    int l = n % 10;
    r = (r * 10) + l;
    return reverse(n / 10, r);
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", reverse(a, 0));
}