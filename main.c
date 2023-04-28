#include <stdio.h>
#include <stdlib.h>

#include "hashtab.h"


int main()
{
    int sizes[] = {10007, 20011, 30011, 40009, 50021, 60013, 70001,
	80021, 90001, 100003, 110017, 120011, 130003, 140009, 150001, 160001,
	170003, 180001, 190027, 200003};
    int cur_size = 0;
    listnode *hashtab[cur_size];
    
    hashtab_init(hashtab, sizes[cur_size]);

    return 0;
}
