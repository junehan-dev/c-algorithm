#include <stdio.h>
#include <stdlib.h>
main()
{
	FILE *fp = fopen("check_double_white_space.txt", "r");
	if(!fp){
		perror("open file check_double_white_space.txt error!");
		printf("EXIT_FAILURE: %d", EXIT_FAILURE);
		return EXIT_FAILURE;
	}
	// opened fine
	int c;
	int b;
	while ((c = fgetc(fp)) != EOF){
		//write c once  
		putc(c, stdout);
		if(c == ' '){
			b = fgetc(fp);
			if(b == EOF){
				break;
			} else if(b != ' '){
				putc(b, stdout);
			    //write c,b
			} else{
				printf("\ndouble space occured!\n");
			}
		}
	}
	
	if (ferror(fp)){
		fputs("erorr occoured\n", stdout);
	} else if(feof(fp)){
		fputs("EOF reached!\n", stdout);
	}
	printf("EXIT_SUCCESS: %d", EXIT_SUCCESS);
	return EXIT_SUCCESS;
}
