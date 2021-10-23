#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>

/**
 * @brief Find minimum between two or more integer variables
 * 
 * @param args Total number of integers
 * @param ... List of integer variables to find minimum
 * @return Minimum among all integers passed
 */

int min(int args, ...)
{
    int i, min, cur;
    va_list valist;
    va_start(valist, args);

    min = INT_MAX;

    for (i = 0; i < args; i++)
    {
        cur = va_arg(valist, int);
        if (min > cur)
            min = cur;
    }

    va_end(valist);

    return min;
}

/**
 * @brief Crée une matrice de taille n * n (0 et 1 aléatoire)
 * 
 * @param mat array pointer
 * @param n size of the array 
 * @return int*
 */

int *createMat(int *mat, int n)
{
    mat = (int *)malloc(sizeof(int[n][n]));

    if (!mat)
    {
        printf("Échec de l'allocation\n");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            mat[(i * n) + j] = rand() % 2;
        }

    return mat;
}
/**
 * @brief Affiche la matrice (* et " ")
 * 
 * @param mat array pointer
 * @param n size of the array
 */

void displayMat(int *mat, int n)
{
    printf("Les éléments de la matrice sont :\n");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[(i * n) + j] == 1)
                printf("%c ", '*');
            else
                printf("%c", ' ');
        }
        printf("\n");
    }
}

/**
 * @brief Recherche le plus grand carré de 0
 * 
 * @param mat 
 * @param n 
 */

void findPgcb(int *mat, int n)
{
    int *cacheMat = (int *)malloc(sizeof(int[n][n]));
    for (int r = 0; r < n; r++)
        memcpy(&cacheMat[r], &mat[r], sizeof(int[n][n]));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if(cacheMat[(i * n) + j] == 1)
                cacheMat[(i * n) + j] = 0;
            else{
                if(i == 0 || j == 0)
                    cacheMat[(i * n) + j] = 1;
                else
                    cacheMat[(i * n) +j] = 1 + min(3, cacheMat[((i-1) * n) + (j - 1)], 
                    cacheMat[(i * n) + (j - 1)], cacheMat[((i-1) * n) + (j - 1)]);
            }
        }

    printf("#################\n");
    //displayMat(cacheMat, 5);
     for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", cacheMat[(i * n) + j]);
        }
        printf("\n");
    }
}