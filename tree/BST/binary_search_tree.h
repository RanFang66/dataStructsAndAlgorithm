#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

typedef int bst_elem_t;

struct BST_NODE {
    bst_elem_t     data;
    struct BST_NODE *lchild;
    struct BST_NODE *rchild;
};
typedef struct BST_NODE *node_t, *bst_t;

enum BST_STATUS {
    BST_OK,
    BST_EMPTY,
    BST_MALLOC_FAILED,
    BST_ACCESS_FAILED
};
typedef enum BST_STATUS bst_status_t;

typedef bst_status_t (*visit_handle_t)(bst_elem_t d);

extern void bst_create(bst_t *t);
extern void bst_clean(bst_t *t);
extern void bst_destroy(bst_t *t);
extern bst_status_t bst_insert(bst_t *t, bst_elem_t d); 
extern bst_status_t bst_delete(bst_t *t, bst_elem_t d);
extern node_t bst_find(bst_t t, bst_elem_t d);
extern bst_status_t bst_pre_trav(bst_t t, visit_handle_t visit);
extern bst_status_t bst_mid_trav(bst_t t, visit_handle_t visit);
extern bst_status_t bst_post_trav(bst_t t, visit_handle_t visit);
extern bst_status_t bst_layer_trav(bst_t t, visit_handle_t visit);

#endif /* _BINARY_SEARCH_TREE_H_ */