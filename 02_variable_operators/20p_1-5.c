#include <stdio.h>
int main(void){
	#define MIN 0
	int far; 
	for (far = 300; far>=MIN; far = far-20){
		printf("%3d %6.1f\n", far, (5.0/9.0) * (far-32));
	}
}
