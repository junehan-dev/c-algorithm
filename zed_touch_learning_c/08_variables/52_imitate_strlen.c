#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int imitate_strlen(char s[ ])
{
	int i;
	
	i = 0;
	while (s[i] != '\0')
		++i;
	return i;
}

int main ( )
{	
	int n, c;
	char prints[MAXLINE];

	n = imitate_strlen("hello world!");
	c = 0;
	while ((n/10)!=0 || (n%10)!=0)
	{
		prints[c] = (n % 10 + 48);
		n = n / 10;
		c++;
	}
	prints[c] = '\0';
	c++;
	write(STDOUT_FILENO, &prints, c);
	printf("\nEXIT_FAILURE:%d, EXIT_SUCCESS:%d\n", EXIT_FAILURE, EXIT_SUCCESS);
	char other_1[4] = "hit";
	char str[16] = "1234";
	char other[4] = "hit";
	for (int i=0; i<32; i++)
	{
		if(str[i] == 0)
			printf("null!\n");
		if(str[i] == 3)
			printf("endoffile!\n");
		printf("%d,", str[i]);	
	}
	return EXIT_SUCCESS;
}
