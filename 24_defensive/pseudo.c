#undef NDEBUG
#include "dbg.h"
#include <stdio.h>
#include <assert.h>


int safercopy(int src_len, char *src, int dest_len, char *dest)

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


}

int safercopy(int src_len, char *src, int dest_len, char *dest)
{
    /*
     *  Validations
     *      1. isNULL(dest) || isNULL(src);
     *      2. isPositive(dest_len) || isPositive(src_len);
     */
    /*
     *  Copying
     *      1. dest[i] = src[i]; (under while statement)
     *      2. dest[dest_len+1] = '\0';
     *      3. return i;
     */
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
