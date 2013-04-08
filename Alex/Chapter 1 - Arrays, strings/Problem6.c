#include <stdlib.h>
#include <stdio.h>

void initializeMatrix(int* mat, int n)
{
     int i, j;
     for (i = 0; i < n; i++)
     {
         for (j = 0; j < n; j++)
         {
             mat[i*n + j] = i * n + j + 1;
         }
     }
}

void printMatrix(int* mat, int n)
{
     printf("\n");
     int i, j;
     for (i = 0; i < n; i++)
     {
         for (j = 0; j < n; j++)
         {
             printf("%d ", mat[i*n + j]);
         }
         printf("\n");
     }
}

void transpose(int* mat, int n)
{
     int i = 0;
     int j = 0;
     int temp = 0;
     for (i = 0; i < n; i++)    
     {
         for (j = i + 1; j < n; j++)
         {
             temp = mat[i * n + j];
             mat[i*n + j] = mat[j*n + i];
             mat[j*n + i] = temp;
         }
     }
}
// interchange rows
void rotateLeft(int* mat, int n)
{
     int i = 0;
     int j = 0;
     int temp = 0;
     for (i = 0; i < n / 2; i++)
         for (j = 0; j < n ; j++)
         {
             temp = mat[(n - i - 1) * n + j];
             mat[(n - i - 1)  * n + j] = mat[i * n + j];
             mat[i * n + j] = temp;
         }
     printMatrix(mat, n);
}

// interchange columns
void rotateRight(int* mat, int n)
{
     int i = 0;
     int j = 0;
     int pivot = n / 2;
     int temp = 0;
     for (i = 0; i < pivot; i++)
         for (j = 0; j < n; j++)
         {
             temp = mat[j * n + i];
             mat[j * n + i] = mat[j * n + (n - i - 1)];
             mat[j * n + (n - i - 1)] = temp;
         }
     printMatrix(mat, n);
}

void rotateMatrix90Degrees(int* mat, int n)
{
    transpose(mat, n);
    //printMatrix(mat, n);
    rotateRight(mat, n);
}

int main()
{
    int N = 4;
    int* matrix = (int*)malloc(sizeof(int) * N * N);
    initializeMatrix(matrix, N);
    printMatrix(matrix, N);
    rotateMatrix90Degrees(matrix, N);
    //rotateLeft(matrix, N);
    //printMatrix(matrix, N);
    system("pause");
    return 0;
}
