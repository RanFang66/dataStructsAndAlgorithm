#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

list_status_t
list_init(list_t *l, int size)
{
    if ((*l = malloc(sizeof(struct LIST))) == NULL)
        return LIST_MALLOC_FAILED;
    if (((*l)->data = malloc(size * sizeof(elem_t))) == NULL)
        return LIST_MALLOC_FAILED;

    (*l)->size = size;
    (*l)->len = 0;

    return LIST_OK;
}

list_status_t
list_get_elem(list_t l, int pos, elem_t *d)
{
    if (pos >= l->len || pos < 0)
        return LIST_ACCESS_FAILED;

    *d = l->data[pos];
    return LIST_OK;
}

list_status_t
list_append(list_t l, elem_t d)
{
    if (l->len == l->size)
        return LIST_FULL;
    l->data[l->len++] = d;

    return LIST_OK;
}

list_status_t
list_insert(list_t l, int pos, elem_t d)
{
    if (pos > l->len || pos < 0 || l->size == l->len)
        return LIST_ACCESS_FAILED;

    for (int i = l->len; i > pos; i--)
        l->data[i] = l->data[i-1];

    l->data[pos] = d;
    l->len++;

    return LIST_OK;
}

list_status_t
list_delete(list_t l, int pos)
{
    if (pos >= l->len || pos < 0)
        return LIST_ACCESS_FAILED;
    if (l->len == 0)
        return LIST_EMPTY;

    for (int i = pos; i < l->len-1; i++)
        l->data[i] = l->data[i+1];

    l->len--;
    l->data[l->len] = LIST_VOID_VAL;

    return LIST_OK;
}

void
list_clear(list_t l)
{
    for (int i = 0; i < l->len; i++)
        l->data[i] = LIST_VOID_VAL;
    l->len = 0;
}

list_status_t
list_traverse(list_t l, list_status_t (*visit)(elem_t d))
{
    for (int i = 0; i < l->len; i++)
        if (visit(l->data[i]) != LIST_OK)
            return LIST_ACCESS_FAILED;
    return LIST_OK;
}

void
list_free(list_t *l)
{
    free((*l)->data);
    free(*l);
}

