#include <stdio.h>

main()
{
	int lower, upper, step;
	// float version
	float fahr, celsius;
	// decimal version
	// int fahr, celsius;	

	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	
	while (fahr <= upper) {
		// decimal version
		/*
		celsius = 5 * (fahr-32) / 9;
		printf("%3d %6d\n", fahr, celsius);
		*/
		// float version
		// /*
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n" ,fahr, celsius);
		// */
		fahr = fahr + step;
	}

}
