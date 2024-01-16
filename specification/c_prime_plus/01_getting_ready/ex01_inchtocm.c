#include <stdio.h>

int isnumeric(char ch);
int	inchtocm(const char *argv);
int	main(int argc, const char **argv)
{
	return (argc == 2) ? inchtocm(*(argv + 1)) : 1;
}

int	inchtocm(const char *argv)
{
	double	ret;
	double	floor;
	int		isnum;

	floor = 1;
	ret = 0;

	while ((isnum = isnumeric(*argv))) {
		if (floor < 1) {
			if (isnum == 2) {
				return (1);
			} else {
				floor *= 0.1;
				ret += floor * (*argv - '0');
			}
		} else {
			if (isnumeric(*argv) == 2) {
				floor *= 0.1;
			} else {
				ret *= 10;
				ret += (*argv - '0');
			}
		}
		argv++;
	}

	if (*argv) 
		return (1);

	ret *= 2.54;
	printf("%f\n", ret);
	return (0);
}

int isnumeric(char ch)
{
	if ((ch >= '0' && ch <= '9') || ch == '.')
		return ((ch == '.') ? 2 : 1);

	return (0);
}

