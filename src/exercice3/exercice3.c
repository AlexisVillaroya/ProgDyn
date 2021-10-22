#include <stdio.h>
#include <stdlib.h>

void createMatrice(int** mat, int n)
{
    int sizeMat = (n * n);
    mat = (int **)malloc(sizeMat * sizeof(int *));
    for (int i = 0; i < sizeMat; i++) 
        mat[i] = malloc(sizeMat * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            mat[i][j] = 0;
        }
    }
}

void displayMatrice(int** mat, int n)
{
    printf("Les éléments de la matrice sont :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}