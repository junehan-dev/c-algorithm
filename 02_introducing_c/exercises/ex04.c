#include <stdio.h>

void	jolly(void);
void	deny(void);

int main(void)
{
	printf("For he's a ");
	jolly();
	printf(" fellow!\n");

	printf("For he's a ");
	jolly();
	printf(" fellow!\n");

	printf("For he's a ");
	jolly();
	printf(" fellow!\n");

	deny();

	return 0;
}

void	jolly(void)
{
	printf("jolly good");
}
void	deny(void)
{
	printf("which nobody can deny!\n\n");
}
