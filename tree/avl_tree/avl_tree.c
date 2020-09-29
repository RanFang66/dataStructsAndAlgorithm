#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

#define TREE_HEIGHT(p) ((p == NULL) ? 0 : (((avl_node_t*)(p))->height))
#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define HEIGHT_UPDATE(p) (MAX(TREE_HEIGHT(p->lch), TREE_HEIGHT(p->rch)) + 1)

avl_status_t avl_tree_status = AVL_OK;

void
avl_tree_create(avl_tree_t* root)
{
    *root = NULL;
}

static int
avl_height_update(avl_node_t *node)
{
    if(node == NULL)
        return 0;
    if (node->lch == NULL && node->rch == NULL)
        node->height = 1;
    else if (node->lch == NULL)
        node->height = node->rch->height+1;
    else if (node->rch == NULL)
        node->height = node->lch->height+1;
    else
        node->height = HEIGHT_UPDATE(node);
    return node->height;
}

static avl_node_t* 
avl_create_node(avl_elem_t val, avl_node_t *lch, avl_node_t *rch)
{
    avl_node_t *p;
    if ((p = malloc(sizeof(struct AVL_TREE_NODE))) == NULL)
        return NULL;

    p->data = val;
    p->lch = lch;
    p->rch = rch;
    p->height = 0;//avl_height_update(p);
    
    return p;
}

int 
avl_tree_height(avl_tree_t root)
{
    return TREE_HEIGHT(root); 
}

static avl_node_t*
LL_rotation(avl_tree_t t)
{
    avl_node_t *p;
    p = t->lch;
    t->lch = p->rch;
    p->rch = t;

    t->height = HEIGHT_UPDATE(t);
    p->height = HEIGHT_UPDATE(p);

    return p;
}

static avl_node_t*
RR_rotation(avl_tree_t t)
{
    avl_node_t *p;

    p = t->rch;
    t->rch = p->lch;
    p->lch = t;

    t->height = HEIGHT_UPDATE(t);
    p->height = HEIGHT_UPDATE(p);

    return p;
}

static avl_node_t*
LR_rotation(avl_tree_t t)
{
    t->lch = RR_rotation(t->lch);
    return LL_rotation(t);
}

static avl_node_t*
RL_rotation(avl_tree_t t)
{
    t->rch = LL_rotation(t->rch);
    return RR_rotation(t);
}

avl_tree_t
avl_insert(avl_tree_t t, avl_elem_t data)
{
    if (t == NULL) {
        t = avl_create_node(data, NULL, NULL);
        if (t == NULL) {
            avl_tree_status = AVL_MALLOC_FAILED;
            return NULL;
        }
    } else if (t->data > data) {
        t->lch = avl_insert(t->lch, data);  // insert the node to left child tree
        if (TREE_HEIGHT(t->lch) - TREE_HEIGHT(t->rch) >= 2) {
            if (t->lch->data > data)        // insertion occured at left-left child
                t = LL_rotation(t);
            else                            // insertion occured at left-right child
                t = LR_rotation(t);
        }
    } else {
        t->rch = avl_insert(t->rch, data);  //insert the node to right child tree
        if (TREE_HEIGHT(t->rch) - TREE_HEIGHT(t->lch) >= 2) {
            if (t->rch->data > data)        //insertion occured at right-left child
                t = RL_rotation(t);
            else                            //insertion occured at right-right child
                t = RR_rotation(t);
        }
    }
    t->height = HEIGHT_UPDATE(t);
    
    return t;
}

static avl_tree_t
avl_find_max(avl_tree_t t)
{
    avl_node_t *max = t;
    if (t == NULL)
        return NULL;

    while (max->rch)
        max = max->rch;

    return max;
}

static avl_node_t*
avl_find_min(avl_tree_t t)
{
    avl_node_t *min = t;
    if (t == NULL)
        return NULL;
    while (min->lch)
        min = min->lch;

    return min;
}

static avl_node_t*
avl_search(avl_tree_t t, avl_elem_t val)
{
    avl_node_t *node = t;
    
    while (node != NULL && node->data != val) {
        if (node->data > val) {
            node = node->lch;
        } else {
            node = node->rch;
        }
    }

    return node;
}

static avl_tree_t
avl_delete_node(avl_tree_t t, avl_node_t *node)
{
    if (t == NULL || node == NULL)
        return NULL;

    if (node->data < t->data) {
        t->lch = avl_delete_node(t->lch, node);
        if (TREE_HEIGHT(t->rch) - TREE_HEIGHT(t->lch) >= 2) {
            avl_node_t *tmp = t->rch;
            if (TREE_HEIGHT(tmp->lch) > TREE_HEIGHT(tmp->rch))
                t = RL_rotation(t);
            else
                t = RR_rotation(t);
        }
    } else if (node->data > t->data) {
        t->rch = avl_delete_node(t->rch, node);
        if (TREE_HEIGHT(t->lch) - TREE_HEIGHT(t->rch) >= 2) {
            avl_node_t *tmp = t->lch;
            if (TREE_HEIGHT(tmp->lch) > TREE_HEIGHT(tmp->rch))
                t = LL_rotation(t);
            else
                t = LR_rotation(t);
        }
    } else {
        if ((t->lch) && (t->rch)) {      // left child and right child are both no-NULL
            if (TREE_HEIGHT(t->lch) > TREE_HEIGHT(t->rch)) {
                avl_node_t *max = avl_find_max(t->lch);
                t->data = max->data;
                t->lch = avl_delete_node(t->lch, max);
            } else {
                avl_node_t *min = avl_find_min(t->rch);
                t->data = min->data;
                t->rch = avl_delete_node(t->rch, min);
            }
        }
        else {
            avl_node_t *tmp = t;
            t = t->lch ? t->lch : t->rch;
            free(tmp);
        }
    }

    return t;
}

avl_tree_t
avl_delete(avl_tree_t t, avl_elem_t data)
{
    avl_node_t *node;
    if ((node = avl_search(t, data)) == NULL) {
        avl_tree_status = AVL_EMPTY;
        return NULL;
    }
    avl_delete_node(t, node);

    return t;
}

void
avl_mid_trav(avl_tree_t root, visit_func_t visit)
{
    if (root != NULL) {
        avl_mid_trav(root->lch, visit);
        visit(root->data);
        avl_mid_trav(root->rch, visit);
    }
}

void
avl_pre_trav(avl_tree_t root, visit_func_t visit)
{
    if (root != NULL) {
        visit(root->data);
        avl_pre_trav(root->lch, visit);
        avl_pre_trav(root->rch, visit);
    }
}

void
avl_post_trav(avl_tree_t root, visit_func_t visit)
{
    if (root != NULL) {
        avl_post_trav(root->lch, visit);
        avl_post_trav(root->rch, visit);
        visit(root->data);
    }
}