#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_LEN 100

int read_scan(const char *fmt, ...);

int main(int argc, char *argv[])
{
    char *first_name, *last_name;
    char initial;
    int age;
    int rc;

    first_name = NULL;
    last_name = NULL;
    age = 0;

    printf("insert first name...:");
    rc = read_scan("%s", MAX_LEN, &first_name);
    check(rc == 0, "Failed first name");

    printf("insert initial...:");
    rc = read_scan("%c\n", &initial);
    check(rc == 0, "failed initial");
    
    printf("insert last name...:");
    rc = read_scan("%s", MAX_LEN, &last_name);
    check(rc == 0, "failed last name.");

    printf("insert age...:");
    rc = read_scan("%d", &age);
    printf("%s %s: %c, %d\n",first_name, last_name, initial, age);
    free(first_name);
    free(last_name);
    return 0;
error:
    return -1;
}

int read_str(char **out_str, int max_buffer)
{
    *out_str = calloc(1, max_buffer+1);
    check_mem(*out_str);

    char *result = fgets(*out_str, max_buffer, stdin);
    check(result != NULL, "INPUT error.");
    return 0;

error:
    if (*out_str) free(*out_str);
    *out_str = NULL;
    return -1;
}

int read_int(int *out_int)
{
    char *input = NULL;
    int rc = read_str(&input, MAX_LEN);
    check(rc == 0, "Failed to read number.");

    *out_int = atoi(input);
    free(input);
    return 0;
error:
    if (input) free(input);
    return -1;
}
    

int read_scan(const char *fmt, ...)
{
    int i;
    int max_buffer;
    int rc;
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
    while (fmt[i] != '\0')
    {
        if(fmt[i] == '%')
        {
            i++;
            switch (fmt[i])
            {
                case '\0':
                    sentinel("invalid format ended with %%");
                    break;
                case 'd':
                    out_int = va_arg(argp, int *);
                    rc = read_int(out_int);
                    check(rc == 0, "failed to read int.");
                    break;
                case 'c':
                    out_char = va_arg(argp, char *);
                    *out_char = fgetc(stdin);
                    break;
                case 's':
                    max_buffer = va_arg(argp, int);
                    out_str = va_arg(argp, char **);
                    rc = read_str(out_str, max_buffer);
                    check(rc == 0, "Failed to read string.");
                    break;
                default:
                    sentinel("invalid format.");

            }
        } else {
            fgetc(stdin);
        }
        check(!feof(stdin) && !ferror(stdin), "Input error.");
        i++;
    }
    va_end(argp);
    return 0;

error:
    va_end(argp);
    return -1;
}

