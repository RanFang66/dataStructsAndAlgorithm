#include "common.h"

uint16_t partition(list_t *lp, int16_t l, int16_t r){
    elem_t pivot = lp->data[l];
    int16_t i = l;
    int16_t j = r;

    while (i < j) {
        while (i < j && LGT(lp->data[j], pivot))
            j--;
        if (i < j) {
            lp->data[i] = lp->data[j];
            i++;
        }

        while (i < j && LGT(pivot, lp->data[i]))
            i++;
        if (i < j) {
            lp->data[j] = lp->data[i];
            j--;
        }
    }
    lp->data[i] = pivot;
    return i;
}

void quick_sort_recur(list_t *lp, int16_t l, int16_t r) {
    int16_t pivot;
    if (l < r) {
        pivot = partition(lp, l, r);
        quick_sort_recur(lp, l, pivot-1);
        quick_sort_recur(lp, pivot+1, r);
    }
}

void quick_sort(list_t *lp) {
    quick_sort_recur(lp, 0, lp->len-1);
}
