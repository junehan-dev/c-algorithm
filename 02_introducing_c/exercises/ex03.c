#include <stdio.h>

int	years_to_days(int year);
int main(void)
{
	int	age;

	age = 32;

	printf("age: %d to year: %d, to days: %d\n", age, age, years_to_days(age));
	
	return 0;
}

int	years_to_days(int year)
{
	return (year * 365);
}
