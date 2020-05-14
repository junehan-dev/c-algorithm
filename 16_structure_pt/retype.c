#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name; // 8bytes
    int age; // 4bytes
    int height; // 4bytes
    int weight; // 4bytes
};

struct Person *creat_person(const char *name, int a, int h, int w)
{
    /*
     *  1. malloc size of person and return it.
     *      - reason to use malloc to alloc structure?
     *          1. many otherplace should allowed to create in equality.
     *          2. if not using malloc(heap allocation), could not return data stored.
     *              - stack releases its local variable while it end.    
     */
    struct Person *created = malloc(sizeof(struct Person));
    assert(created != NULL); //NULL stdio.h defined.
    /*
     *  #include <assert.h>
     *  void assert(scalar expression);
     *
     *  expression as argument should be true.
     *      if false? stderr gets a message and terminates the program by calling abort().
     */ 

    created->name = strdup(name); // copy with malloc
    /*
     *  #include <string.h>
     *  char *strdup(const char *s);
     *  
     *  returns pointer to new string dupliate of the string s.
     *  memory obtained with malloc should be freed with free()
     */
    created->age = a;
    created->height = h;
    created->weight = w;
    return (created);
}

void update_with_value(struct Person someone)
{
    struct Person *pt;
    pt = &someone;
    printf("value_ref:%p\n", pt);
    pt->age += 1;
}
void update_with_mem_location(struct Person *someone)
{
    printf("pt_val:%p\n", someone);
    someone->age += 1;
}

void stat_person(struct Person someone)
{
    printf("name: %s\n, size:%ld, loc:%p\n", someone.name, sizeof(someone.name), &(someone.name));
    printf("age: %d\tweigth: %d\theight: %d, size:%ld\n", someone.age, someone.weight, someone.height, sizeof(someone.age));
    printf("someone-size:%ld\n\n", sizeof(someone));
}

void free_person_with_pointer(struct Person *who)
{
    free(who->name);
    free(who);
}

void stat_person_origin(struct Person *someone)
{
    printf("name: %s\n, size:%ld, loc:%p\n", someone->name, sizeof(someone->name), someone->name);
}

int main()
{
    struct Person *me = creat_person("june han", 30, 171, 68);
    printf("me:%p name:%p\n", me, me->name);
    stat_person(*me);
    update_with_value(*me);
    printf("value-location updated age by one.\n");
    stat_person(*me);
    update_with_mem_location(me);
    stat_person(*me);
    stat_person_origin(me);
    free_person_with_pointer(me);
    return 0;
}
