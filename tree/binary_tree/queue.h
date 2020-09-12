#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "binary_tree.h"

typedef  tree_t  elem_t;

struct QUEUE {
    elem_t *data;
    int16_t front;
    int16_t rear;
    int16_t size;
};
typedef struct QUEUE *queue_t;

enum QUEUE_STATE {
    QUEUE_OK,
    QUEUE_MALLOC_FAILED,
    QUEUE_EMPTY,
    QUEUE_FULL
};
typedef enum QUEUE_STATE queue_state_t;

#define     QUEUE_MAX_SIZE      1024

extern queue_state_t    queue_init(queue_t *qp, int16_t size);
extern queue_state_t    queue_en(queue_t qp, elem_t d);
extern queue_state_t    queue_de(queue_t qp, elem_t *d);
extern int16_t          queue_is_empty(queue_t qp);
extern int16_t          queue_is_full(queue_t qp);
extern int16_t          queue_length(queue_t qp);
extern void             queue_traverse(queue_t qp, void (*visit)(elem_t));
extern void             queue_clear(queue_t qp);
extern void             queue_free(queue_t *qp);

#endif /* _QUEUE_H_ */
