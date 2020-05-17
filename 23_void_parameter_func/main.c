#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_LEN 100

size_t read_scan(const char *fmt, ...);

int main(int argc, char *argv[])
{
    char *first_name, *last_name;
    char initial;
    int age;
    size_t rc;

    first_name = NULL;
    last_name = NULL;
    age = 0;

    printf("insert first name...:");
    rc = read_scan("%s", MAX_LEN, &first_name);
    
}

size_t read_scan(const char *fmt, ...)
{
    int i;
    size_t rc;
    int *out_int;
    char *out_char;
    char **out_str;

    out_int = NULL;
    out_str = NULL;
    out_int = NULL;

    i = 0;
    rc = 0;

    va_list argp;
    va_start(argp, fmt);
}
