## library and link

### library_programs

1. ``ar rcs $(TARGET) $(OBJECTS)``

    - schema
        ``ar [-X32_64] [-]p[mod] [--plugin name] [--target bfdname] 
[relpos] [count] [archive] [member...]``

    - DESC
        GNU ar program. creates modiftes and extract from archives.  
ARCHIVE is single file holding collaction of other files in structre,  
that makes it possible to retrieve the original individual files.

        original file's contents, mode, timestamp, owner and group are preserved in archive.

        ar is considered a binary utility, because archives of this sort are  
mose often used as libraries holding commonly needed subroutines.

    - options
        - ``r``: insert the files ``members`` into ``archive``.
        - ``c``: create archive.
        - ``s``: add an index to archive, or update it if already exist.

2. ``ranlib $(TARGET)``

    - schema
        ``ranlib [--plugin name] [-DhHvVt] archive``

    - DESC
        ranlib generates index to contents of archive and stores it in it.  
the index lists each symbol defined by a member of an archive that is relocatable object file.  

        archive with such as index speeds up linking to the library  
and __allows routines in the library to call each other  
without regard to their placement in the archive__

        GNU ranlib program is another form of GNU ar;
        running ranlib is __completely equivalent to executing ``ar -s``__.

### libraries

1. static library

    일종의 컨테이너로, 오브젝트 파일과 그 안에 포함된 함수 세트가 들어있으며,  
프로그램을 빌드 할 때 하나의 커다란 ``.o``파일 처럼 취급할 수 있다.

    - 사용하기 쉽고 많은 운영체제에서 작업할 수 있다.
    - 단위테스트와 프로그램에 링크하는 것을 선호한다.

2. dynamic library

    보통 ``.so``, ``.dll``로 끝나며, 이러한 동적 라이브러리 파일은 빌드된 다음 공통된 위치에 배치된다.  
그래서 운영체제는 프로그램이 실행 될 때 이러한 라이브러리파일을 동적으로  
로드하고 실시간으로 프로그램에 연구한다.

    - 공간이 부족한 경우 또는 공통적인 기능을 사용하는 프로그램이 많은 경우.
    - 이 경우 공통기능에 대한 코드 전체를 모든 프로그램에 정적으로 링크시킬 필요 없이,  
동적 라이브러리에 저장하여 모든 프로그램에서 한번만 로드되도록 한다.

- ``<dlfcn.h>``: open and close shared object and as shared object.

    1. ``void *dlopen(const char *filename, int flags);``
        - desc:
            loads dynamic shared object. returns opaque "handle" for loaded object.
            __this handle is employed with other functions in ``dlopen API``__.
            if object specified by filename has dependencies on other shared objects,
            the, there are also automatically loaded by dynamic linker.

    2. ``int dlclose(void *handle);``
        - desc:
            decrements the ref-count on dynamically loaded shared object reffered to by handle.
            if ref-count drops to zero, object is unloaded.

    > Errors from these function family can be diagnosed using ``char *dlerror(void)``.
