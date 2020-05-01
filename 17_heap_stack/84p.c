#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 522 // 522%8byte=2
#define MAX_ROWS 100

struct Address {
    int id;
    int set;
    char name[MAX_DATA];
    char email[MAX_DATA];
};

struct Database {
    struct Address rows[MAX_ROWS];
};

struct Connection {
    FILE *file;
    struct Database *db;
};

void die(const char *msg)
{
    if(errno)
        perror(msg);
    else
        printf("Error: %s\n", msg);
    exit(1);
}

void Address_print(struct Address *addr)
{
    printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load(struct Connection *conn)
{
    int rc = fread(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("42_fread Failed to load DB");
}

struct Connection *Database_open(const char *filename, char mode) // 0 - open file and make Connection structure. with mode.
{
    struct Connection *conn = malloc(sizeof(struct Connection));
    if(!conn)
        die("49_malloc conn struction error");

    conn->db = malloc(sizeof(struct Database));
    if(!conn)
        die("55_malloc setting conn.db error");

    if(mode == 'c')
        conn->file = fopen(filename, "w");
    else
    {
        conn->file = fopen(filename, "r+");
        if(conn->file)
            Database_load(conn);
    }

    if ((conn->file) == NULL)
        die("67_malloc conn.file fopen link to structure error");

    return conn;
}

void Database_close(struct Connection *conn)
{
    // 1. close file pointer.(basically struct?, but stream based on fd.(fclose[file close by its pointer]))
    // 2. free db(struct)
    // 3. free conn(struct)
    if(conn)
    {
        if((conn->file) != NULL)
            fclose(conn->file);
        if(conn->db)
            free(conn->db);
        free(conn);
    }
}

void Database_write(struct Connection *conn)
{
    rewind(conn->file);

    int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
    if (rc != 1)
        die("91_fwrite failed to write db.");

    rc = fflush(conn->file);
    if (rc == -1)
        die("95_ffluse cannot flush file with file_pointer");
}

void Database_create(struct Connection *conn) // 1 - initializing all rows.
{
    int i;

    i = 0;

    while(i < MAX_ROWS)
    {
        // default for database, initializing
        struct Address addr = {.id = i, .set = 0};
        conn->db->rows[i] = addr;
        i++;
    }
}

void Database_set(struct Connection *conn, int id, const char *name, const char *email) // 1-1 set row by id, set name, email
{
    struct Address *addr = &(conn->db->rows[id]);
    if((addr->set) != 0)
        die("106_Database_set_addr by id, error: already set.");

    addr->set = 1;
    char *res;

    res = strncpy(&(addr->name[0]), name, MAX_DATA);
    if(res != &(addr->name[0]))
        die("111_strncpy set name by id, value ncpy error");

    res = strncpy(&(addr->email[0]), email, MAX_DATA);
    if(res != &(addr->email[0]))
        die("115_strncpy set email by id, value ncpy error");
}

void Database_get(struct Connection *conn, int id)
{
    struct Address *addr = &(conn->db->rows[id]);

    if(addr->set != 0)
        Address_print(addr);
    else
        die("124_attribute_error get_row by id and prints error, cause by set flag is 0");
}

void Database_delete(struct Connection *conn, int id)
{
    struct Address addr = {.id=id, .set=0};
    conn->db->rows[id] = addr;
}

void Database_list(struct Connection *conn)
{
    int i;
    struct Database *db;

    i = 0;
    db = conn->db;

    while(i < MAX_ROWS)
    {
        struct Address *cur = &(db->rows[i]);
        if(cur->set != 0)
            Address_print(cur);
        i++;
    }

}

int main(int argc, char *argv[])
{
    if (argc < 3)
        die("execution arguments-count error, USAGE: exe_file db_file <action> [action params]");

    char *filename = argv[1];
    char action = argv[2][0];
    
    struct Connection *conn = Database_open(filename, action);
    int id = 0;
    if (argc > 3)
        id = atoi(argv[3]);
    if (id >= MAX_ROWS)
        die("id over MAX allowed 100");

    switch(action)
    {
        case 'c': //creat
            Database_create(conn);
            Database_write(conn);
            break;
        case 'g': //get
            if(argc != 4)
                die("Need an id to get as first param");
            Database_get(conn, id);
            break;
        case 's': //set
            if(argc != 6)
                die("Need param as [id, name, email] to set row");
            Database_set(conn, id, argv[4], argv[5]);
            Database_write(conn);
            break;
        case 'd': //delete
            if(argc != 4)
                die("Need an id to delete as first param");
            Database_delete(conn, id);
            Database_write(conn);
            break;
        case 'l': //list
            Database_list(conn);
            break;
        default:
            die("action invalid error, c-g-s-d-l allowed as action param.");
    }
    Database_close(conn);
    return 0;
}

