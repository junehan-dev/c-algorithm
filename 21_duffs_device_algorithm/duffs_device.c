#include <stdio.h>
#include <string.h>
#include "dbg.h"

int valid_copy(char *data, int count, char expects);
int normal_copy(char *src, char *dest, int count);
int duffs_device(char *src, char *dest, int count);
int zeds_device(char *src, char *dest, int count);
int main()
{
    char from[1000] = {'a'};
    char to[1000] = {'c'};

    int rc;

    memset(from, 'x', 1000); // from all x

    memset(to, 'y', 1000); // to all y
    check(valid_copy(to, 1000, 'y'), "Not inited right");

    rc = normal_copy(from, to, 1000); // to all x now.
    check(rc != 1000, "Normal copy failed.");
    
    memset(to, 'y', 1000); // to all y now.

    rc = duffs_device(from, to, 1000); // to should be all x now.
    check(rc != 1000, "duff's device failed:%d", rc);
    check(valid_copy(to, 1000, 'x'), "duff's device failed copy");

    memset(to, 'y', 1000); // to all y now.

    rc = zeds_device(from, to, 1000); // to should be all y now.
    check(rc != 1000, "zed's device failed:%d", rc);
    check(valid_copy(to, 1000, 'x'), "zed's device failed copy.");

    return 0;
error:
    return 1;
}

int duffs_device(char *src, char *dest, int count)
{
    {
        int n = (count + 7) / 8; // 1007 /8 == 125 and 7
        int time = 1;
        switch (count % 8) { // 1000/8 = 0 . 125
            case 0:
                do {
                    printf("%d n:%d", time++, n);
                    *dest++ = *src++;
                    case 7:
                    *dest++ = *src++;
                    case 6:
                    *dest++ = *src++;
                    case 5:
                    *dest++ = *src++;
                    case 4:
                    *dest++ = *src++;
                    case 3:
                    *dest++ = *src++;
                    case 2:
                    *dest++ = *src++;
                    case 1:
                    printf("occured!\n");
                    *dest++ = *src++; // switch no break, do all happens, 8times 
                } while( --n > 0); // 6 < 0 switch do while again.
        }
        return count;
    }
}

int zeds_device(char *src, char *dest, int count)
{
    {
        int n = (count + 7) / 8; // 7
        int time = 1;
        switch(count%8){
            case 0:
again:      *dest++ = *src++;

            case 7:
            printf("%d ", time++);
            *dest++ = *src++;
            case 6:
            *dest++ = *src++;
            case 5:
            *dest++ = *src++;
            case 4:
            *dest++ = *src++;
            case 3:
            *dest++ = *src++;
            case 2:
            *dest++ = *src++;
            case 1:
            *dest++ = *src++;
            if(--n>0)
                goto again;
        }
    }
    return count;
}

int valid_copy(char *data, int count, char expects)
{
    int i = 0;
    while(i<count)
    {
        if (data[i] != expects)
        {
            log_err("data[%d], %c != %c", i, data[i], expects);
            return 1;
        }
        i++;
    }
    return 0;
    // this function returing integer is not somthing means, but bool.
    //  reverses the returning value 0(fail) to 1(fail) and, 1(success) to 0(success).
    //      - dbg.check macro'
    //          check(A, M, ...) if (!(A)) {\
    //          log_err(M, ##_VA_ARGS__);\
    //          errno = 0; goto error;}
    //      - change
    //          if(!(A)) -> if(A) // - for accepts EXIT_FAILURE.
}

int normal_copy(char *src, char *dest, int count)
{
    int i = 0;

    while (i < count)
    {
        dest[i] = src[i];
        i++;
    }
    return i;
}
