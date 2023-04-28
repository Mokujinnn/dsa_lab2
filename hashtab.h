#include <stdint.h>

typedef struct Listnode 
{
    char *key;
    uint32_t value;

    struct Listnode *next;
} listnode;

uint32_t hashtab_hash(char *key, uint32_t size);
void hashtab_init(listnode **hashtab, uint32_t size);