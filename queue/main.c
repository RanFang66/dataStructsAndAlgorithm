#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define     QUEUE_SIZE      10

int main(int argc, char* argv[])
{
    queue_t q;
    elem_t  d;
    queue_state_t   ret;
    int16_t i;

    if (queue_init(&q, QUEUE_SIZE))
        exit(1);
    printf("Initialize queue ok, the size of queue is %d\n", q->size-1);

    for (i = 0; i < QUEUE_SIZE; i++)
        ret = queue_en(q, i+1);
    printf("After %d enqueue operation: \n", i);
    queue_print(q);

    for (i = 0; i < QUEUE_SIZE / 2; i++) {
        ret = queue_de(q, &d);
        printf("\tdeque %d: %d\n", i, d);
    }
    printf("After %d deque operation, the length of queue is %d\n", i, queue_length(q));
    queue_print(q);

    for (i = 0; i < QUEUE_SIZE; i++)
        ret = queue_en(q, i+1);
    if (ret == QUEUE_FULL)
        printf("Enqueue failed, because queue is full.\n");
    queue_print(q);

    queue_clear(q);
    if (queue_is_empty(q))
        printf("Now the queue is empty, the length of queue is %d.\n", queue_length(q));

    queue_free(&q);
    printf("Now the queue is destroyed.\n");

    return 0;

}
