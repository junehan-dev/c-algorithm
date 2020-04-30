#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf; /* MEANS, pt start from allocatable. */

char *alloc(int n)
{
    if (allocbuf + ALLOCSIZE - allocp >= n) /* 1. if n size could be allocated in buf? */
    {
        allocp += n; /* 1.then. alloc n, and forwards n pt to allocp*/
        return allocp - n; /* 1.return. pt from alloc start. */
    }
    return 0;
}

void afree(char *p) 
{
    /*  expects alloc func ret pt to argument.
     *  store pointer before allocations with upper function,
     *  and when wish to restore current forwarded pt(allocp) to backward to certain timing.
     *  execute this function with argument you've stored somewhere.
     *  not erases mem data, but forwarding flag changes.
     *  
     *  when to use ``alloc()`` again after this modification,
     *  will alloc from function called ``afree(some_pt)``'s ``some_pt`` pointer. 
     * */
    if(p >= allocbuf && p < (allocbuf + ALLOCSIZE)) 
        allocp = p;
}
