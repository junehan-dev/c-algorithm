#include <stdio.h>

main()
{
/* printf에 전달한 문자열상수를 특정 디바이스파일로 전달
 * write(1, "hello, world", 12); 성공시 해당 byte count/ 실패시 -1 리턴
 * 일반적으로 쉘환경등에서 1번 파일디스크립터는 표준출력을 가르킨다.
 * */
	printf("hello, world"); // 12를 리턴받고나면 스택포인터가 이동한다.
}
// main 함수가 종료되었으니 main함수에 스텍이 사라진다.
