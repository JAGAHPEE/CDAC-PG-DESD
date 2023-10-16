#include <stdio.h>
int partition(int arr[], int start, int end)
{
    int i = start;
    int pindex = start-1;
    int pivot = arr[end];
    for (i = start; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            pindex++;
            int temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
        }
    }
    return pindex;
}
void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pindex = partition(arr, start,end);
        quick_sort(arr, start, pindex - 1);
        quick_sort(arr, pindex + 1, end);
    }
}
int main()
{
    int arr[100];
    int n;
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    quick_sort(arr, 0, n - 1);
    printf("Sorted Array");
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
}