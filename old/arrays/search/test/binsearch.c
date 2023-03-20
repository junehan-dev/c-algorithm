#include <assert.h>
#include <stdio.h>
#include "lib_array.h"
#define MAX 30

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

	while (i-- > 0) {
		assert(MAX - i - 1 == binarysearch(test, MAX, MAX - i - 1));
		printf("i:%d at %d\n", MAX - 1 - i, binarysearch(test, MAX, MAX - i - 1));
	}
	
	return (0);
}
