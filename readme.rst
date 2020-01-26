C_BASIC_REFERENCES
=====================

| Provide sphinx documents at https://codenamenadja.github.io/python-ddd/index.html

INDEX
=====

- :`file_functions`_: functions about file object.
  - :`fopen`_
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
   :schema: ``void perror( cont char *s);``
   :desc: print testual desc of err-code curretly stored in sys-var ``errno`` to ``stderr``

io_functions
============

- before type annotations

>>> def sample(arg1:int, arg2) -> bool:
...     """Sample class for testing docstring.
...  
...     :param arg1: value to be ~ed.
...     :param arg2: value to be ~ed.
...     :type arg2: int
... 
...     :Keyword Arguments:
...         :message: some keyword arg.(default to (,))
... 
...     :return: return will be...
...     :rtype: bool
...     """

