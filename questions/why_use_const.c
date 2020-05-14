#include <stdio.h>

void change_value(const char *str)
{
    printf("%p:%s\n",str, str);
    *str = 'a';
}

int main()
{
    char test[] = "original resetable data\0";
    char *const_str = "const origin data\0";
    printf("1:%p\n", test);
    printf("2:%p\n", const_str);
    change_value(test);
    //change_value(const_str);
    return 0;
}
