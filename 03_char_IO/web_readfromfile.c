#include <stdio.h>
#include <stdlib.h>

int main(void){

	/* FILE *fopen( const char *restrict filename, const char *restrict mode ); -> Pointer
	 *
	 * return null pointer when fails to open.
	 */

	FILE *fp = fopen("test.txt", "r");
	if(!fp){
	
		/* void perror( const char *s ); -> print error
		 *
		 * prints textual desc of err-code currently stored in sys-var `errno` to `stderr`
		 */

		perror("fopen() failed!");
		return EXIT_FAILURE;
	} else{

		int c; // int자료형이 들어온다 50000~-49999정도 들어올 수 있는.	

		/* int fgetc( FILE *stream ); -> integer
		 * 
		 * read next char from given stream
		 * 성공시 문자가 아스키로 변환되어, 실패시 EOF(10) 으로 들어온다.
		 * 10이 들어오면 추가적으로 스트림에 대해 eof 지시자를 설정한다.
		 * 만약 EOF이외의 에러가 들어오면 스트림에 대해 error 지시자를 설정한다.
		 */
		
		while ((c = fgetc(fp)) != EOF) {

			/* int putchar( int ch );
			 *
			 * write char ch to stdout.
			 * 내부적으로 char은 stdout에 unsigned char 형태로 전환되어 전달된다.
			 * 성공시 해당 ascii가 반환된다.
			 * 실패시 EOF(-1)을 반환하고, stdout에 대한 에러지시자를 설정한다
	 		 */

			putchar(c);
		}
		
		/* int ferror( FILE *stream );
		 * 
		 * 해당 스트림에 대한 error지시자가 설정되었는지 확인한다.
		 * 해당 스트림에 대한 error지시자가 설정되었다면 0이 아닌 숫자를 반환
		 *
		 * int feof( FILE *stream ); 
		 *
		 * 해당 스트림버퍼가 EOF에 도달했는지 확인한다.
		 * EOF에러지시자가 설정되었다면 0이 아닌 숫자를 반환.
		 */

		if (ferror(fp)){
			puts("I/O error during reading!");
		} else if(feof(fp)) {
			puts("EOF reached!");
		}

		fclose(fp); // tell os to write on hdd buffer to write-wait
		// 일단 이시점에 c스크립트 실행 프로세스에서 벗어난다.
	}	
}
