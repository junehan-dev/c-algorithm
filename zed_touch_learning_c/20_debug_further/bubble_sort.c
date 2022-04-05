#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "types_func.h"
#include "dump_N_dest.h"

void die(const char *msg)
{
    if(errno)
        perror(msg);
    else
        printf("Error: %s\n", msg);

    exit(1);
}


int *bubble_sort(int *numbers, int count, callback_a cmp)
{
    int temp;
    int i;
    int j;
    int *target;
    
    target = malloc(count * sizeof(int));
    
    if (target == NULL)
        die("23_malloc alloc error.");

    memcpy(target, numbers, count * sizeof(int));

    i = 0;
    while(i < count)
    {
        j = 0;
        while(j < (count - 1))
        {
            if(cmp(target[j], target[j+1]) > 0)
            {
                temp = target[j+1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
            j++;
        }
        i++;
    }
    return target;
}

int sorted_order(int a, int b)
{
    return (a - b);
}

int reverse_order(int a, int b)
{
    return (b - a);
}

int strange_order(int a, int b)
{
    return (a == 0 || b == 0) ? 0 : a % b;
}

void test_sorting(int *numbers, int count, callback_a cmp)
{
    int i;
    int *sorted;

    sorted = bubble_sort(numbers, count, cmp);

    if (sorted == NULL)
        die("71_bubble_sort failed to sort as requested.");

    i = 0;
    while (i < count)
        printf("%d ", sorted[i++]);
    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[])
{

    int count;
    int i;

    if(argc < 2) die("execution arguments error, USAGE: *.exe 4 3 1 5 6");

    count = argc - 1;
    i = 0;
    char **inputs = argv+1;

    int *numbers = malloc(count * sizeof(int));
    if(numbers == NULL) die("96_malloc mem alloc error.");

    while(i < count)
    {
        numbers[i] = atoi(inputs[i]);
        printf("got: %d\n", numbers[i]);
        i++;
    }

    test_sorting(numbers, count, sorted_order);
    test_sorting(numbers, count, reverse_order);
    test_sorting(numbers, count, strange_order);

    free(numbers);

    printf("SORTED:");
    dump(sorted_order);

    destroy(sorted_order);

    printf("SORTED:");
    dump(sorted_order);

    return 0;
}
