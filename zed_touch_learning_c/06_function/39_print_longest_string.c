#include <stdio.h>
#define MAXLINE 1000

int	getcurline(char s[], int limit);
void copyfromto(char origin[], char dest[]);
/*	1. read row.
 *	2. count length
 *	3. store longest
 *	4. controller
 * */

main ( )
{
	int len; /*store current row's length*/
	int max; /*store num of max length*/
	char line[MAXLINE]; /*store current data*/
	char longest[MAXLINE]; /*store longest data*/

	max = 0;	
	/*getlin function check current line's length*/
	while((len = getcurline(line, MAXLINE)) > 0) /*if no data stored? break*/
	{
		if (len > max)
		{
			max = len;
			copyfromto(line, longest);/*store cur line in to longest*/
		}
		if (max > 0)
			printf("%s", longest);
	}
}

int	getcurline(char s[], int limit)
{
	int c, i;
	/*returns length of str*/	

	for(i = 0; i < limit-1 && (c=getchar()) != EOF && c!= '\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copyfromto(char origin[], char dest[])
{
	int i;

	i = 0;
	while ((dest[i] = origin[i]) != '\0')
		++i;
}
