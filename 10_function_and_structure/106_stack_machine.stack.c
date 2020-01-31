#include <stdio.h>
#include "calc.h"
#define MAXVAL	100					/*	maximum depth of val stack	*/

static int sp = 0;					/*	next free stack position	*/
static double val[MAXVAL];			/*	value stack	*/


/*	push: push f onto value stack	*/
int push(double f)
{
	int ret = -1;

	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, cant push %g\n", f);
		return ret;
	printf("stack stored %f in %d point!\n", val[sp], sp);
	ret += sp; // if first index? ret:-1 + sp:1 == 0;
	return ret;
}


double pop(void)
{
	double ret = 0.0;

	if (sp > 0)
		ret = val[--sp];
	else {
		printf("error: stack empty");
	}
	return ret;
}
