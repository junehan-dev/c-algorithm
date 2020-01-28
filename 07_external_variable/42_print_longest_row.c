#include <unistd.h>
#include <stdio.h>

#define MAXLINE 100 /* maximum input line size */

int max; /* max length til now */
char line[MAXLINE]; /* cur input line */
char longest[MAXLINE]; /* longest line saved */

int get_line(void);
void copy_line(void);

int main ( )
{
	int len ;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = get_line()) > 0)	/* 3. new input line length is bigger? */
	{
		if (len > max) {
			max = len;
			copy_line(); /* 4-1. copy cur input to longest array */
		}
	}
	if (max > 0) /* 5. print longest line whatever it's renewed or not */
		write(1, &longest, max);
	return 0;
}


int get_line(void)
{
	int c;
	int i;
	extern char line[]; /* 1. store line data */

	for (i = 0; (i < MAXLINE-1)
			&& ((c = getchar()) != EOF)
			&& (c != '\n'); ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	write(1, &line, i);
	return i; /* 2. return length of line to main */
}

void copy_line(void)
{
	int i;
	extern char line[]; /* from get_line */
	extern char longest[]; /* from main */

	i = 0;
	while ((longest[i] = line[i]) != '\0') /* 4-2. move line to longest arr */
		++i;
	write(1, "longest changed!\n", 17);
}
