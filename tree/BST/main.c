#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

#define BST_NODE_NUM 8

bst_status_t
print_bst_elem(bst_elem_t d)
{
    printf("%d\t", d);
    return BST_OK;
}

int
main(int argc, char* argv[])
{
    bst_t bst;
    int   tmp[BST_NODE_NUM];
    bst_create(&bst);
    
    for (int i = 0; i < BST_NODE_NUM; i++) {
        tmp[i] = random() % 100;
        printf("%d\t", tmp[i]);
        bst_insert(&bst, tmp[i]);
    }
    printf("\n");
    bst_mid_trav(bst, print_bst_elem);
    printf("\n");
    bst_delete(&bst, tmp[0]);
    bst_mid_trav(bst, print_bst_elem);

    bst_destroy(&bst);
    return 0;
}