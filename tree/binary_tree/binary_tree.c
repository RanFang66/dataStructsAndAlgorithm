#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "queue.h"
#include "stack.h"

tree_status_t
tree_create(tree_t *T)
{
    char ch;

    ch = getchar();
    if (ch == ' ') {
        *T = NULL;
    } else {
        *T = malloc(sizeof(struct TREE_NODE));
        if (*T == NULL)
            return TREE_MALLOC_FAILED;
        (*T)->data = ch;
        if (tree_create(&((*T)->lchild)) != TREE_OK)
            return TREE_MALLOC_FAILED;
        if (tree_create(&((*T)->rchild)) != TREE_OK)
            return TREE_MALLOC_FAILED;
    }
    return TREE_OK;
}

tree_status_t
preorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d))
{
    if (T) {
        if (visit(T->data) == TREE_OK)
            if (preorder_traverse(T->lchild, visit) == TREE_OK)
                if (preorder_traverse(T->rchild, visit) == TREE_OK)
                    return TREE_OK;
        return TREE_ACCESS_FAILED;
    } else {
        return TREE_OK;
    }
}

tree_status_t
inorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d))
{
    if (T) {
        if (inorder_traverse(T->lchild, visit) == TREE_OK)
            if (visit(T->data) == TREE_OK)
                if (inorder_traverse(T->rchild, visit) == TREE_OK)
                    return TREE_OK;
        return TREE_ACCESS_FAILED;
    } else {
        return TREE_OK;
    }
}

tree_status_t
postorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d))
{
    if (T) {
        if (postorder_traverse(T->lchild, visit) == TREE_OK)
            if (postorder_traverse(T->rchild, visit) == TREE_OK)
                if (visit(T->data) == TREE_OK)
                    return TREE_OK;
        return TREE_ACCESS_FAILED;
    } else {
        return TREE_OK;
    }
}

tree_status_t
levelorder_traverse(tree_t T, tree_status_t (*visit)(telem_t d))
{
    queue_t q;
    tree_t front;
    queue_init(&q, 100);
    if (!T)
        return TREE_EMPTY;
    queue_en(q, T);
    while(!queue_is_empty(q)) {
        queue_de(q, &front);
        if (front->lchild)
            queue_en(q, front->lchild);
        if (front->rchild)
            queue_en(q, front->rchild);
        visit(front->data);
    }
    return TREE_OK;
}

tree_status_t
preorder_unrecursive(tree_t T, tree_status_t (*visit)(telem_t d))
{
    stack_t s;
    tree_t  cur;

    if (T == NULL)
        return TREE_EMPTY;

    stack_init(&s, 100);
    cur = T;
    while (cur || !stack_is_empty(s)) {
        while (cur) {
            if (visit(cur->data) != TREE_OK)
                return TREE_ACCESS_FAILED;
            stack_push(s, cur);
            cur = cur->lchild;
        }
        stack_pop(s, &cur);
        cur = cur->rchild;
    }
    stack_free(&s);

    return TREE_OK;
}

tree_status_t
inorder_unrecursive(tree_t T, tree_status_t (*visit)(telem_t d))
{
    stack_t s;
    tree_t  cur;

    if (T == NULL)
        return TREE_EMPTY;

    stack_init(&s, 100);
    cur = T;
    while (cur || !stack_is_empty(s)) {
        while (cur) {
            stack_push(s, cur);
            cur = cur->lchild;
        }

        stack_pop(s, &cur);
        visit(cur->data);
        cur = cur->rchild;
    }
    stack_free(&s);

    return TREE_OK;
}

tree_status_t
postorder_unrecursive(tree_t T, tree_status_t (*visit)(telem_t d))
{
    stack_t s;
    tree_t  cur, last, top;

    if (T == NULL)
        return TREE_EMPTY;

    stack_init(&s, 100);
    cur = T;
    while (cur || !stack_is_empty(s)) {
        while (cur) {
            stack_push(s, cur);
            cur = cur->lchild;
        }
        stack_get(s, &top);

        if (top->rchild == NULL || top->rchild == last) {
            stack_pop(s, &top);
            visit(top->data);
            last = top;
        } else {
            cur = top->rchild;
        }
    }
    stack_free(&s);

    return TREE_OK;
}

void
tree_destroy(tree_t T)
{
    if (T) {
        tree_destroy(T->lchild);
        tree_destroy(T->rchild);
        free(T);
    }
}
