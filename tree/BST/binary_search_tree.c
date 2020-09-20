#include <stdio.h>
#include <stdlib.h>

#include "binary_search_tree.h"

void
bst_create(bst_t *t)
{
    *t = NULL;
}

void
bst_clean(bst_t *t)
{
    if (*t != NULL){
        bst_clean(&((*t)->lchild));
        bst_clean(&((*t)->rchild));
        free(*t);
    }
}

void
bst_destroy(bst_t *t)
{
    bst_clean(t);
}

bst_status_t
bst_insert(bst_t *t, bst_elem_t d)
{
    if (*t == NULL) {
        node_t tmp = malloc(sizeof(struct BST_NODE));
        if (tmp == NULL)
            return BST_MALLOC_FAILED;

        tmp->lchild = tmp->rchild = NULL;
        tmp->data = d;
        *t = tmp;
    } else {
        if ((*t)->data > d) {
            if (bst_insert(&((*t)->lchild), d) != BST_OK)
                return BST_MALLOC_FAILED;
        } else {
            if (bst_insert(&((*t)->rchild), d) != BST_OK)
                return BST_MALLOC_FAILED;
        }
    }
    return BST_OK;
} 
node_t
bst_find_min(bst_t t)
{
    node_t min = t;
    if (min == NULL)
        return min;
    while (min->lchild != NULL)
        min = min->lchild;
    return min;
}

node_t
bst_find_max(bst_t t)
{
    node_t max = t;
    if (max == NULL)
        return max;
    while (max->rchild != NULL)
        max = max->lchild;
    return max;
}

bst_status_t
bst_delete(bst_t *t, bst_elem_t d)
{
    if (*t == NULL)
        return BST_EMPTY;
    if ((*t)->data == d) {
        if ((*t)->lchild == NULL) {
            node_t tmp = *t;
            *t = (*t)->rchild;
            free(tmp);
        } else if ((*t)->rchild == NULL) {
            node_t tmp = *t;
            *t = (*t)->lchild;
            free(tmp);
        } else {
            node_t r_min = bst_find_min((*t)->rchild);
            node_t tmp;
            (*t)->data = r_min->data;
            //tmp = r_min;
            //r_min = r_min->rchild;
            //free(tmp);
            return bst_delete(&((*t)->rchild), r_min->data);
        }
        return BST_OK;
    } else if ((*t)->data > d) {
        return bst_delete(&((*t)->rchild), d);
    } else {
        return bst_delete(&((*t)->lchild), d);
    }
}

node_t 
bst_find(bst_t t, bst_elem_t d)
{
    if (t == NULL)
        return NULL;
    if (t->data == d) {
        return t;
    } else if (t->data > d) {
        return bst_find(t->lchild, d);
    } else {
        return bst_find(t->rchild, d);
    }
}

bst_status_t
bst_pre_trav(bst_t t, visit_handle_t visit)
{
    if (t == NULL)
        return BST_OK;
           
    if (visit(t->data) == BST_OK)
        if (bst_pre_trav(t->lchild, visit) == BST_OK)
            if(bst_pre_trav(t->rchild, visit) == BST_OK)
                return BST_OK;
    return BST_ACCESS_FAILED;
}
bst_status_t
bst_mid_trav(bst_t t, visit_handle_t visit)
{
    if (t == NULL)
        return BST_OK;
           
    if (bst_mid_trav(t->lchild, visit) == BST_OK)        
        if (visit(t->data) == BST_OK)
            if(bst_mid_trav(t->rchild, visit) == BST_OK)
                return BST_OK;
    return BST_ACCESS_FAILED;
}

bst_status_t
bst_post_trav(bst_t t, visit_handle_t visit)
{
    if (t == NULL)
        return BST_OK;
           
    if (bst_post_trav(t->lchild, visit) == BST_OK)        
        if(bst_post_trav(t->rchild, visit) == BST_OK)
            if (visit(t->data) == BST_OK)
                return BST_OK;
    return BST_ACCESS_FAILED;
}