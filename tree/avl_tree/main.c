#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "avl_tree.h"

#define AVL_TREE_VAL_LIMIT  100
#define AVL_TREE_NODE_NUM   10

void print_avl_elem(avl_elem_t val)
{
    printf("%d\t", val);
}

int
main(void)
{
    int i;
    avl_elem_t val[AVL_TREE_NODE_NUM];

    avl_tree_t root = NULL;

    srand(time(NULL));

    avl_tree_create(&root);
    printf("create a avl tree.\n");

    for (i = 0; i < AVL_TREE_NODE_NUM; i++) {
        val[i] = rand() % AVL_TREE_VAL_LIMIT;
        root = avl_insert(root, val[i]);
        printf("%d. insert \t%d\t to avl tree.\n", i, val[i]);
    }

    printf("print avl tree:\n");    
    avl_mid_trav(root, print_avl_elem);
    printf("\n");

    printf("delete %d from avl tree.\n", val[0]);
    root = avl_delete(root, val[0]);
    
    printf("print avl tree:\n");    
    avl_mid_trav(root, print_avl_elem);   
    printf("\n");

    return 0;
}