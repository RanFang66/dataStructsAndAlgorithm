#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

typedef int avl_elem_t;

struct AVL_TREE_NODE {
    avl_elem_t              data;
    struct AVL_TREE_NODE    *lch;
    struct AVL_TREE_NODE    *rch;
    int                     height;
};
typedef struct AVL_TREE_NODE avl_node_t, *avl_tree_t;

enum AVL_STATUS {
    AVL_OK,
    AVL_MALLOC_FAILED,
    AVL_EMPTY,
    AVL_ACCESS_FAILED
};
typedef enum AVL_STATUS avl_status_t; 

typedef void (*visit_func_t)(avl_elem_t val);

extern avl_status_t avl_tree_status;

extern void avl_tree_create(avl_tree_t *root);
extern avl_tree_t avl_insert(avl_tree_t root, avl_elem_t data);
extern avl_tree_t avl_delete(avl_tree_t root, avl_elem_t data);
extern avl_node_t* avl_search(avl_tree_t root, avl_elem_t data);
extern void avl_pre_trav(avl_tree_t root, visit_func_t visit);
extern void avl_mid_trav(avl_tree_t root, visit_func_t visit);
extern void avl_post_trav(avl_tree_t root, visit_func_t visit);

#endif
