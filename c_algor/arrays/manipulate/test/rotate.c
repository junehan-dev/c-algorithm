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

	i = 0;
	int tmp;
	while (i++ < MAX) {
		tmp = test[1];
		rotate(test, MAX, 1);
		assert(test[0] == tmp);
		printf("i:%d at %d\n", 0, test[0]);
	}
	
	return (0);
}
