#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

typedef char telem_t;
struct TREE_NODE {
    telem_t data;
    struct TREE_NODE *lchild, *rchild;
};
typedef struct TREE_NODE tree_node, *tree_t;

enum TREE_STATUS {
    TREE_OK,
    TREE_MALLOC_FAILED,
    TREE_EMPTY,
    TREE_ACCESS_FAILED
};
typedef enum TREE_STATUS tree_status_t;

extern tree_status_t tree_create(tree_t *T);
extern tree_status_t preorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d));
extern tree_status_t inorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d));
extern tree_status_t postorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d));
extern tree_status_t levelorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d));
extern void tree_destroy(tree_t T);

#endif /* _BINARY_TREE_H_  */
