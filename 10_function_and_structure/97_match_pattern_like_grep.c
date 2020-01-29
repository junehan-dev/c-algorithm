#include <unistd.h>
#define MAXLINE 1000

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // 일반적인 함수 안에서 일어난다면 동적인 할당. 상수로서 문자열은 참조되고 사라진다.
// 그리고 해당 상수로서 문자열의 길이를 추측하고 그에 맞는 크기의 배열을 만들고 값을 할당한다.

main ()
{
	char line[MAXLINE]; // 한 행으로 인정되는 최대 크기.
	int found = 0; // 한 행 안에서 발견된 횟수

	while (getline(line, MAXLINE) > 0) // 한 행으로 인정되는 최대 크기를 넣어서, 어떤 외부효과를?
		if (strindex(line, pattern) >= 0) { // 해당 행에 대해서 패턴을 찾아서 히트만큼 리턴된 값.
			printf("%s", line); // line은 아직도 한행인가?
			found++;
		}
	return found;
}

int getline(char line[], int max)
{

}

int strindex(char source[], char searchfor[])
{
	int i = 0;
	int si = 0;
	while (soureh[i] != '\0')
	{
		if (searchfor[0] != source[i])
		{
			i++;
			continue;
		} else {
			while (seachfor[si] != "\0")
			{
				if searchfor[si++] == source[i]
				{
					
				}
			}
				
		}
	}
}
