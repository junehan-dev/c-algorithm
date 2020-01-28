C_BASIC_REFERENCES
=====================

| Provide sphinx documents at https://codenamenadja.github.io/python-ddd/index.html

INDEX
=====

- :`file_functions`_: functions about file object.
- :`io_functions`_: to recognize fine with sphinx.

file_functions
==============

fopen
-----
   :schema: ``FILE fopen( const char *filename, const char *mode );``
   :returns on success: File pointer
   :returns on fail: null pointer
   :desc: make file to readable as stream 
   :code: >>> fp = fopen('test.txt', "r")
      ... if(!fp){
      ... perror("fopen() failed!");
      ... return EXIT_FAILURE;
      ... }
      ... # not erorr
      ... ## do something...
      ... fclose(fp);
      ... return EXIT_SUCCESS;

perror
------  
   :schema: ``void perror( cont char *s );``
   :desc: print testual desc of err-code curretly stored in sys-var ``errno`` to ``stderr``

ferror
------
   :schema: ``int ferror( FILE *stream );``
   :desc: 해당 스트림에 대한 error-indicator가 set 되었는지 확인한다.
   :return on sucess: 설정되었다면 0이 아닌 숫자를 반환.
   :return on fail: 설정되지 않았다면 0을 반환.
   :code: >>> if (ferror(fp)){
      ... puts("I/O error during reading!");
      ... } else if (feof(fp)){
      ... puts("EOF readched!");
      ... }

feof
----
   :schema: ``int feof( FILE *stream );``
   :desc: 해당 스트림 버퍼가 EOF에 도달 했는지 확인한다.
   :return on success: EOF에러지시자일 경우 0이 아닌 숫자를 반환.
   :return on fail: EOF에러지시자가 아니었을 경우 0.

fclose
------
   :schema: ``int fclose( FILE *stream )``
   :desc: 사용하던 버퍼를 지우고 정리(tell os)한 후 stream을 닫는다.
   :return on success: 잘 처리 되었다면 0.
   :return on fail: 에러가 있을시에 EOF.

io_functions
============

write
-----
   :schema: ``ssize_t write(int fd, const void *buf, size_t count);``
   :desc: from fd is delegating files pointer's cursor, write buf's value by count byte.
   :return on success: ssize_t, 바이트단위로 크기를 측정하기 위해 사용되며, 쓰여진 바이트수 반환.
   :return on fail: -1을 반환하고, errno를 설정한다.
   :errno: (에러에 대한 switch구문을 통한 캡쳐링)[https://github.com/codenamenadja/] 

procedure
   1. 사용자영역프로세스가 write()시스템 콜 호출.
   #. 데이터를 시스템영역 버퍼로 복사.
   #. 변경된 버퍼를 수집해서 최적수준으로 정렬 후에 디스크 드라이버로 전송(write back)
   #. 프로세스의 점유 메모리에 기록되던 데이터를 생각해보라.
   #. /proc/sys/vm/dirty_expire_centiseconds에서 버퍼의 최대 나이가 규정된다.
   #. 동기식 쓰기를 통해 시스템영역에서 HDD로 데이터가 떠나고 나서야 사용자영역으로 돌아 올 수 있다.

getchar
-------
   :schema: ``int getchar(void);``
   :desc: stdin으로부터 다음 캐릭터를 읽는다. 그만큼 비워진다.
          만약 EOF를 만난 것으로 실패된다면, stdin에 파일디스크립터에 대해서 eof indicator를 set. ``feof()``
          그 외의 에러로 실패한다면 error indicator를 set. ``ferror()``
   :equals to: ``getc(stdin);``
   :return on success: obtained character
   :return on fail: EOF
