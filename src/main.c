#include <stdio.h>
#include <assert.h>
#include "exercice1/exercice1.h"

int main()
{
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	int test = find_by_dichotomy(array, 10, 10);
	printf("%d\n", test); // 3
	assert(find_by_dichotomy(array, 10, 4) == 3);
	return (0);
}
