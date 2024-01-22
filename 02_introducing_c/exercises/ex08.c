#include <stdio.h>

void	one_three(void); // A function displays "one" to "three" each line
void	two(void); // A function displays "two" on one line
				   //
int	main(void)
{
	printf("staring now:\n");
	one_three();
	printf("done!\n\n");
	
	return (0);
}

void	one_three(void)
{
	printf("one\n");
	two();
	printf("three\n");

	return ;
}

void	two(void)
{
	printf("two\n");

	return ;
}

