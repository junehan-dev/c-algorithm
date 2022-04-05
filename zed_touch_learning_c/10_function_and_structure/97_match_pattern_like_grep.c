#include <unistd.h>
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // 일반적인 함수 안에서 일어난다면 동적인 할당. 상수로서 문자열은 참조되고 사라진다.
// 그리고 해당 상수로서 문자열의 길이를 추측하고 그에 맞는 크기의 배열을 만들고 값을 할당한다.

main ()
{
	char line[MAXLINE]; // 한 행으로 인정되는 최대 크기.
	int found = 0; // 한 행 안에서 발견된 횟수

	while (get_line(line, MAXLINE) > 0) // 한 행으로 인정되는 최대 크기를 넣어서, 어떤 외부효과를?
		if (strindex(line, pattern) >= 0) { // 해당 행에 대해서 패턴을 찾아서 히트만큼 리턴된 값.
			printf("%s", line); // line은 아직도 한행인가?
			found++;
		}
	printf("%d times found!", found);
	return found;
}

int get_line(char s[], int max)
{
	// get char from stdin. 1by1, and store him in to line; return line length;
	int c, i;

	i = 0;
	while(
			(--max > 0)
			&& ((c=getchar()) != EOF)
			&& (c != '\n')
		 )
	{
		s[i++] = c;
	}
	if (c == '\n')
	{
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}

int strindex(char source[], char keyword[])
{
	int s_i = 0;
	int k_i;
	int s_k_i;
	while (source[s_i] != '\0') // 1. if not finished?
	{
		k_i = 0;
		s_k_i = s_i;
		if (source[s_k_i] == keyword[k_i])
			while(source[++s_k_i] == keyword[++k_i]);
			if(keyword[k_i] == '\0')
				return s_i;
		s_i++;
	}
	return (-1);
}
