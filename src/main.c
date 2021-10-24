#include <stdio.h>
#include <stdio.h>
#include <assert.h>
#include "exercice1/exercice1.h"
#include "exercice2/exercice2.h"
#include "exercice3/exercice3.h"

#define SIZE_MAT 25

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	int test = find_by_dichotomy(array, 10, 10);
	printf("%d\n", test);
	assert(find_by_dichotomy(array, 10, 4) == 3);

	Object obj1, obj2, obj3;
	obj1.w = 6;
	obj1.c = 7;
	obj2.w = 5;
	obj2.c = 5;
	obj3.w = 5;
	obj3.c = 5;
	Object objects[3] = {obj1, obj2, obj3};
	Object *bag;
	bag = knapsack(objects, 3, 10);
	assert(bag->w == 6);
	assert(bag->c == 7);
	bag++;
	
	int* mat = createMat(mat, SIZE_MAT);
	displayMat(mat, SIZE_MAT);
	Pos positionPgcb = findPgcb(mat, SIZE_MAT);
	printf("\n#### RESULTAT DE LA RECHERCHE ####\n");
	displayMatPgcb(mat, SIZE_MAT, positionPgcb);
	free(mat);
}
