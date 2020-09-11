#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

tree_status_t print_elem(telem_t d);

int
main(int argc, char* argv[])
{
    tree_t t;

    if (tree_create(&t))
        printf("Create a tree successfully.\n");

    printf("The pre-order traverse of tree:\n");
    preorder_traverse(t, print_elem);
    putchar('\n');

    printf("The in-order traverse of tree:\n");
    inorder_traverse(t, print_elem);
    putchar('\n');

    printf("The post-order traverse of tree:\n");
    postorder_traverse(t, print_elem);
    putchar('\n');

    printf("The level-order traverse of tree:\n");
    levelorder_traverse(t, print_elem);
    putchar('\n');

    tree_destroy(t);
    printf("Tree is destroyed");

    return 0;
}

tree_status_t
print_elem(telem_t d)
{
    printf("%c\t", d);
    return TREE_OK;
}
