/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include <stdio.h>
#define size 100
void merge(int arr[], int, int, int);
void sort(int arr[], int, int);

int main()
{
    int n;
    int arr[size];
    printf("Enter the Size of the Array: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        sort(arr, low, mid);
        sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
    /*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
}
void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low, index = low;
    int temp[size];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[index] = arr[i];
            i++;
        }
        else
        {
            temp[index] = arr[j];
            j++;
        }
        index++;
    }
    if(i>mid)
    {
        while (j<=high)
        {
            temp[index] = arr[j];
            j++;
            index++;
        }   
    }
    else
    {
        while (i<=mid)
        {
            temp[index] = arr[i];
            i++;
            index++;
        }
    }
    for ( k = low; k < index; k++)
    {
        arr[k] = temp[k];
    }
    
}