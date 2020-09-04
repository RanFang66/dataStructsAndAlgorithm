#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

state_t list_init(list_t *lp)
{
    *lp = malloc(sizeof(struct NODE));
    if (*lp == NULL)
        return MALLOC_FAILED;

    (*lp)->next = NULL;
    (*lp)->data = 0;

    return NO_ERR;
}

state_t list_append(list_t l, elem_t d)
{
    pos_t p, tmp;

    tmp = malloc(sizeof(struct NODE));
    if (tmp == NULL)
        return MALLOC_FAILED;
    tmp->data = d;
    tmp->next = NULL;

    p = l;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;

    return NO_ERR;
}

int16_t list_is_empty(list_t l)
{
    return (l->next == NULL);
}

int16_t list_is_last(list_t l, pos_t p)
{
    return (p->next == NULL);
}

pos_t list_find_elem(list_t l, elem_t d)
{
    pos_t p;
    p = l->next;
    while ((p != NULL) && (p->data != d))
        p = p->next;
    return p;
}

pos_t list_find_prev(list_t l, elem_t d)
{
    pos_t p;
    p = l;
    while ((p->next != NULL) && (p->next->data != d))
        p = p->next;
    return p;
}

state_t list_del_elem(list_t l, elem_t d)
{
    pos_t p, tmp;

    p = list_find_prev(l, d);
    if (p == NULL)
        return ELEM_NOT_FIND;

    tmp = p->next;
    p->next = tmp->next;
    free(tmp);
    return NO_ERR;
}

state_t list_insert(list_t l, elem_t d, pos_t p)
{
    pos_t tmp;
    tmp = malloc(sizeof(struct NODE));
    if (tmp == NULL)
        return MALLOC_FAILED;

    tmp->data = d;
    tmp->next = p->next;
    p->next = tmp;

    return NO_ERR;
}

void list_print(list_t l)
{
    pos_t p = l->next;
    while (p != NULL) {
        printf("%d \t", p->data);
        p = p->next;
    }
    printf("\n");
}

void list_clear(list_t l)
{
    pos_t p;
    pos_t q;

    if (l->next == NULL)
        return;

    p = l->next;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    l->next = NULL;
}

void list_free(list_t *lp)
{
    list_clear(*lp);
    free(*lp);
}
