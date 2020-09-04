#include <stdio.h>
#include <stdlib.h>
#include "link_list.h"

int main(void)
{
    list_t l;
    pos_t p;

    list_init(&l);
    for (int i = 0; i < 10; i++) {
        list_append(l, i);
    }
    printf("after append elements:\n");
    list_print(l);

    list_del_elem(l, 4);
    printf("delete one element:\n");
    list_print(l);

    p = list_find_elem(l, 6);
    list_insert(l, 20, p);
    printf("insert one element\n");
    list_print(l);

    p = list_find_elem(l, 9);
    if (list_is_last(l, p))
        printf("%d is the last element of list.\n", p->data);

    list_clear(l);
    if (list_is_empty(l))
        printf("now the list is empty.\n");

    list_free(&l);
    printf("now the list is free.\n");

    return 0;
}
