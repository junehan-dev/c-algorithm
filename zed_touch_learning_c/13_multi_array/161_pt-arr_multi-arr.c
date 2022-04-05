#include <stdio.h>

int main(void)
{
    int a[10][20];
    int value;
    value = 1;
    while(value <= 10)
    {
        a[value-1][0] = value;
        value++;
    }
    printf("%d = value\n", --value);
    while(--value >= 0)
        printf("%d-arr : %d\n", value, a[value][19]);
}
