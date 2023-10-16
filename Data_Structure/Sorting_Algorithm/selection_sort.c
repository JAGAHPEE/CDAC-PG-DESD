#include <stdio.h>
int main()
{
    int arr[10];
    int n;
    scanf("%d", &n);
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = 0;
    int count =0;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
                count++;
            }
            if (i != min)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            printf("\n");
            for (int k= 0; k < n; k++)
            {
                printf("%d", arr[k]);
            }
            printf(": %d ",i);
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\niterations: %d",count);
}