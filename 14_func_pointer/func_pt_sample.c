#include <stdio.h>

void logger(int a, int b);

int callback(void ((*callbackfunc_pt)(int, int)))
{
    callbackfunc_pt(2, 4);
    printf("callback done;\n");
    return 0;
}

void logger(int a, int b)
{
    printf("logger: %d, %d\n", a, b);
}

int main()
{
    int (*func_pt)(int, int);

    int sample(int a, int b){
        return (a+b);
    }

    func_pt = sample;
    int ret = func_pt(2, 4);
    printf("%d\n", ret);
    callback(&logger);
    return 0;
}
