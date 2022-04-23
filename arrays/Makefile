CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes 
OBJECTS				= search/binarysearch.o \
					search/subarray_max.o \
					manipulate/reverse.o \
					manipulate/rotate.o \
					manipulate/swap.o \
					manipulate/wave.o \
					sort/qsort.o \
					sort/indexsort.o \
					sort/nsort.o
			

TESTS				= search/test/binsearch.c \
					search/test/subarray_max.c \
					manipulate/test/reverse.c \
					manipulate/test/rotate.c \
					manipulate/test/swap.c \
					manipulate/test/wave.c \
					sort/test/qsort.c \
					sort/test/indexsort.c \
					sort/test/nsort.o

NAME				= lib_array.a
.DEFAULT_GOAL		:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: test
test: test_binsearch test_reverse test_rotate \
	test_subarray_max test_swap test_wave \
	test_qsort test_indexsort test_nsort

search/subarray_max.o:
	$(CC) $(CFLAGS) -c search/subarray_max.c -o $@
search/binarysearch.o:
	$(CC) $(CFLAGS) -c search/binarysearch.c -o $@
manipulate/reverse.o:
	$(CC) $(CFLAGS) -c manipulate/reverse.c -o $@
manipulate/rotate.o:
	$(CC) $(CFLAGS) -c manipulate/rotate.c -o $@
manipulate/swap.o:
	$(CC) $(CFLAGS) -c manipulate/swap.c -o $@
manipulate/wave.o:
	$(CC) $(CFLAGS) -c manipulate/wave.c -o $@
sort/qsort.o:
	$(CC) $(CFLAGS) -c sort/qsort.c -o $@
sort/indexsort.o:
	$(CC) $(CFLAGS) -c sort/indexsort.c -o $@
sort/nsort.o:
	$(CC) $(CFLAGS) -c sort/nsort.c -o $@

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
	$(CC) $(CFLAGS) search/test/binsearch.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_reverse
test_reverse:
	$(CC) $(CFLAGS) manipulate/test/reverse.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_rotate
test_rotate:
	$(CC) $(CFLAGS) manipulate/test/rotate.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_subarray_max
test_subarray_max:
	$(CC) $(CFLAGS) search/test/subarray_max.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_swap
test_swap:
	$(CC) $(CFLAGS) manipulate/test/swap.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_wave
test_wave:
	$(CC) $(CFLAGS) manipulate/test/wave.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_qsort
test_qsort:
	$(CC) $(CFLAGS) sort/test/qsort.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_indexsort
test_indexsort:
	$(CC) $(CFLAGS) sort/test/indexsort.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out

.PHONY: test_nsort
test_nsort:
	$(CC) $(CFLAGS) sort/test/nsort.c $(NAME) -o ./test.out
	./test.out
	/bin/rm ./test.out
