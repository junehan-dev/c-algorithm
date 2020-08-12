CFLAGS= -g -Iincludes/ -DNDEBUG $(OPTFLAGS)
LIBS= -ldl $(OPTLIBS)
PREFIX?= ./

SOURCES= $(wildcard 26_lib_n_link/src/*.c)
OBJECTS= $(patsubst %.c,%.o,$(SOURCES))

TEST_SRC= $(wildcard tests/*_tests.c)
TESTS= $(patsubst %.c,%,$(TEST_SRC))

TARGET= build/c-skeleton.a
SO_TARGET= $(patsubst %.a,%.so,$(TARGET))

.DEFAULT_GOAL := all

.PHONY: d_lib
d_lib:
	$(MAKE) -C 26_lib_n_link
	cp ./26_lib_n_link/*.so ./build/d_lib.so


#The Target build
.PHONY: all
all: build d_lib $(TARGET) $(SO_TARGET) tests

dev: CFLAGS=-g -Iincludes/ -Wall -Wall -Wextra $(OPTFLAGS)
dev: all

$(TARGET): $(OBJECTS)# $(TARGET) -> 11:TARGET
$(TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS) # &@ -> 21: $(TARGET) # put target to source file, and OBJECTS so on..
	ranlib $@ # to build library, command ranlib with name $(TARGET)

$(SO_TARGET): $(TARGET) $(OBJECTS) 
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin
#The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh

#The CLeaner
clean:
	rm -rf build $(OBJECTS)
	#rm -rf build $(SO_TARGET) $(TARGET)
	rm -rf build $(TARGET)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`
	$(MAKE) clean -C 26_lib_n_link
	$(MAKE) fclean -C 26_lib_n_link

#The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

#The checker
check:
	@echo "Files with potentially dangerous functions."
	@egrep '[^_.>a-zA-z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
		|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true
