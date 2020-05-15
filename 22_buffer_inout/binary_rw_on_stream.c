#include <stdio.h>
#include "dbg.h"

void stat_pirate(void *obj);
int main(void)
{
    FILE *in_stream, *out_stream;
    struct pirate {
        char name[100];
        unsigned long bt;
        unsigned int beard_len;
    };
    struct pirate p;
    struct pirate blackbeard = {"Edward Teach", 950, 48};

    out_stream = fopen("./structs_pirates", "w");
    if(!out_stream)
        log_err("out_stream not opened!");
    
    // write &blackbeard.
    size_t written;
    size_t times;
    times = 1;
    written = fwrite(&blackbeard, sizeof(struct pirate), times, out_stream);
    // return tiems.
    if(written != times)
        log_err("not written 1time!");
    fclose(out_stream);
    
    in_stream = fopen("./structs_pirates", "r");
    if(!in_stream)
        log_err("in_stream not opened.");
    
    size_t allocated;
    allocated = fread(&p, sizeof(struct pirate), times, in_stream);
    if (allocated != times)
        log_err("err!");

    
    size_t len;
    char *name_pt;
    name_pt = (char *)(&p);
    len = 0;
    char *bt_pt; 
    bt_pt = (char *)(&p.bt);
    while(name_pt != bt_pt)
    {
        printf("offsets:%ld : %c\t", len, *name_pt);
        len++;
        name_pt++;
    }
    printf("fullsize: %ld\n", sizeof(struct pirate));
    printf("bt:%ld", p.bt);
    int ret = fclose(in_stream);
    if(!ret)
        perror("not closed!");
    return 0;
}
