#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#define SET_ON 2;

int main()
{
	int x = 1;
	printf("%d\n", x);
	x = x | SET_ON;
	printf("%d\n", x);
	x = ~x;
	printf("%d\n", x);

	int lowest = INT_MIN;
	int largest;	
	largest = lowest << 1;
	printf("%d = lowest && << 1 : largest = %d\n", lowest, largest);

	char str[12] = "123456789012";
	
	int i = 0;
	while (i <32)
	{
		printf("indes:%d value:", i);
		write(1, &str[i], 1);
		printf("\n");
		i++;
	}

}
