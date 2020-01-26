#include <stdio.h>

main()
{
	int c, i, nwhite, nother;
	int ndigit[10];
	nwhite = nother = 0;
	for (i=0; i<10; i++)
	{
		ndigit[i] = 0;
	}
	while ((c=getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
			++ndigit[c-'0']; // 33(0) to 0th or arr count ++
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else // non numerable charater
			++nother;
	}
	printf("digits =");

	for (i = 0; i < 10; ++i)
		printf(" %d", ndigit[i]);
	printf(", white space = %d, other = %d\n", nwhite, nother);
}
