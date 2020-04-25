#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#define SET_ON 2;

int main()
{
	int x = 1;
	printf("x: %d\n", x);
	x = x | SET_ON;
	printf("x: %d\n", x);
	x = ~x;
	printf("~x: %d\n", x);

	int lowest = INT_MIN;
    int largest = INT_MAX;
	printf("lowest : %d, largest : %d\n", lowest, largest);
    int target = (lowest >> 1) & largest;
    printf("lowest >> 1, largset & lowest = %d\n", target);
    int start = 1;
    while (start < target)
    {
        start = start << 1;
        printf("start: %d\n", start);
    }

	char str[12] = "123456789012";
	
	int i = 0;
	i = -234;

	i = ~i; 
	printf("%d", i);

}
