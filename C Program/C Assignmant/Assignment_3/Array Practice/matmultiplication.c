#include <stdio.h>
#define row1 3
#define col1 4

#define row2 col1
#define col2 3
int main()
{
    int mat1[row1][col1], mat2[row1][col1], mat3[row2][col2];
    printf("Enter Matrix 1\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter Matrix 2\n");
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    for(int i=0;i<row1;i++)
    {
        for (  int j= 0; j < col1; j++)
        {
            printf("%d ",mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<row2;i++)
    {
        for (  int j= 0; j < col2; j++)
        {
            printf("%d ",mat2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            mat3[i][j] = 0;
            for (int k = 0; k < col1; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf("%5d", mat3[i][j]);
        }
        printf("\n");
    }
}