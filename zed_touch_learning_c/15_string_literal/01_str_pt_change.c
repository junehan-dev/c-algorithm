#include <unistd.h>

int main()
{
    char *const_str_pt;
    
    const_str_pt = "sample text";
    *const_str_pt = 'a';
/*
    char arr_pt[10] = "dynamic.\0";
    char arr_pt2[5] = "sss\0";
    &(arr_pt[0]) = &(arr_pt2[0]);
    char *str_pt;

    str_pt = arr_pt;
    while(*str_pt !='\0')
        write(STDOUT_FILENO, str_pt++, 1);
*/
    return 0;
}
