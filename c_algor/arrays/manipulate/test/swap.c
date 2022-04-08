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
	int	temp;
	while (i < MAX - 1) {
		temp = test[i];
		swap(test+i, (test+i+1));
		assert(test[i + 1] == temp);
		printf("i:%d at %d\n", 0, test[i++]);
	}
	
	return (0);
}
