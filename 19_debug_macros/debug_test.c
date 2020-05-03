#include <stdlib.h>
#include <stdio.h>
#include "dbg.h"

void test_debug()
{
    debug("test debug %s.", "void test_debug");
}

void test_log_err()
{
    log_err("test log err %s.", "void test_log_err");
}

void test_log_warn()
{
    log_warn("test log warn %s.", "void test_log_warn");
}

void test_log_info()
{
    log_info("test log info %s.", "void test_log_info");
}

int test_check(char *file_name)
{
    FILE *input = NULL;
    char *block = NULL;

    block = malloc(100);
    check_mem(block); // should be operated.

    input = fopen(file_name, "r");
    check(input, "failed to open %s.", file_name);
    free(block);
    fclose(input);
    return 0;

error:
    if (block != NULL) free(block);
    if (input != NULL) fclose(input);
    return -1; 
}

int test_sentinel(int code)
{
    char *temp;
    
    temp = malloc(100);
    check_mem(temp);

    switch (code){
        case 1:
            log_info("It worked.");
            break;
        default:
            sentinel("line should not come");
    }
    free(temp);
    return 0;

error:
    if (temp != NULL)
        free(temp);
    return -1;
}

int test_check_mem()
{
    char *test = NULL;
    check_mem(test);

    free(test);
    return 1;
error:
    return -1;
}

int test_check_debug()
{
    int i;

    i = 0;
    check_debug(i != 0, "i was 0.");
    return 0;
error:
    return -1;
}

int main(int argc, char *argv[])
{
    check(argc == 2, "Need and argument.");

    test_debug();
    test_log_err();
    test_log_warn();
    test_log_info();

    check(test_check("debug_test.c") == 0, "failed with debug_test.c");
    check(test_check(argv[1]) == -1, "failed with argv");
    check(test_sentinel(1) == 0, "test_sentinel failed");
    check(test_sentinel(100) == -1, "test_sentinel failed");
    check(test_check_mem() == -1, "test_check_mem failed");
    check(test_check_debug() == -1, "test_check_debug failed");
    return 0;
error:
    return 1;
}

