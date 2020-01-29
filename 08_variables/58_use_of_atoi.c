#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int imitate_atoi(char line[]);

int main ( )
{
	int imitated;
	int original;
	char input[8] = "642\0";
	imitated = imitate_atoi(input);
	original = atoi(input);
	printf("imitated:%d\n", imitated);
	write(STDOUT_FILENO, "done\n", 5);
	printf("original: %d\n", original);

}

int imitate_atoi(char s[ ])
{
	int i, n;

	n = 0;
	for (i = 0; (s[i] >= '0') && (s[i] <= '9') ; ++i)
	{
		printf("ongoing:%d\n", i);
		n = 10 * n + (s[i] - '0');
	}
	printf("imitated result: %d\n", n);
	return n;
}
