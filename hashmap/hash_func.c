#include <stdio.h>
#include <stdlib.h>

#include "hash_func.h"

size_t 
hash_linear(ht_key_t key, size_t ht_size, int i)
{
    size_t index;

    index = key % ht_size + i;
    
    return (index % ht_size);
}

size_t
hash_2order(ht_key_t key, size_t ht_size, int i)
{
    size_t index;
    int tmp;
    
    tmp = i * i + i;
    
    index = key % ht_size + tmp;

    return (index % ht_size);
}

size_t
hash_again(ht_key_t key, size_t ht_size, int i)
{
    int h1, h2;
    int index;

    h1 = key % ht_size;
    h2 = key % (ht_size-1) + 1;

    index = h1 + i * h2;

    return (index % ht_size);
}