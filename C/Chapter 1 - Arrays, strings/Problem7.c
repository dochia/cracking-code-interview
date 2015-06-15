#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    //int* matrix = new int[3][4];
    const int M = 3;
    const int N = 4;
    int matrix[3][4] = { 
                     {1, 2, 3, 4}, 
                     {5, 1, 0, 3}, 
                     {1, 4, 5,7}};
    int i = 0, j = 0;
    int value = 0;
    bool rows[M];
    for (i = 0; i < M; i++)
         rows[i] = false;
    bool columns[N];
    for (i = 0; i < N; i++)
        columns[i] = false;
    for (i = 0; i < M; i++)
    {
         for (j = 0; j < N; j++)
         {
             if (matrix[i][j] == value)
             {
                           rows[i] = true;
                           columns[j] = true;
             }    
         }
    }
    /*for (i = 0; i < M; i++)
         printf("%d ", rows[i]);
    for (i = 0; i < N; i++)
        printf("%d ", columns[i]);*/
    for (i = 0; i < M; i++)
        for (j = 0; j < N; j++)
        {
            if (rows[i]  || columns[j])
               matrix[i][j] = value;
        }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}
