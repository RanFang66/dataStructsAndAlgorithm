#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

typedef int elem_t;
struct LIST {
    elem_t  *data;
    int     size;
    int     len;
};
typedef struct LIST *list_t;

enum LIST_STATUS {
    LIST_OK,
    LIST_EMPTY,
    LIST_FULL,
    LIST_MALLOC_FAILED,
    LIST_ACCESS_FAILED
};
typedef enum LIST_STATUS list_status_t;

#define LIST_VOID_VAL   0

extern list_status_t list_init(list_t *l, int size);
extern list_status_t list_get_elem(list_t l, int pos, elem_t *d);
extern list_status_t list_insert(list_t l, int pos, elem_t d);
extern list_status_t list_delete(list_t l, int pos);
extern list_status_t list_append(list_t l, elem_t d);
extern void list_clear(list_t l);
extern list_status_t list_traverse(list_t l, list_status_t (*visit)(elem_t d));
extern void list_free(list_t *l);

#endif
