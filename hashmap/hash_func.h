#ifndef _HASH_FUNC_H_
#define _HASH_FUNC_H_

#include "hashmap.h"

extern size_t hash_linear(ht_key_t key, size_t ht_size, int i);
extern size_t hash_2order(ht_key_t key, size_t ht_size, int i);
extern size_t hash_again(ht_key_t key, size_t ht_size, int i);

#endif