CFLAGS= -Iincludes/ -Wall -g -DNDEBUG $(OPTFLAGS)
PREFIX?= ./

SOURCES= $(wildcard src/*.c)
OBJECTS= $(patsubst %.c,%.o,$(SOURCES))

TARGET= build/c-skeleton.a
SO_TARGET= $(patsubst %.a,%.so,$(TARGET))

TEST_SRC= $(wildcard tests/*_tests.c)

.DEFAULT_GOAL := all

#The Target build
.PHONY: all
all: build $(TARGET) $(SO_TARGET) tests

$(TARGET): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

$(SO_TARGET): CFLAGS += -fPIC
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) $(CFLAGS) -shared -o $@ $(OBJECTS)

.PHONY: build
build:
	@mkdir -p build
	@mkdir -p bin

#The Unit Tests
.PHONY: tests
tests: 
	$(CC) $(CFLAGS) $(TEST_SRC) -ldl -o tests/test.out
	sh ./tests/runtests.sh

#The CLeaner
.PHONY: clean
clean:
	rm -rf build $(OBJECTS)
	rm -rf build $(SO_TARGET) $(TARGET)
	rm -f tests/tests.log
	rm -f tests/*.out
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

.PHONY: fclean
fclean:
	rm -rf $(TARGET) $(SO_TARGET)

#The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

#The checker
check:
	@echo "Files with potentially dangerous functions."
	@egrep '[^_.>a-zA-z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
		|stpn?cpy|a?sn?printf|byte_)' $(SOURCES) || true

