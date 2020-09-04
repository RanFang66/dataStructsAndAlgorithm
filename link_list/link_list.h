#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_

#define unsigned short uint16_t
#define signed short int16_t

typedef int16_t elem_t;

enum LIST_RET {
    NO_ERR,
    MALLOC_FAILED,
    ELEM_NOT_FIND
};
typedef enum LIST_RET state_t;

struct NODE {
    elem_t data;
    struct NODE *next;
};
typedef struct NODE *list_t;
typedef struct NODE *pos_t;

extern state_t list_init(list_t *p);
extern state_t list_append(list_t l, elem_t d);
extern int16_t list_is_empty(list_t l);
extern int16_t list_is_last(list_t l, pos_t p);
extern pos_t list_find_elem(list_t l, elem_t d);
extern state_t list_del_elem(list_t l, elem_t d);
extern pos_t list_find_prev(list_t l, elem_t d);
extern state_t list_insert(list_t l, elem_t d, pos_t p);
extern void list_print(list_t l);
extern void list_clear(list_t l);
extern void list_free(list_t *lp);

#endif /* _LINK_LIST_H_ */
