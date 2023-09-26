#include <stdio.h>
int main()
{
    int arr[50], n, i;
    printf("Enter Arrray total number: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1; i < n; i++)
    {
        int k = arr[i];
        int j;
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
        {
            arr[j + 1] = arr[j];
        }
        arr[j+1]=k;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}