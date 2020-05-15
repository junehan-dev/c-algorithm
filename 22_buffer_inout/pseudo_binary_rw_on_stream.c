#include <stdio.h>

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

    /*
     *  1. writeable stream(out_stream) call with fopen();
     *      FILE *fopen(char *name, int mode);
     *      - check fp validation
     *
     *  2. write blackbeard structure itself with calling it's pt
     *      size_t times = 1;
     *      size_t writtens = fwrite(&blackbeard, sizeof(struct pirate), times, out_stream);
     *      if (written != times)
     *          perror ("");
     *      fclose(outstream);
     *          // fclose returns 0 if closed(buffer data passed to kernel)
     *          // if not? return non 0 and set errno to appropriate one.
     *
     *  -- done binary writting.
     *
     *  1. readable stream(in_stream) call.
     *      - check fp validation
     *
     *  2. fread(&p, sizeof(struct pirate), 1, in_stream);
     *      same prcedure to check count of returned value.
     *  
     *  3. print p.
     *
     *  4. close fp in_stream;
     */
    printf("bufsize: %d", BUFSIZ);
}
