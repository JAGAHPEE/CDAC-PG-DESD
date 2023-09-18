#include <stdio.h>
int fact(int a)
{
    if (a == 1)
    {
        return 1;
    }
    else
    {
        return a * fact(a - 1);
    }
}
int main()
{
    int n, r;
    printf("Enter n and r : ");
    scanf("%d %d", &n, &r);
    int result, sum;
    if (n < 0 || r < 0 || n < r)
    {
        printf("\nInvalid Input");
    }
    else
    {
        result = fact(n) / fact(n - r);
    }
    printf("\nResult : %d", result);
}