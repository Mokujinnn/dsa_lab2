#include <stdint.h>
#include <stdlib.h>

typedef struct Listnode 
{
    char *key;
    uint32_t value;

    struct Listnode *next;
} listnode;

uint32_t hashtab_hash(char *key, size_t size);
void hashtab_init(listnode **hashtab, size_t size);
void hashtab_add(listnode **hashtab, char *key, int value, size_t size);
listnode hashtab_lookup(listnode **hashtab, char *key, size_t size);
void hashtab_delete(listnode **hashtab, char *key, size_t size);
