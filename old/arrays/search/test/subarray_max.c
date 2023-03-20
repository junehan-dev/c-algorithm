#include <assert.h>
#include <stdio.h>
#include "lib_array.h"
#define MAX 10

int	main(void)
{
	int	test[MAX];
	int	i;

	i = 0;
	while (i < MAX)  {
		test[i] = i;
		assert(test[i] == i);
		i++;
	}

	printf("sub max:%d\n", subarray_max(test,MAX));
	assert(subarray_max(test, MAX) == 45);
	test[0] = -4;
	test[MAX - 1] = -5;
	assert(subarray_max(test, MAX) == 36);
	return (0);
}
