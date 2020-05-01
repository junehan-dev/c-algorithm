#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
    int died;
//    char sex;
};

struct Person *create_person(char *name, int a, int h, int w,
        //char s,
        int d)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = a;
    who->height = h;
    who->weight = w;
//    who->sex = s;
    who->died = d;

    return who;
}

void destroy_person(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void print_person(struct Person *who)
{
    printf("by struct pt;\n");
    printf("name: %s, size:%ld\n", who->name, sizeof(who->name));
    printf("age: %d, size:%ld\n", who->age, sizeof(who->age));
    printf("height: %d, size:%ld\n", who->height, sizeof(who->height));
    printf("wight: %d, size:%ld\n", who->weight,sizeof(who->weight));
//    printf("sex: %c, size:%ld\n", who->sex,sizeof(who->sex));
    printf("size of %s: %ld\n",who->name, sizeof(who));
    printf("\n");
}

void print_members(struct Person who)
{
    printf("by struct value;\n");
    printf("name: %s, size:%ld\n", who.name, sizeof(who.name));
    printf("age: %d, size:%ld\n", who.age, sizeof(who.age));
    printf("height: %d, size:%ld\n", who.height, sizeof(who.height));
    printf("wight: %d, size:%ld\n", who.weight,sizeof(who.weight));
//    printf("sex: %c, size:%ld\n", who.sex, sizeof(who.sex));
    printf("size of %s: %ld\n",who.name, sizeof(who));
    printf("\n");
}

int main(int argc, char *argv[])
{
    struct Person *joe = create_person("joe Alex", 32, 64, 140,
            //'f',
            80);
    struct Person *frank = create_person("Frank Blank junoir", 20, 52, 180,
            //'m',
            64);

    printf("joe mem alloc loc: %p\n", joe);
    print_person(joe);
    print_members(*joe);
    printf("frank mem alloc loc: %p\n", frank);
    print_person(frank);
    print_members(*frank);

    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    print_person(joe);

    destroy_person(joe);
    destroy_person(frank);
    char str[12] = "sample12";
    char *str_pt = "sample2";
    printf("size of str[]: %ld\n", sizeof(str));
    printf("size of str_pt: %ld\n", sizeof(*str_pt));
    int i;
    i = 0;
    while(i<15)
    {
        printf("%d: %d\n", i, str[i++]);
    }

}
