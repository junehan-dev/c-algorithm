#include <assert.h>
#include <stdio.h>
#include "lib_array.h"
#define MAX 30

int	main(void)
{
	int	test[MAX];
	int	i;

	i = MAX - 1;
	while (i > 0)  {
		test[i] = MAX - i;
		assert(test[i] == (MAX - i));
		i--;
	}

	test[0] = 17;
	test[12] = 23;
	test[21] = 1;
	test[28] = 11;
	test[2] = 23;
	test[1] = 8;
	i = 0;
	while (i < MAX) {
		printf("i:%d at %d\n", i, test[i]);
		i++;
	}
	i = 0;
	qsort(test, MAX);
	while (i < MAX - 1) {
		//assert(test[i] <= test[i + 1]);
		printf("i:%d at %d\n", i, test[i]);
		i++;
	}
	
	return (0);
}
