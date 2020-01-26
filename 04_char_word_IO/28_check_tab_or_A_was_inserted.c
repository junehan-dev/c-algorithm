#include<stdio.h>

int main()
{
	int key;

	for(int i=0; i <= 10;){
		key = getchar();
		if (key == '\t'){
			i++;
			printf("tab found:%d\n", i);
		}
		if (key == 65 ){
			printf("key A found\n");
		}
	}
}
