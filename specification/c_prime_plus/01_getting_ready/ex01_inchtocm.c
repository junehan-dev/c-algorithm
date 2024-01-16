#include <stdio.h>

int isnumeric(char ch);
int	inchtocm(const char *argv);
int	main(int argc, const char **argv)
{
	return (argc == 2) ? inchtocm(*(argv + 1)) : 1;
}

int	inchtocm(const char *argv)
{
	int		isnum;
	double	v;
	double	div;
	
	v = 0;
	div = 1;

	while ((isnum = isnumeric(*argv)) == 1) {
		v *= 10;
		v += *argv++ - '0';
	}

	if (isnum == 2) {
		while ((isnum = isnumeric(*(++argv))) == 1) {
			div *= 0.1;
			v += !(*argv - '0') ? 0 : (*argv - '0')  * div;
		}
	}

	if (*argv != '\0')
		return (1);

	printf("%f", v * 2.54);
	return (0);
}

int isnumeric(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '.')
		return ((ch == '.') ? 2 : 1);

	return (0);
}

