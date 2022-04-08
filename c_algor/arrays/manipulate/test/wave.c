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
		printf("i:%d at %d\n", i, test[i]);
		i++;
	}

	wave(test, MAX);
	i = 0;

	while (i < MAX - 1) {
		(i % 2) ? assert(test[i] > test[i+1]) : assert(test[i] < test[i + 1]);
		i++;
	}

	return (0);
}
