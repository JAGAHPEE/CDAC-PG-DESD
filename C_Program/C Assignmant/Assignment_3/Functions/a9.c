#include <stdio.h>
void transp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp; 
}
int main()
{
    int row, col;
    printf("Enter row and column : ");
    scanf("%d %d", &row, &col);

    int matrix[row][col];
    //Getting Matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("\n Matrix[%d][%d] : ", i, j, matrix[i][j]);
            scanf("%d", &matrix[i][j]);
        }
    }
    // Print the Matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // printf("\nMatrix[%d][%d] : %d",i,j,matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    // Transpose of matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            transp(&matrix[i][j], &matrix[j][i]);
        }
    }

    // Using For Loop

    // for (int i = 0; i < row; i++)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         int temp = matrix[i][j];
    //         matrix[i][j] = matrix[j][i];
    //         matrix[j][i] = temp;
    //     }
    // }

    printf("\n");
    // Display the Matrix
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // printf("\nMatrix[%d][%d] : %d",i,j,matrix[i][j]);
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}