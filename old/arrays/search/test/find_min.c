#include <assert.h>
#include <stdio.h>
#include "lib_array.h"
#define MAX 30

int	main(void)
{
	int	test[MAX];
	int	i;

	i = 5;
	while (i < MAX)  {
		test[i-5] = i;
		assert(test[i-5] == i);
		i++;
	}

	int min = find_min(test, MAX - 5);
	printf("min:%d\n", min);
	assert(min == 5);
	
	return (0);
}
