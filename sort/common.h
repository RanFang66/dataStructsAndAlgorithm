#ifndef _COMMON_H_
#define _COMMON_H_

#define uint16_t    unsigned short
#define int16_t     signed short

typedef int16_t    elem_t;
typedef struct LIST{
    elem_t  *data;
    uint16_t  len;
}list_t;

/* MOCRO FUNCTION */
#define LGT(A, B)   ((A) > (B))
#define SWAP(A, B)  do { \
            elem_t _tmp_ = A; A = B; B = _tmp_; \
        } while(0);

#define TRUE        1
#define FALSE       0
#define MAXLEN      10

extern void bubble_sort(list_t *lp);
extern void select_sort(list_t *lp);
extern void insert_sort(list_t *lp);
extern void shell_sort(list_t *lp);
extern void quick_sort(list_t *lp);
extern void merge_sort(list_t *lp);

#endif /* _COMMON_H_ */
