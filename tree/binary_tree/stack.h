#ifndef _STACK_H_
#define _STACK_H_

#include "binary_tree.h"

typedef tree_t selem_t;
struct STACK {
    selem_t *data;
    int16_t top;
    int16_t size;
};
typedef struct STACK *my_stack_t;
#define stack_t my_stack_t

enum STACK_STATE {
    STACK_OK,
    STACK_EMPTY,
    STACK_FULL,
    STACK_MALLOC_FAILED,
    STACK_ACCESS_FAILED
};
typedef enum STACK_STATE stack_state_t;

#define     STACK_MAX_SIZE      1024

extern stack_state_t    stack_init(stack_t *sp, int16_t size);
extern stack_state_t    stack_push(stack_t s, selem_t d);
extern stack_state_t    stack_pop(stack_t s, selem_t *d);
extern stack_state_t    stack_get(stack_t s, selem_t *d);
extern int16_t          stack_is_empty(stack_t s);
extern int16_t          stack_is_full(stack_t s);
extern int16_t          stack_size(stack_t s);
extern int16_t          stack_usage_size(stack_t s);
extern stack_state_t    stack_traverse(stack_t s, stack_state_t (*visit)(selem_t d));
extern void             stack_clear(stack_t s);
extern void             stack_free(stack_t *sp);


#endif /* _STACK_H_ */
