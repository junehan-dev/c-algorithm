#include <stdio.h>

int main(){
	int c;
	c = getchar(); // equal to getc(stdin)
	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

}

