#include <ctype.h>
#include <stdio.h>
/*
int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()));
	// c is not space!
	
	// if c is not digit, not fileend and not '+' or '-'
	// then => ungetch(c); return 0;
	// totally mean numeric things only or stop program;
	if (
			(!isdigit(c)) &&
			(c != EOF) &&
			(c != '-') &&
			(c != '+')
			)
	{
		ungetch(c);
		return 0;
	}
   
	sign = (c == '-') ? -1 : 1;

	if(
			(c == '+') ||
			(c == '-')
			)

	*pn = 0; // set pointer value to 0;

	while (isdigit(c=getch())) // get char til not numeric
		(*pn = 10 * (*pn) + (c - '0'));

	(*pn) *= sign;

	if(c != EOF) // not digit and not EOF. alphabet, special character.
		ungetch(c); // dosent handle dot. only integer.

	return (c);
}
*/
int main()
{
	int allocated, *reference;
	allocated = 0;

	reference = &allocated;
	
	printf("allocated: %d, *reference: %d\n", allocated, *reference);
	*reference +=1;

	printf("allocated: %d, *reference: %d\n", allocated, *reference);
	
	int *addone_ref, *addtwo_ref, *addtwoatonce_ref;
	addone_ref= reference+1;
	addtwo_ref= addone_ref+1;
	addtwoatonce_ref =reference+2;
	printf("origin: %p\n +1_ref: %p\n +11ref: %p\n +2_ref:%p",
			reference,
			addone_ref,
			addtwo_ref,
			addtwoatonce_ref
			);
	
	int *add99_ref =reference+99;
	int *addc_ref = reference+'c';
	printf("\n63: %p\n+c: %p", add99_ref, addc_ref);

	int sample[2]={44,55};

	printf("\nsample_p = %p, sample[0]p = %p", sample, &(sample[0]));
}
