#include <stdio.h>
int main()
{
    int n1, n2, n3;
    printf("\nEnter the Total Elements in the 1st Array: ");
    scanf("%d", &n1);
    printf("\nEnter the Total Elements in the 2nd Array: ");
    scanf("%d", &n2);
    int a1[n1], a2[n2];
    for (int i = 0; i < n1; i++)
    {
        printf("\nEnter Arrays Element a1[%d]:", i);
        scanf("%d", &a1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        printf("\nEnter Arrays Element a2[%d]:", i);
        scanf("%d", &a2[i]);
    }
    n3 = n1 + n2;
    int a3[n3];
    for (int i = 0; i < n1; i++)
    {
        a3[i] = a1[i];
    }
    int j = 0;
    for (int i = n1; i < n1 + n2; i++, j++)
    {
        printf("%d ", i);
        a3[i] = a2[j];
    }
    printf("\n");
    for (int i = 0; i < n3; i++)
    {
        printf("%d ", a3[i]);
    }
}