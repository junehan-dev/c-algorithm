#include <stdio.h>
#include "./includes/dbg.h"
#include <dlfcn.h>

typedef int (*lib_function) (const char *data);

int main(int argc, char *argv[])
{
    int rc;
    char *lib_file;
    char *func_to_run;
    char *data;
    void *lib;
    lib_function func;

    if (argc < 3)
    {
        printf("argc should at least 3");
        return -1;
    }
    rc = 0;
    lib_file = argv[1];
    func_to_run = argv[2];
    data = argv[3];
    lib = dlopen(lib_file, RTLD_NOW);
    check(lib == NULL, "failed to open lib %s: %s",
            lib_file, dlerror()
            );

    func = dlsym(lib, func_to_run);
    check(func == NULL,
            "did not find %s function in lib %s: %s",
            func_to_run, lib_file, dlerror()
            );

    rc = func(data);
    check(rc != 0, "Function %s returned %d for data: %s",
            func_to_run, rc, data);

    rc = dlclose(lib);
    check(rc != 0, "failed to close %s", lib_file);

    return 0;

error:
    return -1;
}
