#include <assert.h>
#include <stdio.h>
#include "lib_array.h"
#define MAX 30

int	main(void)
{
	int	test[MAX];
	int	i;

    i = 0;
	while (i++ < MAX)  {
		test[MAX - i] = i;
		assert(test[MAX - i] == i);
	}
	i = 0;
    nsort(test, MAX);
	while (i < MAX) {
		assert(test[i] == i + 1);
		i++;
	}
	return (0);
}
