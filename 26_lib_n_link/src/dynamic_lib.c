#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
    printf("A String: %s\n", msg);
    return 0;
}


int uppercase(const char *msg)
{
    int i = 0;

    while (*(msg + i))
        printf("%c", toupper(msg[i++]));

    return 0;
}
int lowercase(const char *msg)
{
    int i = 0;

    while (*(msg + i))
        printf("%c", tolower(msg[i++]));

    return 0;
}

int fail_on_purpose(const char *msg)
{
    return 1;
}

