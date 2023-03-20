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

	reverse(test, 0, 29);
	while (i-- > 0) {
		assert(MAX - i - 1 == test[i]);
		printf("i:%d at %d\n", i, test[i]);
	}
	
	return (0);
}
