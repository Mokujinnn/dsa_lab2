#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>

#include "hashtab.h"

uint32_t hashtab_hash(char *key, size_t size)
{
    uint32_t h = 0, hash_mul = 31;

    while (*key)
    {
        h = h * hash_mul + (unsigned int)*key++;
    }

    return h % size;
}

void hashtab_init(listnode **hashtab, size_t size)
{
    for (int i = 0; i < size; i++)
    {
        hashtab[i] = NULL;
    }
}

void hashtab_add(listnode **hashtab, char *key, int value, size_t size)
{
    listnode *node;

    int index = hashtab_hash(key, size);
    node = malloc(sizeof(*node));
    if (node != NULL) 
    {
        node->key = key;
        node->value = value;
        node->next = hashtab[index];
        hashtab[index] = node;
    }
}

listnode *hashtab_lookup(listnode **hashtab, char *key, size_t size)
{
	listnode *node;
	
	int index = hashtab_hash(key, size);
	
	for (node = hashtab[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			return node;
		}
	}
	return NULL;
}

void hashtab_delete(listnode **hashtab, char *key, size_t size)
{
	listnode *node, *prev = NULL;
	
	int index = hashtab_hash(key, size);
	
	for (node = hashtab[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			if (prev == NULL)
				hashtab[index] = node->next;
			else
				prev->next = node->next;
				
			free(node);
			return;
		}
		
		prev = node;
	}
}



















