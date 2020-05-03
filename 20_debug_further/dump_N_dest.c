#include <stdio.h>
#include "types_func.h"

void destroy(callback_a cmp)
{
    int i;

    i = 0;
    unsigned char *data = (unsigned char *)cmp;

    while (i < 1)
    {
        data[i] = i;
        i++;
    }

    printf("\n");
}

void dump(callback_a cmp)
{
    int i;
    unsigned char *data = (unsigned char *)cmp;

    i = 0;
    while (i < 25)
        printf("%02x:", data[i++]);
    printf("\n");
}
