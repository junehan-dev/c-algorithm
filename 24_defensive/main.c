#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>


int safercopy(int src_len, char *src, int dest_len, char *dest);

int main(int argc, char *argv[])
{
    char from[] = "0123456789";
    int from_len = sizeof(from);
    /*
     * regards01-remeber why to get size of this array.
     */

    char to[] = "0123456";
    int to_len = sizeof(to);

    debug("Copying '%s':%d to '%s':%d", from, from_len, to, to_len);

    int rc = safercopy(from_len, from, to_len, to);
    check(rc > 0, "failed to safecopy");
    check(to[to_len-1] == '\0', "string not terminated");

    debug("Result is: '%s':%d", to, to_len);

    // break function.

    rc = safercopy(from_len * -1, from, to_len, to);
    check(rc == -1, "safe copy sould fail #1");
    check(to[to_len -1] == '\0', "string not terminated");

    rc = safercopy(from_len, from, 0, to);
    check(rc == -1, "safe copy should fail #2"); // retured i(0) and dest[0-1] = '\0'
    check(to[to_len -1] == '\0', "string not terminated");

    return 0;
error:
    return 1;
}

int safercopy(int src_len, char *src, int dest_len, char *dest)
{
    /*
     *  Validations
     *      1. isNULL(dest) || isNULL(src);
     *      2. isPositive(dest_len) || isPositive(src_len);
     */
    assert(src != NULL && dest != NULL && "src and dest can't be NULL.");

    int i = 0;
    int max = src_len > dest_len ? dest_len -1 : src_len;

    if (src_len < 0 || dest_len < 0)
        return -1;
  
    /*
     *  Copying
     *      1. dest[i] = src[i]; (under while statement)
     *      2. dest[dest_len+1] = '\0';
     *      3. return i;
     */

    while(i < max)
    {
        dest[i] = src[i];
        i++;
    }

    dest[dest_len - 1] = '\0';

    return i;
}


void copy(char dest[], char src[])
{
    /*
     *  Copying
     *      1. while dest[i] != '\0';
     *          - dest[i] = src[i];
     *  no stop if dest termintating 0 not founds.
     */
}
