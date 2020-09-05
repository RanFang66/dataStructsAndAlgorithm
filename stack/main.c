#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE 10

int main(int argc, char* argv[])
{
    stack_t s;
    stack_state_t ret;
    elem_t d;

    ret = stack_init(&s, STACK_SIZE);
    printf("Initialize a stack with size %d.\n", s->size);

    if (stack_is_empty(s))
        printf("Now the stack is empty.\n");

    for (int i = 0; i < 5; i++)
        ret = stack_push(s, i);
    stack_print(s);

    stack_get(s, &d);
    printf("Get the top element of stack: %d.\n", d);
    stack_print(s);

    for (int i = 0; i < 5; i++)
        ret = stack_pop(s);
    if (ret == STACK_EMPTY)
        printf("Pop stack failed, because stack is empty.\n");
    stack_print(s);

    for (int i = 0; i < 20; i++)
        ret = stack_push(s, i);
    if (ret == STACK_FULL)
        printf("Push stack failed, because stack is full.\n");
    stack_print(s);

    stack_clear(s);
    printf("Now stack is clear, the stack usage size is %d.\n", stack_usage_size(s));

    stack_free(&s);
    printf("Now stack is free.\n");

    return 0;
}
