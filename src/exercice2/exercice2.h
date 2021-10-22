#include <stdlib.h>

#define SIZE_MAX 100
typedef struct
{
    int c;
    int w;
    double ratio;

} Object;

Object* knapsack(Object obj[], int n, int W);
void descendingSort(Object obj[], size_t n);



