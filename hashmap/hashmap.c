#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"
#include <math.h>

#define     TRUE    (1)
#define     FALSE   (0)
#define     FAILED  (-1)

const int prime_table[] = {
                3, 7, 11, 17, 23, 29, 37, 47, 59, 71, 89, 107, 131, 163, 197, 239, 293, 353, 431, 521, 631, 761, 919, 
                1103, 1327, 1597, 1931, 2333, 2801, 3371, 4049, 4861, 5839, 7013, 8419, 10103, 12143, 14591, 
                17519, 21023, 25229, 30293, 36353, 43627, 52361, 62851, 75431, 90523, 108631, 130363, 156437,
                187751, 225307, 270371, 324449, 389357, 467237, 560689, 672827, 807403, 968897, 1162687, 1395263, 
                1674319, 2009191, 2411033, 2893249, 3471899, 4166287, 4999559, 5999471, 7199369
};

static int
is_prime(int n)
{
    if ((n & 1) != 0) {
        int limit = sqrt(n);
        for (int i = 3; i <= limit; i += 2) {
            if (n % i == 0)
                return FALSE;
        }
        return TRUE;
    }
    return (n == 2);
}

static int 
get_next_prime(int min)
{
    int i = 0;
    int prime;
    int len = sizeof(prime_table);

    for (i = 0; i < len; i++) {
        prime = prime_table[i];
        if (prime > min)
            return prime;
    }
    
    return prime_table[i-1];
}

hash_table_t
ht_create(size_t size, hash_func_t hash)
{
    hash_table_t ht;
    if ((ht = malloc(sizeof(struct HASH_TABLE))) == NULL) {
//        ht->status = HT_MALLOC_FAILED;
        return NULL;
    }

    if (size < HASH_MIN_SIZE) {
        size = HASH_MIN_SIZE;
    } else {
        size = is_prime(size) ? size : get_next_prime(size);
    }
    if ((ht->t = malloc(sizeof(struct HASH_ELEM) * size)) == NULL) {
//        ht->status = HT_MALLOC_FAILED;
        return NULL;
    }
    ht->size = size;
    ht->usage = 0;
    ht->hash_func = hash;
    ht->status = HT_OK;

    for (int i = 0; i < size; i++) {
        ht->t[i].key = 0;
        ht->t[i].val = 0;
        ht->t[i].status = EMPTY;
    }
    return ht;
}

int 
ht_insert(hash_table_t ht, ht_key_t key, ht_val_t val)
{
    size_t  index;
    int     i = 0;

    if (ht->usage >= ht->size * LOAD_FACTOR) {
        ht->status = HT_FULL;
        return FAILED;
    }   

    do {
        index = ht->hash_func(key, ht->size, i);

        if (ht->t[index].status != VALID) {
            ht->t[index].key = key;
            ht->t[index].val = val;
            ht->t[index].status = VALID;
            ht->usage++;
            return index;
        } else {
            if (ht->t[index].key == key) {
                ht->status = HT_KEY_REPEAT;
                return FAILED;
            }
            i++;
        }
    } while(i < ht->size);

    return FAILED;
}

int
ht_search(hash_table_t ht, ht_key_t key)
{
    int index;
    int i = 0;

    if (ht->usage == 0)
        return FAILED;

    do {
        index = ht->hash_func(key, ht->size, i);
        if (ht->t[index].key == key)
            return index;
        
        if (ht->t[index].status == EMPTY)
            return FAILED;

        i++;
    } while (i < ht->size);
    return FAILED;
}

int
ht_remove(hash_table_t ht, ht_key_t key)
{
    int index;
    int i = 0;

    if ((index = ht_search(ht, key)) == -1) {
        return FAILED;
    }
    ht->t[index].status = INVALID;
    ht->usage--;

    return index;
}

int 
ht_is_empty(hash_table_t ht)
{
    return (ht->usage == 0);
}

size_t 
ht_size(hash_table_t ht)
{
    return (ht->usage);
}

void 
ht_destroy(hash_table_t *ht)
{
    free((*ht)->t);
    free((*ht));
}

void
ht_print(hash_table_t ht)
{
    int i;

    printf("---print hash table---\n");
    for (i = 0; i < ht->size; i++){
        if (ht->t[i].status == VALID)
            printf("key = %d,\t index = %d,\t value = %d\n", ht->t[i].key, i, ht->t[i].val);
    }

    printf("---print end---\n");
}