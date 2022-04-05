#include <ctype.h>
#include <stdio.h>
#include "calc.h"

/*	getop: get next operator or numeric operand.	*/
int getop(char s[])
{
	int i, c;

	/*	1. flush charater from string if blank or tab	*/
	while (
			((s[0] = c = getch()) == ' ')
			|| (c == '\t')
		  );
	
	/* 2. s[0] and `c` would be printable char or NULL */
	s[1] = '\0';

	/*	3. return c, if not digit and somthing except dot	*/
	if (
			(!isdigit(c))
			&& (c != '.')
	   )
		return c;

	/*	4. c is digit or .	*/

	i = 0;
	/*	5. s[1~] will be digits */
	if (isdigit(c))
		while (isdigit(
					s[++i] = c = getch()
					)
				);
	/*	this point c will be . or \0	*/

	/*	6. s[~] will be digits after .	*/
	if (c == '.')
		while (isdigit(
					s[++i] = c = getch()
					)
			  );
	
	s[i] = '\0'; // end s with NULL.
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}
