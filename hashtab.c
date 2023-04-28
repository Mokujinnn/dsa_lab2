#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "hashtab.h"

uint32_t hashtab_hash(char *key, uint32_t size)
{
    uint32_t h = 0, hash_mul = 31;

    while (*key)
    {
        h = h * hash_mul + (unsigned int)*key++;
    }

    return h % size;
}

void hashtab_init(listnode **hashtab, uint32_t size)
{
    for (int i = 0; i < size; i++)
    {
        hashtab[i] = NULL;
    }
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
    listnode *node;

    int index = hashtab_hash(key);
    node = malloc(sizeof(*node));
    if (node != NULL) 
    {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}
