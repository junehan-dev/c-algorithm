#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[ ], int nlines);
void writelines(char *lineptr[ ], int nlines);
void qsort(char *lineptr[ ], int left, int right);

main()
{
	int nlines;

	if ((nlines = readlines(linetr, MAXLINES)) >= 0)
	{
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}	else	{
		printf("error: input too big to sort\n");
		return -1;
	}
}

#define MAXLEN 1000
int getline(char *int);
char *alloc(int);

int readlines(char *lineptr[ ], int maxlines)
{
	int len, nlines;
	char *p, line{MAXLEN];
}
