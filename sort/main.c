#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "common.h"

void print_list(list_t *lp);

int main(void)
{
    list_t *lp;

    lp = malloc(sizeof(list_t));
    lp->data = malloc(MAXLEN * sizeof(elem_t));
    lp->len = MAXLEN;

    srand(time(NULL));
    for (int i = 0; i < MAXLEN; i++) {
        lp->data[i] = rand() % (MAXLEN*2);
    }

    printf("0-- before sort:\n");
    print_list(lp);

    bubble_sort(lp);
    printf("1-- after bubble sort:\n");
    print_list(lp);

    select_sort(lp);
    printf("2-- after select sort:\n");
    print_list(lp);

    insert_sort(lp);
    printf("3-- after insert sort:\n");
    print_list(lp);

    shell_sort(lp);
    printf("4-- after shell sort:\n");
    print_list(lp);

    quick_sort(lp);
    printf("5-- after quick sort:\n");
    print_list(lp);

    quick_sort(lp);
    printf("6-- after merge sort:\n");
    print_list(lp);

    free(lp->data);
    free(lp);

    return 0;
}

void print_list(list_t *lp)
{
    for (uint16_t i = 0; i < lp->len; i++) {
        printf("%d\t", lp->data[i]);
    }
    printf("\n");
}
