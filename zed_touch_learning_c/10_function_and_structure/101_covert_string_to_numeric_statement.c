#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

int main()
{
	char str_1[] = "-1234.235";
	char str_2[] = "2345.356";
	double sum, atof_imitated(char[]);
	char line[MAXLINE];
	double res_1, res_2;
	res_1 = atof_imitated(str_2);
	printf("%f\n", res_1);
	res_2= atof_imitated(str_1);
	printf("%f\n", res_2);
	sum = res_1+ res_2;
	printf("%f\n", sum);
}

double atof_imitated(char s[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	// reset i = 0;
	if (s[i] == '+'|| s[i] == '-')// 0번에 부호가 있었다면,
		i++; // 부호를 제외하고,
	for (val = 0.0; isdigit(s[i]); i++) // 숫자와 . 만 있어야 한다.
		val = 10.0 * val + (s[i] - 48); // val에 자릿수를 더한다. 10을 곱한다.
	// 중간에 . 이 있었거나, 끝에 도달, 문자발견시, 즉, 소수점 이하의 수는
	printf("%d,\n", i);
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0'); // 정수로서 값을 자릿수로 늘리고
		power *= 10.0; // 이후에 나눠야할 10을 키운다.
	}
	return sign * val / power;
}

