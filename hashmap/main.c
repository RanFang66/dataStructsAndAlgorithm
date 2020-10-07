#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hashmap.h"
#include "hash_func.h"

#define MY_HT_SIZE      (197)     

int
main(int argc, char* argv[])
{
    hash_table_t ht;
    hash_func_t  hf;
    int data[10];

    srand(time(NULL));

    if (argc < 2) {
        hf = hash_again;
    } else {
        int tmp = atoi(argv[1]);
        switch (tmp) {
        case 1:
            hf = hash_linear;
            break;
        case 2:
            hf = hash_2order;
            break;
        case 3:
            hf = hash_again;
            break;
        default:
            hf = hash_again;
            break;
        }
    }
    ht = ht_create(MY_HT_SIZE, hash_linear);
    printf("Creat a hash table with size %zu.\n", ht->size);

    for (int i = 0; i < 10; i++) {
        data[i] = rand() % 1000;
        ht_insert(ht, data[i], data[i]-1);
    }    
    printf("Insert %zu elements to hash table.\n", ht->usage);
    
    ht_print(ht);

    ht_remove(ht, data[0]);
    printf("Remove the element key = %d from hash table.\n", data[0]);

    ht_print(ht);

    printf("Destroy the hash table.\n");
    ht_destroy(&ht);

    return 0;

}