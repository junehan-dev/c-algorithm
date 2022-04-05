#include <stdio.h>

void test()
{
    char *str_pt = "origin data";
    *str_pt = 'A';
    printf("%s", str_pt);
}

int main()
{
    test();
    return 0;
}
