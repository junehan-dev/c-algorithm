#include <unistd.h>
#include <stdio.h>
#define MAX 1000
#define MIN 80

int getstring(char line[], int max);

main ( )
{
	/*
	 * define MIN 80 이상인 문자열 출력
	 * 1. 문자를 입력한다.
	 * 2. 문자를 배열에 저장하고 line \n과 \0, EOF등을 만나면 저장을 종료시키고 \0을 입력한다?
	 * 3. 그 배열의 길이를 측정한다.
	 * 4. 80이상이라면 해당 배열을 출력하고 비운다. 
	 */
	int len;
	char line[MAX];

	while ((len = getstring(line, MAX)) > MIN)
		write(1, &line, len);
}

int getstring(char line[], int max)
{
	int i, c;
	i = 0;
	while((c = getchar()) != EOF && c != '\n' && (i=i+1) < max)
	{
		line[i] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
