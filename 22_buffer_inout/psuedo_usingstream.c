#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 128

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor; // automatically set name as value 0~4 ?

const char *EYE_C_NAMES[] = {
    "Blue", "Green", "BROWN", "Black", "Other"
}

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[]){
    /*
     *  1. Person newone = {.age = 0 }.
     *
     *  2. int i = 0;
     *
     *  3. char *in = NULL;
     *
     *  - program
     *      1. get Firstname from stdin(fp). not STDIN_FILENO(fd). using fgets().
     *      2  store in newone.first_name;
     *          - fgets() return value validation check
     *      3. get last_name likewise.
     *
     *      4. get age using fscanf() from stdin; // store returned value in variable rc.
     *      5. store in in newone.age.
     *          - validation of returned value.
     *
     *      6. i = 0; print EyeColor[i+1]; while i<=OTHER_EYES//4;
     *      7. get int from stdin using fscanf. also store it int to ``int eyes = -1``
     *          - eyes variable should store actual index of EYE_C_NAMES.
     *          - validation of return value.
     *          - validation of stored value is 0~4;
     *      
     *      8. get income from stdin usign fscanf // and store into rc
     *          - check rc is floating point number with fscanf(stdin, "%f", &newone.income);
     *          - income is float type in struct Person
     *
     *  int fscanf(FILE *stream, const char *format, ...);
     *      read buf til \n found. and store it in to after third arguments.
     *      if type conversion format exceeds, retsult is undefined.
     *      on sucess: returns number of input items(matched and assigned).
     *          so if none is assigned or matched, returns 0
     *      - EOF retured
     *          - end of input is reached is reached before first conversion or matching failure occurs. (like nothing input). 
     *          - read error occurs, errno is set to indicate the error. message from ferror() not perror().
     */
}
