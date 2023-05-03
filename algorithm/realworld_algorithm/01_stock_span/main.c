#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int **get_ints(int count, const char **strs)
{
	int **ret;
   
	ret = (int **)malloc(sizeof(int **));

	while (count--) {
		*(ret + count) = malloc(sizeof(int));
		**(ret + count) = atoi(*(strs + count));
	}

	return (ret);
}

int stat_ints(int count, int **ints)
{
	while (count--)
		printf("ints[%d] is %d\n", count, **(ints + count));

	return (0);
}

int free_ints(int count, int **ints)
{
	while (count--)
		free(*(ints + count));

	free(ints);
	return (0);
}

int	main(int argc, const char **argv)
{
	int **spans;
	spans = (argc > 1) ? get_ints(--argc, argv + 1) : NULL;
	return (spans) ? (stat_ints(argc, spans) | free_ints(argc, spans)) : (1);
}
