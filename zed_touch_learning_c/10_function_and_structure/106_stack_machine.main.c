#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP	100

/* routine procedure */
int main()
{
	/* variables */
	int type;
	double op2;
	char s[MAXOP];

	while ( (type = getop(s)) != EOF )
	{
		printf("start while in main");
		switch (type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop(); // care of order
				push(pop() - op2);
				break;
			case '/':
				op2 = pop(); // care of order
				if (op2 != 0.0)
					push(pop()/op2);
				else
					printf("error: zero division error\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
	/*
	 * if(subroutin_procudure())
	 * 		return EXIT_SUCCESS;
	 */
	return EXIT_SUCCESS;
}


/* subroutine procedure			*/

/* 		1. void push(double);	*/
/*
int push(double value)
{
	int index;
	// return index in stack on success
	// return -1 on failure
	return index;
}
*/
/*		2. double pop(void);	*/
/*
double pop(void)
{
	// return value from stack
	// return 0.0 if failure;
}
*/
/*		3. int getop(char[]);	*/
/*
int getop(char s[])
{
	// return 
}
*/
