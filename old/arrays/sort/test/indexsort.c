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

	test[0] = -1;
	test[12] = -1;
	test[21] = -1;
	test[28] = -1;
	test[2] = -1;
	i = 0;
	while (i < MAX) {
		printf("i:%d at %d\n", i, test[i]);
		i++;
	}
	i = 0;
	indexsort(test, MAX);
	while (i < MAX) {
		printf("i:%d at %d\n", i, test[i]);
		assert(test[i] == i || test[i] == -1);
		i++;
	}
	
	return (0);
}
