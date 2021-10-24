#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdarg.h>
#include "exercice3.h"

/**
 * @brief Trouve le minimum entre deux ou plusieurs nombre
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
 * @brief Create a Mat object
 * 
 * @param mat 
 * @param n 
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
 * @brief 
 * 
 * @param mat 
 * @param n 
 */

void displayMat(int *mat, int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (mat[(i * n) + j] == 1)
                printf("%c ", '*');
            else if(mat[(i * n) + j] == 0)
                printf("%c ", ' ');
            else
                printf("%c ", '#');
        }
        printf("\n");
    }
}

/**
 * @brief 
 * 
 * @param mat 
 * @param n 
 * @return Pos 
 */

Pos findPgcb(int *mat, int n)
{
    int *cacheMat = (int *)malloc(sizeof(int[n][n]));
    Pos position;
    position.size = 0;
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
                    cacheMat[(i * n) + j] = 1 + min(3, cacheMat[((i-1) * n) + (j - 1)], 
                    cacheMat[(i * n) + (j - 1)], cacheMat[((i-1) * n) + j]);
            }
            if(cacheMat[(i * n) + j] > position.size){
                position.size = cacheMat[(i * n) + j];
                position.x = i; 
                position.y = j;
            }    
        }

    return position;
}

/**
 * @brief 
 * 
 * @param mat 
 * @param n 
 * @param p 
 */

void displayMatPgcb(int *mat, int n, Pos p){
    for (int i = (p.x - p.size + 1); i <=  p.x; i++){
        for (int j = (p.y - p.size + 1); j <= p.y; j++){
            mat[(n*i) + j] = 2;
        }
    }    
    displayMat(mat, n);  
}