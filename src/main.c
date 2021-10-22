#include <stdio.h>
#include <stdio.h>
#include <assert.h>
#include "exercice1/exercice1.h"
#include "exercice2/exercice2.h"
#include "exercice3/exercice3.h"

int main()
{
	// int array[] = {1,2,3,4,5,6,7,8,9,10};
	// int test = find_by_dichotomy(array, 10, 10);
	// printf("%d\n", test); // 3
	// assert(find_by_dichotomy(array, 10, 4) == 3);
	// return (0);

	// Object o1, o2, o3;
	// o1.w = 6;o1.c = 7;
	// o2.w = 5;o2.c = 5;
	// o3.w = 5;o3.c = 5;
	// Object objects[3] = {o1, o2,o3};
	// Object *backpack;
	// backpack = knapsack(objects, 3, 10);
	// Object *endPtr = backpack + sizeof(backpack)/sizeof(backpack[0]);
	// printf("L'object w : %d, c: %d\n", backpack->w,backpack->c);
	// assert(backpack->w == 6);
	// assert(backpack->c == 7);
	// backpack++;
	
	int** mat;
	createMatrice(mat, 5);
	displayMatrice(mat, 5);

}
