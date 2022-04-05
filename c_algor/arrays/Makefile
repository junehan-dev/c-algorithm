CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes 
OBJECTS				= search/binarysearch.o \
					manipulate/reverse.o \
					manipulate/rotate.o

TESTS				= search/test/binsearch.c \
					manipulate/test/reverse.c \
					manipulate/test/rotate.c
OUTPUT_OPTION		= -o $@
NAME				= lib_array.a
.DEFAULT_GOAL		:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: test
test: test_binsearch test_reverse test_rotate

search/binarysearch.o:
	$(CC) $(CFLAGS) -c search/binarysearch.c -o $@
manipulate/reverse.o:
	$(CC) $(CFLAGS) -c manipulate/reverse.c -o $@
manipulate/rotate.o:
	$(CC) $(CFLAGS) -c manipulate/rotate.c -o $@

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f lib_*.a

.PHONY: re
re: fclean all


.PHONY: test_binsearch
test_binsearch:
	$(CC) $(CFLAGS) -Iincludes search/test/binsearch.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_reverse
test_reverse:
	$(CC) $(CFLAGS) -Iincludes manipulate/test/reverse.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_rotate
test_rotate:
	$(CC) $(CFLAGS) -Iincludes manipulate/test/rotate.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

