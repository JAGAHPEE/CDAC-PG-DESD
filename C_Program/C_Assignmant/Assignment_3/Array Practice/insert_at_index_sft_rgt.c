#include <stdio.h>
#define N 50
int main()
{
    int num, n, i, arr[N];
    printf("Enter total Numbers: ");
    scanf("%d", &n);
    printf("Enter Numbers: ");
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index;
    printf("Enter the index no. to add value: ");
    scanf("%d", &index);
    int item;
    scanf("%d", &item);
    for (i = n - 2; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    printf("\n%d\n", i);
    arr[i+1] = item;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}