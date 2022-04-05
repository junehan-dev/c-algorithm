CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -Iincludes 
OBJECTS				= search/binarysearch.o
NAME				= lib_array.a
.DEFAULT_GOAL		:= all

.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@

.PHONY: test
test: $(TESTS)
	$(CC) -Werror -Wextra -Wall -Iincludes search/test/test_binsearch.c $(NAME) -o ./test_binsearch.out
	./test_binsearch.out
	/bin/rm ./test_binsearch.out

.PHONY: clean
clean:
	/bin/rm -f $(OBJECTS)

.PHONY: fclean
fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f lib_*.a

.PHONY: re
re: fclean all

srcs/search/binarysearch.o:
	$(CC) $(CFLAGS) -c search/binarysearch.c -o $@
