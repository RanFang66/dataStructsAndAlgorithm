#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

stack_state_t stack_init(stack_t *sp, int16_t size)
{
    *sp = malloc(sizeof(struct STACK));
    if (*sp == NULL)
        return STACK_MALLOC_FAILED;

    size = (size > STACK_MAX_SIZE) ? STACK_MAX_SIZE : size;
    (*sp)->data = malloc(size * sizeof(selem_t));
    if ((*sp)->data == NULL)
        return STACK_MALLOC_FAILED;
    (*sp)->top = 0;
    (*sp)->size = size;

    return STACK_OK;
}

int16_t
stack_is_empty(stack_t s)
{
    return (s->top == 0);
}

int16_t
stack_is_full(stack_t s)
{
    return (s->top == s->size);
}

stack_state_t
stack_push(stack_t s, selem_t d)
{
    if (stack_is_full(s))
        return STACK_FULL;
    s->data[s->top++] = d;

    return STACK_OK;
}

stack_state_t
stack_pop(stack_t s, selem_t *d)
{
    if (stack_is_empty(s))
        return STACK_EMPTY;

    s->top--;
    *d = s->data[s->top];

    return STACK_OK;
}

stack_state_t
stack_get(stack_t s, selem_t *d)
{
    if (stack_is_empty(s))
        return STACK_EMPTY;

    *d = s->data[s->top-1];

    return STACK_OK;
}

int16_t
stack_usage_size(stack_t s)
{
    return s->top;
}

stack_state_t
stack_print(stack_t s, stack_state_t (*visit)(selem_t d))
{
    int i;
    for (i = 0; i < s->top; i++)
        if(!visit(s->data[i]))
            return STACK_ACCESS_FAILED;
    return STACK_OK;
}

void
stack_clear(stack_t s)
{
    s->top = 0;
}

void
stack_free(stack_t *sp)
{
    free((*sp)->data);
    free(*sp);
}
