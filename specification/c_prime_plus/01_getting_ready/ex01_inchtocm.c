#include <stdio.h>
#include <stdlib.h>

int		isnumeric(char ch);
int		inchtocm(const char *argv);
double	convertinchtocm(double src);

int	main(int argc, const char **argv)
{
	return (argc == 2) ? inchtocm(*(argv + 1)) : 1;
}

int	inchtocm(const char *argv)
{
	int		isnum;
	double	v[2];
	double	div;
	
	/* ERROR */
	if ((isnum = isnumeric(*argv)) != 1)
		return (1);

	/* parse interger point */
	v[0] = atoi(argv);
	while (isnum == 1) {
		/* skip while num */
		isnum = isnumeric(*(++argv));
	}

	/* parse floating point */
	div = 0.1;
		/* skip dot and expect next to number */
	if (isnum == 2 && isnumeric(*++argv) == 1) {
		v[1] = atoi(argv);
		/* skip while num */
		while ((isnum = isnumeric(*++argv) == 1))
			div *= 0.1;
	}

	/* if not normal end */
	if (isnum != 0)
		return (1);

	printf("%f", convertinchtocm(v[1] == 0 ? v[0] : v[1] * div + v[0]));
	return (0);
}

int isnumeric(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '.')
		return ((ch == '.') ? 2 : 1);

	return ch == 0 ? (0) : -1;
}


double	convertinchtocm(double inch)
{
	return (inch * 2.54);
}
