#include <stdio.h>
#include <stdlib.h>

#include "hashtab.h"

#define SIZES 7

int main()
{
    int sizes[SIZES] = {5051, 12289, 24593, 49157, 98317, 196613, 393241};
    int cur_size = 0;
    float factor = 0.75;
    listnode **hashtab = malloc(sizeof(listnode) * sizes[cur_size]);
    
    hashtab_init(hashtab, sizes[cur_size]);

    return 0;
}