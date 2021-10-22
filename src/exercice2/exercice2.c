#include "exercice2.h"  

/**
 * @brief Tri par ordre décroissant en fonction du ratio
 * 
 * @param obj array of Object (weight and value) 
 * @param n number of objects in the array
 */

void descendingSort(Object obj[], size_t n){
    int temp;
    for(size_t i=0; i < n; i++){
        for(size_t j=0; j < n; j++){
            if(obj[j].ratio < obj[i].ratio){
                temp = obj[j].ratio;
                obj[i].ratio = obj[j].ratio;
                obj[j].ratio = temp;
            }
        }
    }
}

/**
 * @brief Renvoie la liste des objets avec le meilleur ratio
 * 
 * @param obj array of Object (weight and value)
 * @param n number of objects in the array
 * @param W maximum capacity of the bag
 * @return int 
 */

Object* knapsack(Object obj[], int n, int W){
    Object* ret = malloc(sizeof(Object)*n);
    int currW = 0;
    for (int i = 0; i < n; i++)
    {
        obj[i].ratio = obj[i].c / obj[i].w;
    }
    descendingSort(obj, n);
    for(int i=0; i<n; i++){
        if(obj[i].w + currW < W)
        {
            ret[i].w = obj[i].w;
            currW += obj[i].w;
        }
        else
            break;
        ret[i].c = obj[i].c;
    }
    return ret;
}
