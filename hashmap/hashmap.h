#ifndef _HASH_MAP_H_
#define _HASH_MAP_H_

#include <stdlib.h>

typedef int ht_key_t;             // hash table key type
typedef int ht_val_t;             // hash table data type
typedef size_t (*hash_func_t)(ht_key_t key, size_t ht_size, int i);        // hash fucntion

enum ELEM_STATUS {
    VALID,
    EMPTY,
    INVALID
};
typedef enum ELEM_STATUS elem_status_t;

struct HASH_ELEM {
    ht_key_t      key;
    ht_val_t      val;
    elem_status_t   status;
};
typedef struct HASH_ELEM ht_elem_t;

enum HASH_STATUS {
    HT_OK,
    HT_EMPTY,
    HT_FULL,
    HT_KEY_REPEAT,
    HT_MALLOC_FAILED,
    HT_ACCESS_FAILED
};
typedef enum HASH_STATUS ht_status_t;

struct HASH_TABLE {
    ht_elem_t   *t;
    size_t      size;
    hash_func_t hash_func;
    ht_status_t status;
    size_t      usage;
};
typedef struct HASH_TABLE *hash_table_t;

#define HASH_MIN_SIZE   (101)
#define LOAD_FACTOR     (0.8)

extern hash_table_t ht_create(size_t size, hash_func_t hash);
extern int ht_insert(hash_table_t ht, ht_key_t key, ht_val_t val);
extern int ht_remove(hash_table_t ht, ht_key_t key);
extern int ht_search(hash_table_t ht, ht_key_t key);
extern int ht_is_empty(hash_table_t ht);
extern size_t ht_size(hash_table_t ht);
extern void ht_destroy(hash_table_t *ht);
extern void ht_print(hash_table_t ht);
#endif