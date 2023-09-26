#include <stdio.h>
int main()
{
    int n;
    printf("Enter the Number of Integer:");
    scanf("%d", &n);
    int arr[n];

    int even[10], odd[10];
    int ef = 0, of = 0;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the Integer arr[%d]:", i);
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0)
        {
            even[ef] = arr[i];
            ef++;
        }
        else
        {
            odd[of] = arr[i];
            of++;
        }
    }
    printf("\n");
    printf("Arrray : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < ef; i++)
    {
        printf("\nEven[%d]", i);
        printf("%d", even[i]);
    }
    printf("\n");
    for (int i = 0; i < of; i++)
    {
        printf("\nOdd[%d] :", i);
        printf("%d", odd[i]);
    }
    printf("\n");
}